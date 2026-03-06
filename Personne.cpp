#include "Personne.h"

Personne::Personne(string cin, string n, string p, Date d)
    : CIN(cin)
{
    nom = n;
    prenom = p;
    dateN = d;
}

Personne::~Personne()
{


}

void Personne::setNom(string n)
{ 
	nom = n; 
}
void Personne::setPrenom(string p)
{ 
	prenom = p; 
}
void Personne::setDate(Date d)
{ 
	dateN = d; 
}


string Personne::getCIN()
{ 
	return CIN; 
}

string Personne::getNom()
{ 
	return nom; 
}

string Personne::getPrenom()
{ 
	return prenom; 
}

Date Personne::getDate()
{ 
	return dateN; 
}


