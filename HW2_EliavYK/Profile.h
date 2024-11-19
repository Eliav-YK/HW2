#pragma once
#include <string>
#include "User.h"
#include "UserList.h"
#include "Page.h"
class Profile
{
private:
	User user;
	Page page;
	UserList* friendsList;
public:
	void init(User owner);
	void clear();
	User getOwner() const;
	void setStatus(const std::string new_status);
	void addPostToProfilePage(std::string post);
	void addFriend(User friend_to_add);
	std::string getPage() const;
	std::string getFriends() const;
	std::string getFriendsWithSameNameLength() const;
};

