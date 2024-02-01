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



GravityVectorIn3D::GravityVectorIn3D() 
{
    //this->ptrVectorOfDoubleIn3D = NULL;
}

GravityVectorIn3D::GravityVectorIn3D(double& valueOfX, double& valueOfY, double& valueOfZ)
{
    vector<vector<vector<double>>> vectorOfZ;
    vector<vector<double>> vectorOfY;
    vector<double> vectorOfX;

    vectorOfX.push_back(valueOfX);
    vectorOfX.push_back(valueOfY);
    vectorOfY.push_back(vectorOfX);
    vectorOfX.push_back(valueOfZ);
    vectorOfY.push_back(vectorOfX);
    vectorOfZ.push_back(vectorOfY);
    this->ptrVectorOfDoubleIn3D->push_back(vectorOfZ);
}

GravityVectorIn3D::GravityVectorIn3D(vector<vector<vector<vector<double>>>> doubleVectorIn3D)
{
    *(this->ptrVectorOfDoubleIn3D) = doubleVectorIn3D;
}

GravityVectorIn3D& GravityVectorIn3D::setValueOfX(double& valueOfX, int& elementNum)
{
    (*this->ptrVectorOfDoubleIn3D)[elementNum][0][0][0] = valueOfX;
    return *this;
}

GravityVectorIn3D& GravityVectorIn3D::setValueOfY(double& valueOfY, int& elementNum)
{
    (*this->ptrVectorOfDoubleIn3D)[elementNum][0][0][1] = valueOfY;
    return *this;
}

GravityVectorIn3D& GravityVectorIn3D::setValueOfZ(double& valueOfZ, int& elementNum)
{
    (*this->ptrVectorOfDoubleIn3D)[elementNum][0][1][0] = valueOfZ;
    return *this;
}

GravityVectorIn3D& GravityVectorIn3D::setGravityVector(vector<vector<vector<vector<double>>>> doubleVectorIn3D)
{
    *(this->ptrVectorOfDoubleIn3D) = doubleVectorIn3D;
    return *this;

}

double GravityVectorIn3D::getValueOfX(int& elementNum)
{
    return (*this->ptrVectorOfDoubleIn3D)[elementNum][0][0][0];
}

double GravityVectorIn3D::getValueOfY(int& elementNum)
{
    return (*this->ptrVectorOfDoubleIn3D)[elementNum][0][0][1];
}

double GravityVectorIn3D::getValueOfZ(int& elementNum)
{
    return (*this->ptrVectorOfDoubleIn3D)[elementNum][0][1][0];
}

void GravityVectorIn3D::addGravityVector(double& valueOfX, double& valueOfY, double& valueOfZ)
{
    if (this->ptrVectorOfDoubleIn3D == nullptr) 
    {
        // if ptrVectorOfDoubleIn3D is null, create a new vector and add the first gravity vector
        this->ptrVectorOfDoubleIn3D = new vector <vector<vector<vector<double>>>>;
        
        vector<vector<vector<double>>> temp1VectorOfZ;
        vector<vector<double>> temp1VectorOfY;
        vector<double> temp1VectorOfX;

        temp1VectorOfX.push_back(valueOfX);
        temp1VectorOfX.push_back(valueOfY);
        temp1VectorOfY.push_back(temp1VectorOfX);
        temp1VectorOfX.push_back(valueOfZ);
        temp1VectorOfY.push_back(temp1VectorOfX);
        temp1VectorOfZ.push_back(temp1VectorOfY);
        this->ptrVectorOfDoubleIn3D->push_back(temp1VectorOfZ);
    }
    else 
    {

        vector<vector<vector<double>>> temp2VectorOfZ;
        vector<vector<double>> temp2VectorOfY;
        vector<double> temp2VectorOfX;

        temp2VectorOfX.push_back(valueOfX);
        temp2VectorOfX.push_back(valueOfY);
        temp2VectorOfY.push_back(temp2VectorOfX);
        temp2VectorOfX.push_back(valueOfZ);
        temp2VectorOfY.push_back(temp2VectorOfX);
        temp2VectorOfZ.push_back(temp2VectorOfY);
        this->ptrVectorOfDoubleIn3D->push_back(temp2VectorOfZ);
    }
}

void GravityVectorIn3D::addGravityVector(vector<vector<vector<vector<double>>>> gravityVector)
{
    this->ptrVectorOfDoubleIn3D->push_back(*(gravityVector.data()));
}

vector<vector<vector<vector<double>>>> GravityVectorIn3D::getGravityVector()
{
    return *(this->ptrVectorOfDoubleIn3D);
}

vector<vector<vector<vector<double>>>> GravityVectorIn3D::getGravityVectorAtIndex(int index)
{
    return (this->ptrVectorOfDoubleIn3D)[index];
}

int GravityVectorIn3D::getSize()
{
    return static_cast<int>(ptrVectorOfDoubleIn3D->size());
}

GravityVectorIn3D& GravityVectorIn3D::deleteGravityVector(int& elementNum)
{
    this->ptrVectorOfDoubleIn3D->erase(this->ptrVectorOfDoubleIn3D->begin() + elementNum);
    return *this;
}

GravityVectorIn3D::~GravityVectorIn3D()
{
    delete this->ptrVectorOfDoubleIn3D;
}
