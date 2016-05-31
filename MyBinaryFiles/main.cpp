#include <io.h>
#include <fstream>
#include <iostream>
#include "Building.h"

using namespace std;

void InitFile(char*);
void DisplayFile(char*);
void AddToEndFile(char*);
void ChangeFile(char*);
void RemoveFromFile(char*);
void InitNumber(long&);
void InitNameFile(char*);
void SortingFile(char*);
void Menu();

int main()
{
	Menu();
	return 0;
}

void InitFile(char* fileName)
{
	ofstream streamOut;
	streamOut.open(fileName, ios::binary);
	if (!streamOut.is_open())
	{
		cout << "\nCan't open file to write!";
		cout << endl;
		system("pause");
		system("cls");
		return;
	}
	Building house;
	while (true)
	{
		cin >>house;
		cout << endl;
		streamOut.write((char*)&house, sizeof(Building));
		cout << " If do you want to continue, press 'y' :";
		char choice;
		cin >> choice;
		if (choice != 'y')break;
		system("cls");
	}
	streamOut.close();
}

void AddToEndFile(char* fileName)
{
	ofstream streamOut(fileName, ios::app | ios::binary);
	if (!streamOut.is_open())
	{
		cout << "Can't open file to write!";
		cout << endl;
		system("pause");
		system("cls");
		return;
	}
	Building house;
	while (true)
	{
		cin >> house;
		cout << endl;
		streamOut.write((char*)&house, sizeof(Building));
		cout << " If do you want to continue, press 'y' :";
		char choice;
		cin >> choice;
		if (choice != 'y')break;
		system("cls");
	}
	streamOut.close();
}

void ChangeFile(char* fileName)
{
	fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
	if (!streamInOut)
	{
		cout << "Can't open file to read and write!";
		cout << endl;
		system("pause");
		system("cls");
		return;
	}
	Building house;
	long Position;
	InitNumber(Position);
	streamInOut.seekp((Position - 1) * sizeof(Building), ios::beg);
	cin >> house;
	streamInOut.write((char*)&house, sizeof(Building));
	streamInOut.close();
}

void RemoveFromFile(char* fileName)
{
		fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
		if (!streamInOut.is_open())
		{
			cout << "Can't open file to read and write!";
			cout << endl;
			system("pause");
			system("cls");
			return;
		}
		streamInOut.seekp(0, ios::end);
		long N = streamInOut.tellp();
		Building house;
		long Position;
		InitNumber(Position);
		streamInOut.seekp(Position * sizeof(Building), ios::beg);
		while (streamInOut.read((char*)&house, sizeof(Building)))
		{
			streamInOut.seekp(-2 * sizeof(Building), ios::cur);
			streamInOut.write((char*)&house, sizeof(Building));
			streamInOut.seekp(sizeof(Building), ios::cur);
		}
		streamInOut.close();
		int DiskriptorFile = open(fileName, 2);
		chsize(DiskriptorFile, N - sizeof(Building));
		close(DiskriptorFile);//*
}

void SortingFile(char* fileName)
{


	bool flag = true;
	while (flag)
	{
		fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
		if (!streamInOut.is_open())
		{
			cout << "Can't open file to read and write!";
			cout << endl;
			system("pause");
			system("cls");
			return;
		}
		flag = false;
		Building Build1, Build2;
		int bufSize = sizeof(Building);
		streamInOut.read((char*)&Build1, bufSize);
		while (streamInOut.read((char*)&Build2, bufSize))
		{
			if (Build2.GetBuildTime() < Build1.GetBuildTime())
			{
				
				streamInOut.seekp(-2 * bufSize, ios::cur);
				streamInOut.write((char*)&Build2, bufSize);
				streamInOut.write((char*)&Build1, bufSize);
				flag = true;

			}
			streamInOut.seekp(-bufSize, ios::cur);
			streamInOut.read((char*)&Build1, bufSize);
		}
		streamInOut.close();
	}
}

void DisplayFile(char* fileName)
{
	ifstream streamIn(fileName, ios::binary);
	if (!streamIn.is_open())
	{
		cout << "Can't open file to read!";
		cout << endl;
		system("pause");
		system("cls");
		return;
	}
	Building house;
	while (streamIn.read((char*)&house, sizeof(Building)))
	{
		cout << house;
	}
	streamIn.close();
}

void InitNumber(long& n)
{
	cout << "Enter the number of record:" << endl;
	cin >> n;
	system("cls");
}

void InitNameFile(char* fileName)
{
	cout << "Enter the name of file: " << endl;
	cin.ignore();
	cin.getline(fileName, 256, '\n');
	system("cls");
}

void Menu()
{
	char filename[256];
	InitNameFile(filename);
	while (true)
	{
		cout << "1) Enter to the file" << endl;
		cout << "2) Display file" << endl;
		cout << "3) Add element to the end of file" << endl;
		cout << "4) Changing element in the file" << endl;
		cout << "5) Removing Element from file" << endl;
		cout << "6) Sorting by build time" << endl;
		cout << "7) Exit" << endl;
		int k;
		cin >> k;
		system("cls");
		if (k == 7)break;
		switch (k)
		{
		case 1:
			InitFile(filename);
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 2:
			DisplayFile(filename);
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 3:
			AddToEndFile(filename);
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 4:
			ChangeFile(filename);
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 5:
			RemoveFromFile(filename);
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 6:
			SortingFile(filename);
			cout << "Sort was completed" << endl;
			cout << endl;
			system("pause");
			system("cls");
			break;
		default:
			cout << "\nIncorrect input! Try again!";
			cout << endl;
			system("pause");
			system("cls");
		}
	}
}