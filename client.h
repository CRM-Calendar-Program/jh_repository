#ifndef CLIENT_H
#define CLIENT_H

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
	int type;	// ¸â¹ö½Ê Á¾·ù
public:
	Client(int id, std::string name, int gender, int age, std::string phone_number, int visit, int mileage, std::string service_history);
	~Client();

	virtual void ShowMemInfo() const = 0;
	virtual int getDisRate() = 0;

	void Save(int mileage);
	void Deducted(int cost);
	// void record_history(int t, int length);
	int GetID();
};

#endif