#include "Device.h"
/*
innitiating a device
input: id,type,os
output: none
*/
void Device::init(unsigned int id, DeviceType type, std::string os)
{
	this->id = id;
	this->deviceType = type;
	this->operationsSystem = os;
	this->active = true;
}
/*
returning the id
input:none
output: id
*/
unsigned int Device::getID() const
{
	return this->id;
}
/*
returning the device type
input:none
output: id
*/
DeviceType Device::getType() const
{
	return this->deviceType;
}
/*
returning the os
input:none
output: os
*/
std::string Device::getOS() const
{
	return this->operationsSystem;
}
/*
returning the state of the user
input:none
output: id
*/
bool Device::isActive() const
{
	return this->active;
}
/*
changing the state to active
input:none
output: none
*/
void Device::activate()
{
	this->active = true;
}
/*
changing the state to deactive
input:none
output: none
*/
void Device::deactivate()
{
	this->active = false;
}
