#include "Profile.h"
/*
initiating a profile
input: user
ouput:none
*/
void Profile::init(User owner)
{
	this->user = owner;
	this->page.init();
	this->friendsList = new UserList;
	this->friendsList->init();
}
/*
clearing the profile
input: None
output : none
*/
void Profile::clear()
{
	this->user.clear();
	this->page.clearPage();
	this->page.setStatus("");
	friendsList->clear();
}
/*
returns the user
input: None
output : user
*/
User Profile::getOwner() const
{
	return this->user;
}
/*
seting the status
input: status
output : none
*/
void Profile::setStatus(const std::string new_status)
{
	this->page.setStatus(new_status);
}
/*
adding a post
input: post
output : none
*/
void Profile::addPostToProfilePage(std::string post)
{
	this->page.addLineToPosts(post);
}
/*
adding a friend
input: friend to add
output : none
*/
void Profile::addFriend(User friend_to_add)
{
	this->friendsList->add(friend_to_add);
}
/*
returning the page
input: none
output : the page
*/
std::string Profile::getPage() const
{
	return "Status: " + this->page.getStatus() + "\n*******************\n*******************\n" + this->page.getPosts();
}
/*
returning the names of his friends
input: none
output : the name of his friends
*/
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
/*
returning the name of his friends that have the same length as his name
input: none
output : the name of his friends that have the same length as his name
*/
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
