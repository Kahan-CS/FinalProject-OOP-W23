#pragma once
#include "GravityVectorIn3D.h"

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

/// @file this file is for declaring the phone class

/// @brief This class is for the Phone that is the main data format for this project
///
/// The phone class contains the attributes and methods required to use througout the project for all other operation. It uses vectors and thus avoids using arrays
/// @author Kahan Desai
/// @date 14/04/2023
class Phone
{
	GravityVectorIn3D gravityVector;
	vector <int> orientation;

public:

	Phone();

	Phone(double& valueOfX, double& valueOfY, double& valueOfZ, int& orientation);

	GravityVectorIn3D getGravityVector();

	Phone& setGravityVector(double& valueOfX, double& valueOfY, double& valueOfZ);

	Phone& addGravityVector(double& valueOfX, double& valueOfY, double& valueOfZ);

	Phone& addGravityVector(GravityVectorIn3D gravityVector);

	Phone& setOrientation(int orientation);

	Phone& addOrientation(vector <int> orientation);


	Phone& addOrientation(int orientation);

	vector <int> getOrientation();

	friend ofstream& operator<<(ofstream& fout, Phone& p);
	friend ifstream& operator>>(ifstream& fin, Phone& p);
};

