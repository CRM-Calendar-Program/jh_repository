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

	int i, g, b, v, m;
	std::string n, p, s;
	// std::string line;
	int k = 0; int row = -1;
	while (file >> i >> n >> g >> b >> p >> v >> m >> s)
	{
		// std::stringstream ss(line);
		// std::string cell;

		if (k != 0)
		{
			clients.emplace_back(i, n, g, b, p, v, m, s);
			/*
			std::cout << "= 1 =" << std::endl;
			int col = 0;
			std::cout << "= 2 =" << std::endl;
			while (getline(ss, cell, ','))
			{
				std::cout << "= 3 =" << std::endl;
				if (col == id) {
					std::cout << "= 4 =" << std::endl;
					clients[row].PutIntData(id, stoi(cell));
					std::cout << "= 5 =" << std::endl;
				}
				else if (col == name) clients[row].PutStringData(name, cell);
				else if (col == gender) clients[row].PutIntData(gender, stoi(cell));
				else if (col == birthday) clients[row].PutIntData(birthday, stoi(cell));
				else if (col == phone_number) clients[row].PutStringData(phone_number, cell);
				else if (col == visit) clients[row].PutIntData(visit, stoi(cell));
				else if (col == mileage) clients[row].PutIntData(mileage, stoi(cell));
				else if (col == service_history) clients[row].PutStringData(service_history, cell);
			}
			*/
		}
		k++;
		row++;
		std::cout << row << std::endl;
	}
	next_pointer = row;
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

	for (const auto& Client : clients)
	{
		// file << client.toCSV() << "\n"
	}

	int row = 0;
}

int DataHandler::GetData(int index)
{
	return clients[index].GetIntData(birthday);
}