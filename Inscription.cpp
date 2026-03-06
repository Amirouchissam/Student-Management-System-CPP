#include "Inscription.h"
#include <iostream>

using namespace std;

Inscription::Inscription(Module* m)
{
    module = m;
}

Inscription::~Inscription()
{
	for(int i = 0; i < controles.size(); i++)
        delete controles[i];
}

void Inscription::ajouterControle(Controle* c)
{
    controles.push_back(c);
}

float Inscription::calculerMoyenneModule()
{
    float somme = 0;
    float total = 0;

    for(int i = 0; i < controles.size(); i++)
    {
        somme += controles[i]->getNote() * controles[i]->getPourcentage() / 100;
        total += controles[i]->getPourcentage();
    }

    if(total != 100)
    {
        cout << "Erreur: total pourcentage != 100\n";
        return 0;
    }

    return somme;
}

// on fait cette methode car module est private donc
Module* Inscription::getModule()
{
    return module;
}
