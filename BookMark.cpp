#include "BookMark.h"
using namespace std;

Bookmark::Bookmark()
{
}

Bookmark::~Bookmark()
{
}

void Bookmark::setName(string n)
{
	name = n;
}

void Bookmark::setURL(string u)
{
	URL = u;
}

void Bookmark::setTags(string s)
{
	string subS;
	int i = 0 , pos = 0;

	for (; i <= s.size(); i++)
	{
		if (s[i] == ';'|| i == s.size())
		{
			subS = s.substr(pos, i-pos);
			Tags.push_back(subS);
			pos = i+1;
		}
	}
}

void Bookmark::setComment(string c)
{
	comment = c;
}

string Bookmark::getName()
{
	return name;
}

string Bookmark::getURL()
{
	return URL;
}

vector<string> Bookmark::getTags()
{
	return Tags;
}

string Bookmark::getComment()
{
	return comment;
}

