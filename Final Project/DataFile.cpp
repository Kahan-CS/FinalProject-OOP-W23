#include "DataFile.h"

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

DataFile::DataFile()
{
	this->fileName = '\0';
	this->phoneSensorData = nullptr;
}

DataFile::DataFile(string fileName)
{
	this->fileName = fileName;
	this->phoneSensorData = nullptr;
}

void DataFile::scanFileName()
{
	cin >> this->fileName;
}

void DataFile::writeData()
{
	ofstream outputFile;

	outputFile.open(this->fileName);
	if (outputFile.is_open())
	{
		while (!outputFile.eof())
		{
			int i =0;
			outputFile << *(this->phoneSensorData);
			i++;
		}
	}
	else
	{
		cout << "cannot open file: " << this->fileName << endl;
	}

}

void DataFile::readUnknownData()
{
	ifstream inputFile;
	inputFile.open(this->fileName);
	if (inputFile.is_open())
	{
		while (!inputFile.eof())
		{
			int i = 0;
			double x, y, z;
			char comma;
			inputFile  >> x >> comma >> y >> comma >> z;
			int nullorientation = 0;
			this->phoneSensorData->setOrientation(nullorientation);
			this->phoneSensorData->setGravityVector(x,y,z);
			
			i++;
		}
	}
	else
	{
		cout << "cannot open file: " << this->fileName << endl;
	}

}

void DataFile::readData()
{
	ifstream inputFile;
	inputFile.open(this->fileName);
	if (inputFile.is_open())
	{
		while (!inputFile.eof())
		{
			int i = 0;
			inputFile >> *(this->phoneSensorData);
			i++;
		}
	}
	else
	{
		cout << "cannot open file: " << this->fileName << endl;
	}
}

Phone DataFile::getData()
{
	return *(this->phoneSensorData);
}

DataFile::~DataFile()
{
	delete phoneSensorData;
}
