#ifndef SYSTEME_H
#define SYSTEME_H

#include "Etudiant.h"
#include "Module.h"
#include <vector>

using namespace std;

class Systeme
{
public:
    Systeme();
    ~Systeme();

	// Le système 	
    void ajouterEtudiant();
    void ajouterModule();
    void inscrireEtudiant();
    void ajouterControle();
    void afficherTousEtudiants();
    void afficherTousModules();
    // Statistiques globales (moyennes par module, taux de réussite ) && ( Recherche, tri et filtrage) 
    void verifierSemestre(); // moyenne general  
    void rechercherEtAfficherEtudiant();
    void filtrerParDecision();
    void filtrerParFiliere();
    void moyenneGeneraleParModule();
    void classementGeneral();
    //  Sauvegarde et chargement des données
	void sauvegarderTout();
	void chargerTout();

private:
    vector<Etudiant*> etudiants;
    vector<Module*> modules;

    Etudiant* rechercherEtudiant(const string cne);
    Module* rechercherModule(const string code);
};

#endif
