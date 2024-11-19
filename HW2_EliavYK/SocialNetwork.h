#pragma once
#include "ProfileList.h"
#include "string"
class SocialNetwork
{
private:
	std::string networkName;
	ProfileList* listOfProfiles;
	int minimalAge;
public:
	void init(std::string networkName, int minAge);
	void clear();
	std::string getNetworkName() const;
	int getMinAge() const;
	bool addProfile(Profile profile_to_add);
	std::string getWindowsDevices() const;
};

