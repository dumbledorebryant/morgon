#include <array>
#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <string>
#include "client.h"
using boost::asio::ip::tcp;
int main(int argc, char* argv[])
{
	boost::asio::io_service io_service;
	tcp::resolver resolver(io_service);
	tcp::resolver::query query("192.168.1.86", "9876");
	tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
	tcp::socket socket(io_service);
	boost::asio::connect(socket, endpoint_iterator);
	boost::system::error_code error;

	std::string my_name = "Zheng Lv";
	boost::asio::write(socket, boost::asio::buffer(my_name), error);

	std::array<char, 256> input_buffer;
	std::size_t rsize = socket.read_some(
		boost::asio::buffer(input_buffer), error);
	std::cout << std::string(input_buffer.data(), input_buffer.data() + rsize) << std::endl;
	return 0;
}



void Client::getInfo() {
	cout << "input 'end' to quit!!!" << endl;
	cout << "input ur stock u wanna to operate: " << endl;

	info buyORsell;        cin >> buyORsell;     tag_54 = buyORsell;
	info request;          cin >> request;       tag_54 = buyORsell;
	info request;          cin >> request;       tag_35 = request;
	info idname;           cin >> idname;        tag_11 = idname;
	info price;            cin >> price;         tag_44 = price;
	info amount;           cin >> amount;        tag_38 = amount;
	info_table[54]->setTagPair("buyORsell", tag_54);
	info_table[35]->setTagPair("request", tag_35);
	info_table[11]->setTagPair("id", tag_11);
	info_table[44]->setTagPair("price", tag_44);
	info_table[38]->setTagPair("amount", tag_38);
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
*/