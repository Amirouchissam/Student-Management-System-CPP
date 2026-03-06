#include "Controle.h"

Controle::Controle(string t, float n, float p)
{
    type = t;
    note = n;
    pourcentage = p;
}

Controle::~Controle(){}

string Controle::getType()
{
    return type;
}

float Controle::getNote()
{
    return note;
}

float Controle::getPourcentage()
{
    return pourcentage;
}

void Controle::setNote(float n)
{
    if(n >= 0 && n <= 20)
        note = n;
}

void Controle::setPourcentage(float p)
{
    if(p >= 0 && p <= 100)
        pourcentage = p;
}


