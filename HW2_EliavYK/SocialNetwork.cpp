#include "SocialNetwork.h"
/*
initiating a social network
input: name and minimal age
output: none
*/
void SocialNetwork::init(std::string networkName, int minAge)
{
	this->networkName = networkName;
	this->minimalAge = minAge;
	this->listOfProfiles = new ProfileList();
}
/*
clearing a social network
input: none
output: none
*/
void SocialNetwork::clear()
{
	this->networkName = "";
	this->minimalAge = NULL;
	this->listOfProfiles->clear();
}
/*
returning networks name
input: none
output: networks name
*/
std::string SocialNetwork::getNetworkName() const
{
	return this->networkName;
}
/*
returning minimalAge
input: none
output: minimalAge
*/
int SocialNetwork::getMinAge() const
{
	return this->minimalAge;
}
/*
adding a profile
input: profile to add
output: true or false wether the profile is under or above the min age
*/
bool SocialNetwork::addProfile(Profile profile_to_add)
{
	bool flag = false;
	if (profile_to_add.getOwner().getAge() >= this->minimalAge)
	{
		this->listOfProfiles->add(profile_to_add);
		flag = true;
	}
	return flag;
}
/*
returning the id of devices activated and in windows
input: none
output: the id of devices activated and in windows
*/
std::string SocialNetwork::getWindowsDevices() const
{
	std::string result = "";
	ProfileNode* pNode = this->listOfProfiles->get_first();
	User user;
	DeviceNode* dNode = NULL;
	while (pNode)
	{
		user = pNode->get_data().getOwner();
		dNode = user.getDevices().get_first();
		while (dNode)
		{
			if (dNode->get_data().isActive() && (dNode->get_data().getOS() == WINDOWS11 || dNode->get_data().getOS() == WINDOWS10 || dNode->get_data().getOS() == WINDOWS7))
			{
				result += "["+std::to_string(dNode->get_data().getID())+", "+dNode->get_data().getOS() + "], ";
			}
			dNode = dNode->get_next(); 
		}
		pNode = pNode->get_next();
	}
	result.pop_back();
	result.pop_back();
	return result;
}