#include "Address.h"
#include "Project.h"
#include "Employee.h"

Project::Project(char* namee, int budget, int duration)
{
	int x = strlen(namee);
	this->name = new char[x + 1];
	for (int i = 0; i < x; i++)
		this->name[i] = namee[i];
	this->name[x] = NULL;

	this->budget = budget;
	this->duration = duration;
}


Project::Project(const Project& other)
{
	int x = strlen(other.name);
	this->name = new char[x + 1];
	for (int i = 0; i < x; i++)
		this->name[i] = other.name[i];
	this->name[x] = NULL;

	this->budget = other.budget;
	this->duration = other.duration;
}

ostream& operator<<(ostream& out, const Project& other)
{
	out << "Name of project is: " << other.name << endl;
	out << "Budget of project is: " << other.budget << endl;
	out << "Duration of project is: " << other.duration << endl;
	return out;
}

const Project & Project::operator=(const Project& other)
{
	delete[] this->name;
	int x = strlen(other.name);
	this->name = new char[x + 1];
	for (int i = 0; i < x; i++)
		this->name[i] = other.name[i];
	this->name[x] = NULL;
	this->budget = budget;
	this->duration = duration;

	return *this;
}

void Project::setBudget(int x)
{
	this->budget = x;
}


Project::~Project()
{
	delete[] name;
	name = nullptr;
}