#include "data_handler.h"

DataHandler::DataHandler() {}

DataHandler::~DataHandler() {}

void DataHandler::ReadCSV(std::string filename)
{
	std::ifstream file(filename);
	if (!file.is_open())
	{
		std::cerr << "Unable to open file" << std::endl;
		return;
	}

	std::string line;
	int row = 0;
	while (getline(file, line))
	{
		std::stringstream ss(line);
		std::string cell;

		if (row != 0)
		{
			int col = 0;
			while (getline(ss, cell, ','))
			{

			}
		}

		row++;
	}
}

void DataHandler::WriteCSV(std::string filename)
{

}