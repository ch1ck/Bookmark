#include "BookmarkMenu.h"

void BookmarkMenu::displayMenu()
{
	int Choice = 0;
	while (Choice != 4)
	{
		cout << "1 - Add a new bookmark\n"
			<< "2 - Print all bookmarks\n"
			<< "3 - Search bookmarks by tag\n"
			<< "4 - exit" << endl;
		Choice = enterChoice(1, 4);
		switch (Choice)
		{
		case 1:
			addBookmark();
			break;
		case 2:
			printAllBookmarks();
			break;
		case 3:
			searchBookmark();
			break;
		case 4:
			exit(1);
			break;
		default:
			break;
		}
		if (Choice == 2 || Choice == 3)
		{
			int bmCho,opCho;
			cout << "which bookmark do you want to choose?(-1 - Go back to main menu)\n";
			cin >> bmCho;
			if (bmCho == -1)
				continue;
			cout << "What kind operation do you want to do?\n"
				<< "1 - delete\n"
				<< "2 - modify\n"
				<< "3 - open\n"
				<< "4 - exit\n";

			opCho = enterChoice(1, 4);
			switch (opCho)
			{
			case 1:
				deleteBookmark(bmCho);
				break;
			case 2:
				modifyBookmark(bmCho);
				break;
			case 3:
				openURL(bmCho);
				break;
			case 4:
				exit(1);
				break;
			default:
				break;
			}
			

		}
	}
}

int BookmarkMenu::enterChoice(int min,int max)
{
	int Choice;

	do
	{
		cin >> Choice;
	} while (Choice < min || Choice > max);

	return Choice;
}

void BookmarkMenu::addBookmark()
{
	Bookmark tempBm;
	string name, url, tags, comment;
	cout << "input name: " << endl;
	cin >> name;
	cout << "input url: " << endl;
	cin >> url;
	cout << "input tags(separate by ';'): " << endl;
	cin >> tags;
	cout << "input comment: " << endl;
	cin >> comment;

	tempBm.setName(name);
	tempBm.setURL(url);
	tempBm.setTags(tags);
	tempBm.setComment(comment);

	bookMarks.push_back(tempBm);
}

void BookmarkMenu::print(unsigned int n)
{
	cout << n << " - ";
	cout << "name: " << bookMarks[n].getName() << endl;
	cout << "URL: " << bookMarks[n].getURL() << endl;
	for (unsigned int i = 0; i < bookMarks[n].getTags().size(); i++)
	{
		if (i < bookMarks[n].getTags().size() - 1)
			cout << bookMarks[n].getTags()[i] << ";";
		else if (i == bookMarks[n].getTags().size() - 1)
			cout << bookMarks[n].getTags()[i];
	}
	cout << endl;
	cout << "comment: " << bookMarks[n].getComment() << endl << endl;
}

void BookmarkMenu::printAllBookmarks()
{
	for (unsigned int i = 0; i < bookMarks.size(); i++)
	{
		print(i);
	}
}

void BookmarkMenu::deleteBookmark(unsigned int n)
{
	bookMarks.erase(bookMarks.begin() + n);
}

void BookmarkMenu::modifyBookmark(unsigned int n)
{
	string name, url, tags, comment;
	cout << "input name: " << endl;
	cin >> name;
	cout << "input url: " << endl;
	cin >> url;
	cout << "input tags(separate by ';'): " << endl;
	cin >> tags;
	cout << "input comment: " << endl;
	cin >> comment;

	bookMarks[n].setName(name);
	bookMarks[n].setURL(url);
	bookMarks[n].setTags(tags);
	bookMarks[n].setComment(comment);
}

void BookmarkMenu::searchBookmark()
{
	string tag;
	cout << "input a tag to search your bookmarks: \n";
	cin >> tag;
	for (unsigned int i = 0; i < bookMarks.size(); i++)
	{
		for (unsigned int j = 0; j < bookMarks[i].getTags().size(); j++)
		{
			if (bookMarks[i].getTags()[j] == tag)
			{
				print(i);
			}
		}
	}
}

void BookmarkMenu::openURL(unsigned int n)
{
	const std::string cmd("start chrome ");
	string url = bookMarks[n].getURL();
	cout << "Open Bookmark: " << cmd + "\"" + url + "\"" << endl;
	system((cmd + "\"" + url + "\"").c_str());
}
