#include "Etudiant.h"

Etudiant::Etudiant(string cin, string nom, string prenom, Date d, string cne,string f)
    : Personne(cin, nom, prenom, d), CNE(cne)
{
	filiere = f;
}

Etudiant::~Etudiant()
{
    for(int i = 0; i < inscriptions.size(); i++)
        delete inscriptions[i];
}

string Etudiant::getCNE()
{
    return CNE;
}

void Etudiant::inscrireModule(Module* m)
{
    inscriptions.push_back(new Inscription(m));
}

float Etudiant::calculerMoyenneGenerale()
{
    float somme = 0;
    float totalCoef = 0;

    for(int i = 0; i < inscriptions.size(); i++)
    {
        float moyModule = inscriptions[i]->calculerMoyenneModule();
        float coef = inscriptions[i]->getModule()->getCoef();

        somme += moyModule * coef;
        totalCoef += coef;
    }

    if(totalCoef == 0)
        return 0;

    return somme / totalCoef;
}

void Etudiant::afficherDecision()
{
    float moy = calculerMoyenneGenerale();

    if(moy >= 10)
        cout << "Admis" << endl;
    else
        cout << "Ajourné" << endl;
}


void Etudiant::ajouterControle(string codeModule, Controle* c)
{
    for(int i = 0; i < inscriptions.size(); i++)
    {
        if(inscriptions[i]->getModule()->getCode() == codeModule)
        {
            inscriptions[i]->ajouterControle(c);
            return;
        }
    }

    cout << "Module non trouve pour cet etudiant.\n";
}


bool Etudiant::semestreValide()
{
    if(calculerMoyenneGenerale() >= 10)
        return true;
    else
        return false;
}


string Etudiant::getFiliere() 
{
    return filiere;
}


void Etudiant::setFiliere(string f)
{
    filiere = f;
}

// on a utiliser cette fonction pour chercher code dans la procedure moyenneGeneraleParModule()
float Etudiant::moyenneModule(const string codeModule)
{
    for(int i = 0; i < inscriptions.size(); i++)
    {
        if(inscriptions[i]->getModule()->getCode() == codeModule)
            return inscriptions[i]->calculerMoyenneModule();
    }

    return -1;
}

//on a fait cette fonction  pour save car class Inscription et private donc pas acces...

vector<Inscription*> Etudiant::getInscriptions()
{
    return inscriptions;
}



