#include"building.h"

Building::Building(char Adress[], char Type[], int stages, int flats, int BuildTime)
{
	struct tm *a;
	time_t buff = time(NULL);
	a = localtime(&buff);
	int year = a->tm_year;
	year += 1900;
	try
	{
		this->stages = stages;
		this->flats = flats;
		this->BuildTime = BuildTime;
		RemainingTime = 25 - (year - BuildTime);
		if (stages <= 0) throw 1;
		if (flats <= 0) throw 2;
		if (BuildTime <= 1970) throw 3;
		if (BuildTime > year)throw 4;
	}
	catch (int i)
	{
		if (i == 1 || i == 2)std::cout << "Error " << i << " member must be positive" << std::endl;
		if (i == 3) std::cout << "Error " << i << " year must be greater then 1970" << std::endl;
		if (i == 4) std::cout << "Error " << i << " invalid year" << std::endl;
		this->stages = 1;
		this->flats = 1;
		this->BuildTime = 1972;
		this->RemainingTime = 1;
	}
	strcpy(adress, Adress);
	strcpy(type, Type);
}


std::istream& operator>> (std::istream& in, Building& v)
{
	struct tm *a;
	time_t buff = time(NULL);
	a = localtime(&buff);
	int year = a->tm_year;
	year += 1900;
	try
	{
		std::cout << "Enter adress: ";
		in >> (v.adress);
		std::cout << std::endl;
		std::cout << "Enter type: ";
		in >> v.type;
		std::cout << std::endl;
		std::cout << "Enter number of steges: ";
		in >> v.stages;
		std::cout << std::endl;
		std::cout << "Enter number of flats: ";
		in >> v.flats;
		std::cout << std::endl;
		std::cout << "Enter year when this building was built ";
		in >> v.BuildTime;
		std::cout << std::endl;
		v.RemainingTime = 25 - (year - v.BuildTime);
		if (v.stages <= 0) throw 1;
		if (v.flats <= 0) throw 2;
		if (v.BuildTime <= 1970) throw 3;
		if (v.BuildTime > year)throw 4;
	}
	catch (int i)
	{
		if (i == 1 || i == 2)std::cout << "Error " << i << " member must be positive" << std::endl;
		if (i == 3) std::cout << "Error " << i << " year must be greater then 1970" << std::endl;
		if (i == 4) std::cout << "Error " << i << " invalid year" << std::endl;
		v.stages = 1;
		v.flats = 1;
		v.BuildTime = 1972;
		v.RemainingTime = 1;
	}
	return in;
}


std::ostream& operator<<(std::ostream& out, Building v)
{
	out << "Adress: " << v.adress << "\n";
	out << "Type: " << v.type << "\n";
	out << "Stages: " << v.stages << "\n";
	out << "Flats: " << v.flats << "\n";
	out << "BuildTime: " << v.BuildTime << "\n";
	if (v.RemainingTime < 0) out << " Time is out" << "\n";
	else out << "Remaining Time: " << v.RemainingTime << "\n";
	return out;
}

Building::Building()
{
	struct tm *a;
	time_t buff = time(NULL);
	a = localtime(&buff);
	int year = a->tm_year;
	year += 1900;
	this->stages = stages;
	this->flats = flats;
	this->BuildTime = BuildTime;
	this->RemainingTime = year - BuildTime;
}


void Building::operator=(Building v)
{
	strcpy(adress, v.adress);
	strcpy(type, v.type);
	flats = v.flats;
	stages = v.stages;
	BuildTime = v.BuildTime;
	RemainingTime = v.RemainingTime;
}

char* Building::GetAdress()
{
	return adress;
}

char* Building::GetType()
{
	return type;
}

int Building::GetStages()
{
	return stages;
}

int Building::GetFlats()
{
	return flats;
}

int Building::GetBuildTime()
{
	return BuildTime;
}



int Building::GetRemainingTime()
{
	return RemainingTime;
}




