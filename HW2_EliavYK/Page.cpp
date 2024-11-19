#include "Page.h"
/*
initiating
input: None
output : none
*/
void Page::init()
{
	this->status = "";
	this->posts = "";
}
/*
returns the posts
input: None
output : posts
*/
std::string Page::getPosts() const
{
	return this->posts;
}
/*
returns the status
input: None
output : status
*/
std::string Page::getStatus() const
{
	return this->status;
}
/*
reset the page
input: None
output : none
*/
void Page::clearPage()
{
	this->posts = "";
}
/*
sets the status
input: status
output : none
*/
void Page::setStatus(std::string status)
{
	this->status = status;
}
/*
adding a line to post
input: new line to posts
output : none
*/
void Page::addLineToPosts(std::string new_line)
{
	this->posts += (new_line + "\n");
}
