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
	int k = 0; int row = -1;
	while (getline(file, line))
	{
		std::stringstream ss(line);
		std::string cell;

		if (k != 0)
		{
			int col = 0;
			while (getline(ss, cell, ','))
			{
				if (col == id) client[row].PutIntData(id, stoi(cell));
				else if (col == name) client[row].PutStringData(name, cell);
				else if (col == gender) client[row].PutIntData(gender, stoi(cell));
				else if (col == age) client[row].PutIntData(age, stoi(cell));
				else if (col == phone_number) client[row].PutStringData(phone_number, cell);
				else if (col == visit) client[row].PutIntData(visit, stoi(cell));
				else if (col == mileage) client[row].PutIntData(mileage, stoi(cell));
				else if (col == service_history) client[row].PutStringData(service_history, cell);
			}
		}
		k++;
		row++;
	}
}

void DataHandler::WriteCSV(std::string filename)
{
	std::ofstream file(filename);
	if (!file.is_open())
	{
		std::cerr << "Error: Unable to open file " << filename << std::endl;
		return;
	}

	file << "No.,이름,성별,나이,전화번호,방문횟수,마일리지,서비스 기록" << std::endl;

	for (const auto& Client : client)
	{
		file << client.toCSV() << "\n"
	}

	int row = 0;
}