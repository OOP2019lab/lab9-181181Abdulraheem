#include "Address.h"
#include "Project.h"
#include "Employee.h"




Address::Address(char* houseNumber, char* StreetName, char * City,char* County)
{
	int x;
	x = strlen(houseNumber);
	this->house_Number = new char[x + 1];
	for (int i = 0 ; i < x ;i++)
		this->house_Number[i] = houseNumber[i];
	this->house_Number[x] = NULL;

	x = strlen(StreetName);
	this->street_Name = new char[x + 1];
	for (int i = 0 ; i < x ;i++)
		this->street_Name[i] = StreetName[i];
	this->street_Name[x] = NULL;

	x = strlen(City);
	this->city = new char[x + 1];
	for (int i = 0 ; i <= x ;i++)
		this->city[i] = City[i];
	this->city[x] = NULL;

	x = strlen(County);
	this->county = new char[x + 1];
	for (int i = 0 ; i <= x ;i++)
		this->county[i] = County[i];
	this->county[x] = NULL;
}

Address::Address(const Address& other)
{
	int x;
	x = strlen(other.house_Number);
	this->house_Number = new char[x + 1];
	for (int i = 0 ; i < x ; i++)
		this->house_Number[i] = other.house_Number[i];
	this->house_Number[x] = NULL;

	x = strlen(other.street_Name);
	this->street_Name = new char[x + 1];
	for (int i = 0 ; i < x ; i++)
		this->street_Name[i] = other.street_Name[i];
	this->street_Name[x] = NULL;

	x = strlen(other.city);
	this->city = new char[x + 1];
	for (int i = 0 ; i < x ; i++)
		this->city[i] = other.city[i];
	this->city[x] = NULL;

	x = strlen(other.county);
	this->county = new char[x + 1];
	for (int i = 0 ; i < x ; i++)
		this->county[i] = other.county[i];
	this->county[x] = NULL;
}

ostream& operator<<(ostream& osObject, const Address& other)
{
	osObject << "The house number is: "<<other.house_Number << endl;
	osObject << "The street number is: "<<other.street_Name << endl;
	osObject  << "The city name is: "<<other.city << endl;
	osObject << "The county name is: "<<other.county << endl;

	return osObject;

}

const Address& Address::operator = (const Address& other)
{

	if (this != &other)
	{
		int x;
		delete [] this->house_Number;
		x = strlen(other.house_Number);
		this->house_Number = new char[x + 1];
		for (int i = 0; i < x; i++)
			this->house_Number[i] = other.house_Number[i];
		this->house_Number[x] = NULL;

		delete[] this->street_Name;
		x = strlen(other.street_Name);
		this->street_Name = new char[x + 1];
		for (int i = 0; i < x; i++)
			this->street_Name[i] = other.street_Name[i];
		this->street_Name[x] = NULL;

		delete[] this->city;
		x = strlen(other.city);
		this->city = new char[x + 1];
		for (int i = 0; i < x; i++)
			this->city[i] = other.city[i];
		this->city[x] = NULL;

		delete[] this->county;
		x = strlen(other.county);
		this->county = new char[x + 1];
		for (int i = 0; i < x; i++)
			this->county[i] = other.county[i];
		this->county[x] = NULL;
	}
	return *this;
}

Address::~Address()
{
	delete[] house_Number;
	house_Number = nullptr;
	delete[]this->street_Name;
	street_Name = nullptr;
	delete[] city;
	city = nullptr;
	delete[] county;
	county = nullptr;
}