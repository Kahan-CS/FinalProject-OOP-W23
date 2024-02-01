#include "NNClassifier.h"

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


double NNClassifier::getDistance(GravityVectorIn3D v1, GravityVectorIn3D v2)
{
    double sumOfX = 0.0;
    double sumOfY = 0.0;
    double sumOfZ = 0.0;

    for (int i = 0; i < v1.getSize(); i++)
    {
        sumOfX += pow(v1.getValueOfX(i) - v2.getValueOfX(i), 2);
        sumOfY += pow(v1.getValueOfY(i) - v2.getValueOfY(i), 2);
        sumOfZ += pow(v1.getValueOfZ(i) - v2.getValueOfZ(i), 2);
    }

    double distance = sqrt(sumOfX + sumOfY + sumOfZ);
    return distance;
}

void NNClassifier::train(DataFile& fileName)
{
    fileName.readData();
    dataStored.addGravityVector(fileName.getData().getGravityVector());
    dataStored.addOrientation(fileName.getData().getOrientation());
}

void NNClassifier::predict(DataFile& unknownFile, DataFile& answerFile)
{
    unknownFile.readUnknownData();
    for (int i = 0; i < unknownFile.getData().getGravityVector().getSize(); i++)
    {
        int nearestIndex = nearestNeighbour(unknownFile.getData().getGravityVector().getGravityVectorAtIndex(i));
        answerFile.getData().addOrientation(dataStored.getOrientation().at(nearestIndex));
    }
    answerFile.writeData();
}

void NNClassifier::predict(GravityVectorIn3D v1)
{
    int orientation = dataStored.getOrientation().at(nearestNeighbour(v1));

    cout << "The prediction from machine says the orientation is: ";

    switch (orientation)
    {
    case 1:
    {
        cout << "Face up" << endl;
        break;
    }
    case 2:
    {
        cout << "Face down" << endl;
        break;
    }
    case 3:
    {
        cout << "Potrait" << endl;
        break;
    }
    case 4:
    {
        cout << "Potrait upside down" << endl;
        break;
    }
    case 5:
    {
        cout << "Landscape Left" << endl;
        break;
    }
    case 6:
    {
        cout << "Landscape Right" << endl;
        break;
    }
    default:
    {
        cout << "Unable to predict /o\\" << endl;
        exit(1);
    }
    }
}

int NNClassifier::nearestNeighbour(GravityVectorIn3D v1)
{
    int nearestIndex = 0;
    double minDistance = numeric_limits<double>::max();
    for (int i = 0; i < this->dataStored.getGravityVector().getSize(); i++)
    {

        GravityVectorIn3D v2 = this->dataStored.getGravityVector().getGravityVectorAtIndex(i);

        double distance = getDistance(v1, this->dataStored.getGravityVector().getGravityVectorAtIndex(i));

        if (distance < minDistance) 
        {
            minDistance = distance;
            nearestIndex = i;
        }
    }
    return nearestIndex;

}
