#include "KNNClassifier.h"
#include "NNClassifier.h"
#include "DummyClassifier.h"
#include<windows.h>

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

/// @file this file has the main function/client for the entire project, 
/// it basically implements all the classes and the user interaction as per the requirements
/// @author Kahan Desai
/// @date 14/04/2023

int main(void)
{
	int* userInputForMenu = nullptr;

	cout << "Please specify the classifier you would use for the machine" << endl << endl <<
		"1) NN Classifier" << endl << "2) KNN Classifer" << endl << "3) Dummy Classifer" << endl <<
		"Any other number will exit the program" << endl;

	userInputForMenu = new int;
	cin >> (*userInputForMenu);


	switch (*userInputForMenu)
	{
	case 1:
	{
		cout << "You are using NN Classifier now..." << endl;
		system("CLS");

		cout << endl << "LOADING NN CLASSIFIER..." << endl;
		Sleep(300);
		system("CLS");
		break;
	}

	case 2:
	{
		cout << "Sorry for the inconvinience! The KNN Classifier is under development /o\\ " << endl;
		return 1;
	}

	case 3:
	{
		cout << "Sorry for the inconvinience! The Dummy Classifier is under development /o\\ " << endl;
		return 1;
	}

	default:
	{
		cout << "Program exited..." << endl;
		return 1;
	}
	}

	delete userInputForMenu;

	userInputForMenu = new int;
	

	NNClassifier classifier;

	cout << "NNCLASSIFIER LOADED" << endl;
	cout << "Please pick the option you would like to perform" << endl << endl <<
		"1)" << "to train the machine" << endl <<
		"2)" << "test the machine" << endl <<
		"Any other number will exit the program" << endl;

	cin >> (*userInputForMenu);

	switch (*userInputForMenu)
	{
	case 1:
	{
		cout << "Training the machine..." << endl <<
			"Please enter the training file (along with its extension)" << endl;


		DataFile trainingFileByUser;

		trainingFileByUser.scanFileName();
		trainingFileByUser.readData();
		classifier.train(trainingFileByUser);

		cout << "The file provided was feeded to machine for training. \\o/" << endl <<
			"Ending the program";

		return 0;
	}
	case 2:
	{
		system("CLS");
		cout << "Getting machine ready for testing..." << endl;
		Sleep(300);
		system("CLS");

		break;
	}

	default:
	{
		cout << "Program exited..." << endl;
		return 1;
	}
	}

	delete userInputForMenu;

	userInputForMenu = new int;

	DataFile trainingData("trainingData.txt");
	trainingData.readData();
	classifier.train(trainingData);

	cout << "Let us test the machine" << endl << 
		"*****************************************" << endl <<
		"Pick the testing method:" << endl << endl << 
		"1) Using files" << endl << 
		"2) Manually testing (without files)" << endl << 
		"Any other number will exit the program" << endl;

	cin >> (*userInputForMenu);
	


	switch (*userInputForMenu)
	{
	case 1:
	{
		cout << "please enter the file required for testing (along with its extension)" << endl;

		DataFile testingFileByUser;
		DataFile resultFile("result.txt");

		testingFileByUser.scanFileName();

		classifier.predict(testingFileByUser, resultFile);

		cout << "Done testing! The result has been stored to result.txt file \\o/" << endl <<
			"Ending the program";
		return 0;
	}
	case 2:
	{
		double x, y, z;
		cout << "Entry for the gravity vector of the phone:" << endl << "*****************************" << endl 
			<< "Please enter the value of X:"<<endl;
		cin >> x;
		cout << endl << "Please enter the value of X:" << endl << endl;
		cin >> y;
		cout << endl << "Please enter the value of Y:" << endl << endl;
		cin >> z;
		cout << endl << "Please enter the value of Z:" << endl << endl;

		GravityVectorIn3D vectorByUser(x, y, z);

		classifier.predict(vectorByUser);

		return 0;
	}

	default:
	{
		cout << "Program exited..." << endl;
		return 1;
	}

	}


	return 0;
}