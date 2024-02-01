#pragma once
#include <iostream>
#include <cmath>
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

using namespace std;

/// @file this file is for the declaration fo Classifier abstract class


/// @brief Thi class is to be used as an interface for the derived classifiers
/// @author Kahan Desai
/// @date 14/04/2023
class Classifier
{
protected:

	/// @brief variable for the data that will be used by classifiers
 /// 
 /// This variable will be storing training data in form of Phone object.
 /// @author Group-11
 /// @date 18/02/2023
	Phone dataStored;

public:
	
	virtual void train(DataFile&) = 0;
	virtual void predict(DataFile&, DataFile&) = 0;
};