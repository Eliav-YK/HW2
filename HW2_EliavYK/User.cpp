#include "User.h"
void User::init(unsigned int id, std::string username, unsigned int age)
{
	this->id = id;
	this->username = username;
	this->age = age;
	this->deviceList = new DevicesList();
	this->deviceList->init();
}
void User::clear() 
{
	this->id = 0;
	this->username = "";
	this->age = 0;
	this->deviceList->clear();
}
unsigned int User::getID() const
{
	return this->id;
}
std::string User::getUserName() const
{
	return this->username;
}
unsigned int User::getAge() const
{
	return this->age;
}
DevicesList& User::getDevices() const
{
	DevicesList& list = *this->deviceList;
	return list;
}
void User::addDevice(Device newDevice)
{
	this->deviceList->add(newDevice);
}
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