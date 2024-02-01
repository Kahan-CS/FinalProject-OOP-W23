#pragma once

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

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class GravityVectorIn3D
{
	vector <vector<vector<vector<double>>>>* ptrVectorOfDoubleIn3D = new vector <vector<vector<vector<double>>>>;

public:

	GravityVectorIn3D();
	GravityVectorIn3D(double& valueOfX, double& valueOfY, double& valueOfZ);
	GravityVectorIn3D(vector <vector<vector<vector<double>>>> doubleVectorIn3D);


	GravityVectorIn3D& setValueOfX(double& valueOfX, int& elementNum);
	GravityVectorIn3D& setValueOfY(double& valueOfY, int& elementNum);
	GravityVectorIn3D& setValueOfZ(double& valueOfZ, int& elementNum);

	GravityVectorIn3D& setGravityVector(vector <vector<vector<vector<double>>>> doubleVectorIn3D);

	double getValueOfX(int& elementNum);
	double getValueOfY(int& elementNum);
	double getValueOfZ(int& elementNum);

	void addGravityVector(double& valueOfX, double& valueOfY, double& valueOfZ);

	void addGravityVector(vector<vector<vector<vector<double>>>>);

	vector<vector<vector<vector<double>>>> getGravityVector();

	vector<vector<vector<vector<double>>>> getGravityVectorAtIndex(int index);



	int getSize();

	GravityVectorIn3D& deleteGravityVector(int& elementNum);

	~GravityVectorIn3D();

};

