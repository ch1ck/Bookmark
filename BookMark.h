#pragma once
#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Bookmark
{
private:
	string name;
	string URL;
	vector<string> Tags;
	string comment;

public:
	Bookmark();
	~Bookmark();
	void setName(string);
	void setURL(string);
	void setTags(string);
	void setComment(string);

	string getName();
	string getURL();
	vector<string> getTags();
	string getComment();
	

};