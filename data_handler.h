#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "client.h"

class DataHandler
{
private:
	std::vector<Client> clients;
	int next_pointer;
public:
	DataHandler();
	~DataHandler();

	void ReadCSV(std::string filename);
	void WriteCSV(std::string filename);
	int GetData(int index);
};