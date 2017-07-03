#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
#include<map>
using namespace std;
typedef string info;
typedef string tagName;
typedef string FIX;
typedef char tag;

class tag_pair {
public:
	tagName name;
	info information;
	//assignment!!!
	void setTagPair(tagName Tname, info Tinformation);

	tagName getName() { return name; }

	info getInformation() { return information; }

}; 

FIX generateFIX(map<int, tag_pair*> info_table);
vector<info> parseFIX(FIX fixmessage);
void setOrders(vector<info> tags);

//some basic tools!
vector<info> split_CHAR(string str, char ch);
int TOnum(string str);





#pragma once
