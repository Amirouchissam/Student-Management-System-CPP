#include "Module.h"

Module::Module(string c, string n, float coef): code(c)
{
    nom = n;
    coefficient = coef;
}

Module::~Module(){}

string Module::getCode()
{
    return code;
}

string Module::getNom()
{
    return nom;
}

float Module::getCoef()
{
    return coefficient;
}

void Module::setNom(string n)
{
    nom = n;
}

void Module::setCoef(float c)
{
    coefficient = c;
}





