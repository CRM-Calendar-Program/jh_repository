#pragma once
#include <iostream>
#include <string>

class Client
{
private:
	int id;
	std::string name;
	int gender;
	int age;
	std::string phone_number;
	int visit;
	int mileage;
	std::string service_history;
protected:
	int type;	// ����� ����
public:
	Client(int id, std::string name, int gender, int age, std::string phone_number, int visit, int mileage, std::string service_history);
	~Client();

	void SaveMileage(int cost);
	int PayMileage(int cost);
	// void record_history(int t, int length);

	int GetID();
};