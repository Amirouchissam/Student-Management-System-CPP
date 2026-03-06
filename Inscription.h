#ifndef INSCRIPTION_H
#define INSCRIPTION_H

#include "Module.h"
#include "Controle.h"
#include <vector>

using namespace std;

class Inscription
{
public:
    Inscription(Module* m);
    ~Inscription();

    void ajouterControle(Controle*);
    float calculerMoyenneModule();
	Module* getModule();

private:
    Module* module;
    vector<Controle*> controles;
};

#endif
