#pragma once
#include "Classifier.h"

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

/// @file Header file for the Nearest neighbour classifier class

/// @brief Class for NNClassifier
/// 
/// This class inherits from the classifier, for the data Stored and the method to train and predict.
/// It performs the task related to finding the nearest neighbour of any vector and training for the same through files
/// @author Kahan Desai
/// @date 14/04/2023
class NNClassifier :
    public Classifier
{

    /// @brief Function to distance between two gravity vectors
/// 
/// This function uses a gravity vectors and finds the distance between them
/// @param v1 One of the gravity vectors, for comparision
/// @param v2 The other gravity vector for comparision
/// @return returns a double value for the distance found
/// @author Kahan Desai
/// @date 14/04/2023
    double getDistance(GravityVectorIn3D v1, GravityVectorIn3D v2);

public:
    
    
    /// @brief Function to train the classifier
/// 
/// This function basically adds the data input to the stored one, so that the data size increases, 
/// thus training the machine 
/// @param fileName for the data file it is going to train with
/// @author Kahan Desai
/// @date 14/04/2023
    void train(DataFile& fileName);
    
    
    /// @brief Function to find the predict the orientation
/// 
/// This function basically uses the nearest neighbour function to predict the orientation
/// @param unknown file to scan for the data given
///     @param answer file to store the data predicted
/// @author Kahan Desai
/// @date 14/04/2023
    void predict(DataFile& unknownFile, DataFile& answerFile);
    
/// @brief Function predicting just for one gravity vector
/// 
/// @param v1 the paramter v1 is for the gravity vector for which we are going to predict
/// @author Kahan Desai
/// @date 14/04/2023
    void predict(GravityVectorIn3D v1);

    /// @brief Function to find the nearest neighbour of a gravity vector
    /// 
    /// This function uses a gravity vector to compare it with the vector data stored in the classifier, 
    /// and then helps find the one with the nearest one's index
    /// @param v1 the paramter v1 is for the gravity vector needed for comparision
    /// @return nearestIndex is type of an integer that represents the index of the nearest neighbour found
    /// @author Kahan Desai
    /// @date 14/04/2023
    int nearestNeighbour(GravityVectorIn3D v1);

};
