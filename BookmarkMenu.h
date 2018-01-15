#pragma once
#include"BookMark.h"
#include<iostream>

using namespace std;

class BookmarkMenu
{
private:
	vector<Bookmark> bookMarks;
public:
	void displayMenu();
	int enterChoice(int,int);
	void addBookmark();
	void print(unsigned int);
	void printAllBookmarks();
	void deleteBookmark(unsigned int);
	void modifyBookmark(unsigned int);
	void searchBookmark();
	void openURL(unsigned int n);


};