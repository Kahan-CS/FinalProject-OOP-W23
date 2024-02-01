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

/// @file this file is yet to be implemented

/// @brief This class is yet to be implemented
/// @author Kahan Desai
/// @date 14/04/2023
class KNNClassifier :
    public Classifier
{
public:

    /// @brief Function is yet to be implemented
    /// 
/// @param fileName for the data file it is going to train with
/// @author Kahan Desai
/// @date 14/04/2023
    void train(DataFile& fileName);

    /// @brief Function is yet to be implemented
/// @author Kahan Desai
/// @date 14/04/2023
    void predict(DataFile& unknownFile, DataFile& answerFile);

};

