#include <iostream>
#include "client.h"

using namespace std;

Client::Client(int id, std::string name, int gender, int age, std::string phone_number, int visit, int mileage, std::string service_history)
{
	this->id = id; this->name = name; this->gender = gender; this->age = age;
	this->phone_number = phone_number; this->visit = visit; this->mileage = mileage;
	this->service_history = service_history;
}

Client::~Client() {}

void Client::SaveMileage(int cost)
{
	int temp = cost * 0.1;
	mileage += temp;
}

int Client::PayMileage(int cost)
{
	if (mileage < 100)
	{
		cout << "마일리지가 충분하지 않습니다" << endl;
		return cost;
	}
	else
	{
		int temp = mileage - cost;
		if (temp < 0)
		{
			mileage = 0;
			return cost - mileage;
		}
		else
		{
			mileage -= cost;
			return 0;
		}
	}
}

int Client::GetID()
{
	return id;
}