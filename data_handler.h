#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "client.h"

class DataHandler
{
private:
	std::vector<Client> client;
public:
	DataHandler();
	~DataHandler();

	void readCSV(std::string filename);
	void writeCSV(std::string filename);
};