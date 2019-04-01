#include "Address.h"
#include "Project.h"
#include "Employee.h"




Employee::Employee(char* namee, const Address& other)
{
	int x;
	x = strlen(namee);
	this->emp_name= new char[x + 1];
	for (int i = 0 ; i < x ;i++)
		this->emp_name[i] = namee[i];
	emp_name[x] = NULL;
	empadd = new Address(other);
	noprojects = 0;
	emp_projects = new Project*[2];
	for (int i = 0 ; i < 2 ;i++)
	emp_projects[i] = nullptr;
}

Employee::Employee(const Employee& other)
{
	int x = strlen(other.emp_name);
	this->emp_name = new char[x + 1];
	strcpy(this->emp_name, other.emp_name);

	this->empadd = other.empadd;
	for (int i = 0; i < 2; i++)
		this->emp_projects[i] = other.emp_projects[i];
}


ostream& operator << (ostream& out, const Employee& other)
{
	out << "Name of employee is: " << other.emp_name << endl;
	out << "Address is: " << *other.empadd << endl;
	out << "Total no. of projects: " << other.noprojects << endl;
	for (int i = 0; i < 2; i++)
	{
		if (other.emp_projects[i] != nullptr)
		{
			cout << "Project " << i + 1 << "is: ";
			out <<*other.emp_projects[i] << endl;
		}
	}
	return out;
}


const Employee& Employee::operator = (const Employee& other)
{
	if (this != &other)
	{
		int x = strlen(other.emp_name);
			delete[]emp_name;
		this->emp_name = new char[x + 1];
		strcpy(this->emp_name,other.emp_name);

		this->empadd = other.empadd;
		for (int i = 0; i < 2; i++)
			this->empadd[i] = other.empadd[i];
	}
	return *this;
}

void Employee::addProject(Project const* pro)
{
	bool f = true;
	for (int i = 0; i < 2 && (f); i++)
	{
		if (this->emp_projects[i] == nullptr)
		{
			emp_projects[noprojects] = new Project(pro[0]);
			f = false;
		}
	}
	noprojects++;
}

void Employee::removeProject(Project const* pro)
{
	for (int i = 0; i < 2; i++)
	{
		if (emp_projects[i] == pro)
		{
			emp_projects[i] = nullptr;
		}
	}
	noprojects--;
}

Employee::~Employee()
{
	delete this->empadd;
	if (this->emp_name != nullptr)
		delete[]this->emp_name;
	for (int i = 0; i < 2; i++)
	{
		delete this->emp_projects[i];
	}
	delete[] empadd;

}

