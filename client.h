#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>

class Client
{
private:
	std::string name;
	std::string gender;
	std::string id;
	int age;
	int phonenumber;
	int visit;

public:
	Client();
	void writeExcel(std::string& filename, Client* list, int size);
};

#endif