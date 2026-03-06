#ifndef CONTROLE_H
#define CONTROLE_H

#include <string>
using namespace std;

class Controle
{
public:
    Controle(string type, float note, float pourcentage);
    ~Controle();

    string getType();
    float getNote();
    float getPourcentage();

    void setNote(float);
    void setPourcentage(float);

private:
    string type;      
    float note;        
    float pourcentage; 
};

#endif
