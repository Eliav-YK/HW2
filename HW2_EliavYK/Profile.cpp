#include "Profile.h"
void Profile::init(User owner)
{
	this->user = owner;
	this->page.init();
	this->friendsList = new UserList;
	this->friendsList->init();
}
void Profile::clear()
{
	this->user.clear();
	this->page.clearPage();
	this->page.setStatus("");
	friendsList->clear();
}
User Profile::getOwner() const
{
	return this->user;
}
void Profile::setStatus(const std::string new_status)
{
	this->page.setStatus(new_status);
}
void Profile::addPostToProfilePage(std::string post)
{
	this->page.addLineToPosts(post);
}
void Profile::addFriend(User friend_to_add)
{
	this->friendsList->add(friend_to_add);
}
std::string Profile::getPage() const
{
	return "Status: " + this->page.getStatus() + "\n*******************\n*******************\n" + this->page.getPosts();
}
std::string Profile::getFriends() const
{
	std::string names = "";
	UserNode* node = this->friendsList->get_first();
	while (node)
	{
		names += node->get_data().getUserName() + ",";
		node = node->get_next();
	}
	if (names != "")
	{
		names.pop_back();
	}
	return names;
}

std::string Profile::getFriendsWithSameNameLength() const
{
	std::string names = "";
	UserNode* node = this->friendsList->get_first();
	int importentLetters = 0;
	int letters = 0;
	std::string str = this->user.getUserName();
	while (str != "")
	{
		importentLetters++;
		str.pop_back();
	}
	while (node)
	{
		letters = 0;
		str = node->get_data().getUserName();
		while (str != "")
		{
			letters++;
			str.pop_back();
		}
		if(importentLetters == letters)
		{
			names += node->get_data().getUserName() + ",";
		}
		node = node->get_next();
	}
	if (names != "")
	{
		names.pop_back();
	}
	return names;
}
