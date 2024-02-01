#pragma once
#include <iostream>
#include <string>
#include <fstream>

#include "Phone.h"

//***************************************
// Name: Kahan Desai
//***************************************
// Course: Object Oriented Programming	*
// PROG71020 - Winter'23				*
// Assignment - Final Project: Lab 8-9	*
//***************************************
//***************************************
//Prof: Akrem Ghazal					*
//***************************************

class DataFile
{
	string fileName; 
	Phone* phoneSensorData = new Phone;

public:
	DataFile();
	DataFile(string);

	void scanFileName();

	void writeData();

	void readUnknownData();

	void readData();

	Phone getData();

	~DataFile();

	friend ofstream& operator<<(ofstream& fout, Phone& p);
	friend ifstream& operator>>(ifstream& fin, Phone& p);
};

