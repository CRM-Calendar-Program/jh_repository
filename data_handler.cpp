#include "data_handler.h"

DataHandler::DataHandler(int size)
{
	clients = new Client[size];
}

DataHandler::~DataHandler() {
	delete[] clients;
}

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
				if (col == id) clients[row].PutIntData(id, stoi(cell));
				else if (col == name) clients[row].PutStringData(name, cell);
				else if (col == gender) clients[row].PutStringData(gender, cell);
				else if (col == birthday) clients[row].PutStringData(birthday, cell);
				else if (col == phone_number) clients[row].PutStringData(phone_number, cell);
				else if (col == visit) clients[row].PutIntData(visit, stoi(cell));
				else if (col == mileage) clients[row].PutIntData(mileage, stoi(cell));
				else if (col == service_history) clients[row].PutStringData(service_history, cell);
				col++;
			}
		}
		k++;
		row++;
	}
	next_pointer = row - 1;
}

void DataHandler::WriteCSV(std::string filename)
{
	std::ofstream file(filename);
	if (!file.is_open())
	{
		std::cerr << "Error: Unable to open file " << filename << std::endl;
		return;
	}

	file << "번호,이름,성별,생일,전화번호,방문횟수,마일리지,서비스 기록" << std::endl;

	for (int i = 0; i < next_pointer - 1; i++)
	{
		file << clients[i].toCSV() << "\n";
	}
	file.close();
}

void DataHandler::FindClient(std::string birthday)
{
	for (int i = 0; i < next_pointer; i++)
		if (clients[i].GetStringData(3) == birthday)
		{
			clients[i].PrintInfo();
			return;
		}
	std::cout << "Client with birthday " << birthday << " not found" << std::endl;
}

std::string DataHandler::GetData(int index)
{
	return clients[index].GetStringData(name);
}