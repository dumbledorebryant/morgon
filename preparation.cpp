#include"preparation.h"




void setOrders(vector<info> tags) {
	ofstream outfile("buy.txt");
	size_t num_tags = tags.size();
	info singleInfo;
	for (size_t i = 0; i < num_tags; ++i) {
		singleInfo = singleInfo + tags[i] + " ";
	}
	outfile << singleInfo;
	outfile.close();
}





int TOnum(string str) {
	stringstream ss;
	ss << str;
	int num;
	ss >> num;
	return num;
}





void tag_pair::setTagPair(tagName Tname, info Tinformation) {
	name = Tname;
	information = Tinformation;
	cout << " ur stock name is: " << name << endl
		<< "          information is: " << information << endl;

}





FIX generateFIX(map<int, tag_pair*> info_table) {
	FIX fixmessage;
	fixmessage = "8=FIX.4.2;"
		"54=" + info_table[54]->information + ";"
		"35=" + info_table[35]->information + ";"
		"11=" + info_table[11]->information + ";"
		"44=" + info_table[44]->information + ";"
		"38=" + info_table[38]->information + ";"
		+ "10=000;";
	return fixmessage;
}




vector<info> split_CHAR(string str, char ch) {
	vector<info> tags;
	char split_ch(ch);
	info singleTag;
	for (size_t i = 0; i < str.size(); ++i) {
		if (str[i] == split_ch) {
			tags.push_back(singleTag);
			singleTag = "";
		}
		else { singleTag += str[i]; }
	}
	return tags;
}





vector<info> parseFIX(FIX fixmessage) {
	vector<info> allContents;
	vector<info> tags;
	allContents = split_CHAR(fixmessage, ';');
	for (size_t j = 1; j < allContents.size() - 1; ++j) {
		tags.push_back(allContents[j]);
	}
	return tags;
}














