#include "User.h"
/*
initiating a user
input:id,username and age
output: none
*/
void User::init(unsigned int id, std::string username, unsigned int age)
{
	this->id = id;
	this->username = username;
	this->age = age;
	this->deviceList = new DevicesList();
	this->deviceList->init();
}
/*
clearing user data
input: None
output: None
*/
void User::clear() 
{
	this->id = 0;
	this->username = "";
	this->age = 0;
	this->deviceList->clear();
}
/*
returns the id
input: None
output : id
*/
unsigned int User::getID() const
{
	return this->id;
}
/*
returns username
input: None
output : username
*/
std::string User::getUserName() const
{
	return this->username;
}
/*
returns the age
input: None
output : age
*/
unsigned int User::getAge() const
{
	return this->age;
}
/*
returns refrence of devices
input: None
output : refrence of devices
*/
DevicesList& User::getDevices() const
{
	DevicesList& list = *this->deviceList;
	return list;
}
/*
adding a device
input: device
output : none
*/
void User::addDevice(Device newDevice)
{
	this->deviceList->add(newDevice);
}
/*
checking if all devices are on
input: none
output : true or false if all devices are on
*/
bool User::checkIfDevicesAreOn() const
{
	Device device;
	DeviceNode* node = NULL;
	bool flag = true;
	if (this->deviceList->get_first() != NULL)
	{
		node = this->deviceList->get_first();
		device = node->get_data();
		while (node != NULL)
		{
			if (device.isActive() == false)
			{
				flag = false;
			}
			node = node->get_next();
		}
	}
	return flag;
}