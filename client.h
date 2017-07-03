#include<iostream>
#include<string>
#include<vector>
#include<map>
#include"preparation.h"
using namespace std;
typedef string info;
typedef string tagName;
typedef string FIX;
typedef char tag;


class Client {

	friend FIX generateFIX(map<int, tag_pair*> info_table);

	friend vector<info> parseFIX(FIX fixmessage);

public:
	Client() = default;

	void getInfo();
	
private:
	info tag_54;//buy or sell
	info tag_35;//request or cancel
	info tag_11;/*order id 
	              represents the types,
		          whether it is private or belonging to government
				*/
	info tag_44;//price
	info tag_38;//amount
	info tag_40;//limit order which is not a range
	map<int, tag_pair*> info_table;//include tags
};





#pragma once
