#ifndef MODULE_H
#define MODULE_H

#include <string>
using namespace std;

class Module
{
public:
    Module(string code, string nom, float coef);
    ~Module();

    string getCode();
    string getNom();
    float getCoef();

    void setNom(string);
    void setCoef(float);

private:
    const string code;   
    string nom;
    float coefficient;
};

#endif


