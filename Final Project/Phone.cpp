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

ofstream& operator<<(ofstream& fout, Phone& p)
{
    for (int i = 0; i < p.gravityVector.getSize();i++)
    {
        fout << p.gravityVector.getValueOfX(i) << ',';
        fout << p.gravityVector.getValueOfY(i) << ',';
        fout << p.gravityVector.getValueOfZ(i) << ',';
        fout << p.orientation[i] << endl;
    }
    return fout;
}

ifstream& operator>>(ifstream& fin, Phone& p)
{
    double x, y, z;
    char comma;
    for (int i = 0; i < p.gravityVector.getSize(); i++)
    {
        fin >> x >> comma >> y >> comma >> z>>comma>>p.orientation[i];
        // fin >> p.gravityVector.getValueOfX(i) >> comma >> p.gravityVector.getValueOfY(i) >> comma >> p.gravityVector.getValueOfZ(i);
        x = p.gravityVector.getValueOfX(i);
        y = p.gravityVector.getValueOfY(i);
        z = p.gravityVector.getValueOfZ(i);
    }

    return fin;
}

Phone::Phone()
{
}

Phone::Phone(double& valueOfX, double& valueOfY, double& valueOfZ, int& orientation)
{
    this->gravityVector = { valueOfX, valueOfY, valueOfZ };
    this->orientation = { orientation };
}

GravityVectorIn3D Phone::getGravityVector()
{
    return this->gravityVector;
}

Phone& Phone::setGravityVector(double& valueOfX, double& valueOfY, double& valueOfZ)
{
    this->gravityVector = { valueOfX, valueOfY, valueOfZ };
    return *this;
}

Phone& Phone::addGravityVector(double& valueOfX, double& valueOfY, double& valueOfZ)
{
    this->gravityVector.addGravityVector(valueOfX, valueOfY, valueOfZ);
    return *this;
}

Phone& Phone::addGravityVector(GravityVectorIn3D gravityVector)
{
    this->gravityVector.addGravityVector(gravityVector.getGravityVector());
    return *this;
}

Phone& Phone::setOrientation(int orientation)
{
    this->orientation = { orientation };
    return *this;
}

Phone& Phone::addOrientation(vector<int> orientation)
{
    this->orientation.push_back(*(this->orientation).data());
    return *this;
}

Phone& Phone::addOrientation(int orientation)
{
    this->orientation.push_back(orientation);
    return *this;
}

vector<int> Phone::getOrientation()
{
    return this->orientation;
}
