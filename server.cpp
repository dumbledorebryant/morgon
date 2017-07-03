#include <array>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include "server.h"

using boost::asio::ip::tcp;

int main()
{
	boost::asio::io_service io_service;
	tcp::acceptor acc(io_service, tcp::endpoint(tcp::v6(), 9876));

	while (1) {
		boost::system::error_code ignored;

		tcp::socket socket(io_service);
		acc.accept(socket);

		std::array<char, 256> input_buffer;
		std::size_t input_size = socket.read_some(
			boost::asio::buffer(input_buffer),
			ignored);
		std::string visitor(input_buffer.data(),
			input_buffer.data() + input_size);

		std::cout << "Visited from " +
			socket.remote_endpoint().address().to_string() +
			" by visitor " << visitor << std::endl;

		std::string message = "Hello, you are " + visitor + "\n";
		boost::asio::write(socket, boost::asio::buffer(message), ignored);

		socket.shutdown(tcp::socket::shutdown_both, ignored);
		socket.close();
	}
	return 0;
}




//judge whether the user can buy the good!
vector<int> Server::match_order(vector<info> tags) {
/*feedback: first number:  0-for-fullfill and 1-for partialfill and -1 for not-matched
 *          second number:  供给量-需求量   >0: full fill
 *                                         <0: partial fill
 */
	vector<int> feedback;
	ifstream infile("sell.txt");
	string line;
	while (getline(infile, line)) {
		vector<info> singleInfo;
		singleInfo = split_CHAR(line, ' ');
		//judging id......
		if (tags[2] == singleInfo[2]) { 
			//Matched, now it's time to fill.
			if (tags[3] > singleInfo[3]) {       //price is ok for both sides! 
				if (tags[4] < singleInfo[4]) {   //All can be filled!
					feedback.push_back(0);
					feedback.push_back(TOnum(tags[4]) - TOnum(singleInfo[4]));
					return feedback;
				}
				else {// partial fill
					feedback.push_back(1);
					feedback.push_back(TOnum(tags[4]) - TOnum(singleInfo[4]));
					return feedback;
				}
			}
			else {
				feedback.push_back(-1);
				feedback.push_back(-1);
				return feedback;
			}
		}
	}
}





vector<info> Server::recipt(vector<int> feedback, FIX fixmessage) {
	vector<info> temp;
	temp = split_CHAR(fixmessage, ' ');
	if (feedback[0] == 0) {//fullfill
		temp[1] = "8";
		temp[6] = "2";
		return temp;
	}
	else if(feedback[0] == 1){
		temp[1] = "8";
		temp[6] = "1";
		return temp;
	}
	else if (feedback[0] == -1) {
		setOrders(temp);
		return temp;
	}
}

/*
info tag_54;//buy or sell
info tag_35;//request or cancel
info tag_11;//order id
              represents the types,
              whether it is private or belonging to government
info tag_44;//price
info tag_38;//amount
info tag_40;//limit order which is not a range
info tag_150//part or full fill
*/