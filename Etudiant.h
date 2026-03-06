#ifndef ETUDIANT_H
#define ETUDIANT_H

#include "Personne.h"
#include "Inscription.h"
#include <vector>
#include <iostream>

using namespace std;

class Etudiant : public Personne
{
public:
    Etudiant(string cin, string nom, string prenom, Date d, string cne,string f);
    ~Etudiant();

    string getCNE();

    void inscrireModule(Module* m); // Un étudiant peut être inscrit à un ou plusieurs modules.
    void ajouterControle(string codeModule, Controle* c);// Permet d'ajouter un contrôle (TP, CC ou EXAM) à un module spécifique.
    
    void afficherDecision();// pour afficher si etudiant valide ou non valide selon sa moyenne general
    bool semestreValide(); // on utuliser pour faire la comparaison dans class system si semestre valide ou non ...
    


	string getFiliere();
	void setFiliere(string f);
	
	vector<Inscription*> getInscriptions(); //  on fait cette methode pour retourner iscription dans procedeure savetout() parce que on declare vector private
	
	float moyenneModule(string codeModule);
	float calculerMoyenneGenerale();
private:
    const string CNE;
    string filiere;
    vector<Inscription*> inscriptions;  
};

#endif


