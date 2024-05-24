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

void Client::Save(int mileage)
{
	this->mileage += mileage;
}

void Client::Deducted(int cost)
{
	if (mileage > 0) mileage -= cost;
}

int Client::GetID()
{
	return id;
}