#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "client.h"

class DataHandler
{
private:
	Client* clients;
	int next_pointer;
public:
	DataHandler(int size);
	~DataHandler();

	void ReadCSV(std::string filename);
	void WriteCSV(std::string filename);
	Client& FindClient(std::string birthday);
	std::string GetData(int index);
};