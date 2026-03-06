#include "Systeme.h"
#include <iostream>
#include <fstream>
using namespace std;

// ================= CONSTRUCTEUR =================

Systeme::Systeme()
{

}

// ================= DESTRUCTEUR =================

Systeme::~Systeme()
{
    for(int i = 0; i < etudiants.size(); i++)
        delete etudiants[i];

    for(int i = 0; i < modules.size(); i++)
        delete modules[i];
}

// ================= RECHERCHE ETUDIANT =================

Etudiant* Systeme::rechercherEtudiant(string cne)
{
    for(int i = 0; i < etudiants.size(); i++)
    {
        if(etudiants[i]->getCNE() == cne)
            return etudiants[i];
    }
    return NULL;
}

// ================= RECHERCHE MODULE =================

Module* Systeme::rechercherModule(string code)
{
    for(int i = 0; i < modules.size(); i++)
    {
        if(modules[i]->getCode() == code)
            return modules[i];
    }
    return NULL;
}

// ================= AJOUTER MODULE =================

void Systeme::ajouterModule()
{
    string code, nom;
    float coef;

    cout << "Code module: ";
    cin >> code;
    
   if(rechercherModule(code))
	{
    	cout << "Module deja existant\n";
    	return ;
	}
	
    cout << "Nom module: ";
    cin >> nom;

    cout << "Coefficient: ";
    cin >> coef;

    modules.push_back(new Module(code, nom, coef));

    cout << "Module ajoute avec succes.\n";
    
    
}

// ================= AJOUTER ETUDIANT =================

void Systeme::ajouterEtudiant()
{
    string Cin, nom, prenom, cne , fil;
    Date d;

    cout << "CIN: ";
    cin >> Cin;

    cout << "Nom: ";
    cin >> nom;

    cout << "Prenom: ";
    cin >> prenom;

    // ===== Jour =====
    do{
        cout << "Jour : ";
        cin >> d.jour;
        
        if(d.jour < 1 || d.jour > 31)
            cout << "invalide jour entrer (1-31)\n";
            
    }while(d.jour < 1 || d.jour > 31);

    // ===== Mois =====
    do{
        cout << "Mois : ";
        cin >> d.mois;
        
        if(d.mois < 1 || d.mois > 12)
            cout << "invalide mois entrer (1-12)\n";
            
    }while(d.mois < 1 || d.mois > 12);

    // ===== Annee =====
    do{
        cout << "Annee : ";
        cin >> d.annee;
        
        if(d.annee < 1990 || d.annee > 2009)
            cout << "annee invalide entrer (1990-2009)\n";
			        
    }while(d.annee < 1990 || d.annee > 2009);

    cout << "CNE: ";
    cin >> cne;
    
    cout << "Filiere: ";
    cin >> fil;

    etudiants.push_back(new Etudiant(Cin, nom, prenom, d, cne, fil));

    cout << "Etudiant ajoute avec succes.\n";
}

// ================= INSCRIRE ETUDIANT =================

void Systeme::inscrireEtudiant()
{
    string cne, code;

    cout << "CNE etudiant: ";
    cin >> cne;

    cout << "Code module: ";
    cin >> code;

    Etudiant* e = rechercherEtudiant(cne);
    Module* m = rechercherModule(code);

    if(e != NULL && m != NULL)
    {
        e->inscrireModule(m);
        cout << "Inscription reussie.\n";
    }
    else
    {
        cout << "Etudiant ou module introuvable.\n";
    }
}

// ================= AJOUTER CONTROLE =================

void Systeme::ajouterControle()
{
    string cne, codeModule, type;
    float note, pourcentage;

    cout << "CNE etudiant: ";
    cin >> cne;

    cout << "Code module: ";
    cin >> codeModule;

    Etudiant* e = rechercherEtudiant(cne);

    if(e == NULL)
    {
        cout << "Etudiant introuvable.\n";
        return;
    }

   do{
    cout << "Type controle (TP/CC/EXAM): ";
    cin >> type;

    if(type != "TP" && type != "CC" && type != "EXAM")
        cout << "Type invalide ! Entrer uniquement TP ou CC ou EXAM\n";

	}while(type != "TP" && type != "CC" && type != "EXAM");

	do{
	cout << "Note (0-20): ";
    cin >> note;
    if(note < 0 || note > 20)
    	cout<<"note invalide : note doit etre entre (0-20) \n";
    	
	}while(note < 0 || note > 20);
    
	do{
	cout << "Pourcentage: ";
    cin >> pourcentage;
    
    if(pourcentage < 0 || pourcentage > 100)
    	cout<<"pourcentage invalide : doit etre entre (0-100)";
	
	}while(pourcentage < 0 || pourcentage > 100);
    
    Controle* c = new Controle(type, note, pourcentage);
    e->ajouterControle(codeModule, c);
    cout << "Controle ajoute.\n";
}

// ================= Afficher tous les etuidinats =================

void Systeme::afficherTousEtudiants()
{
    for(int i = 0; i < etudiants.size(); i++)
        cout << etudiants[i]->getCNE() << " - "
             << etudiants[i]->getNom() << " "
             << etudiants[i]->getPrenom() << endl;
}

// ================= Afficher tous les modules  =================

void Systeme::afficherTousModules()
{
    for(int i = 0; i < modules.size(); i++)
        cout << modules[i]->getCode() << " - "
             << modules[i]->getNom() << " (Coef: "
             << modules[i]->getCoef() << ")" << endl;
}

// ================= AFFICHER ETUDIANT par CNE =================

void Systeme::rechercherEtAfficherEtudiant()
{
    string cne;

    cout << "Entrer CNE: ";
    cin >> cne;

    Etudiant* e = rechercherEtudiant(cne);

    if(e != NULL)
    {
        cout << "\n===== Etudiant Trouve =====\n";
        cout << "CIN: " << e->getCIN() << endl;
        cout << "Nom: " << e->getNom() << endl;
        cout << "Prenom: " << e->getPrenom() << endl;
        cout << "CNE: " << e->getCNE() << endl;
        cout << "===========================\n";
    }
    else
    {
        cout << "Etudiant introuvable.\n";
    }
}

// ================= Moy GENERAL module =================

void Systeme::moyenneGeneraleParModule()
{
    string code;
    cout << "Code module: ";
    cin >> code;

    
    Module* m = rechercherModule(code);
	if(m == NULL)
	{
    cout << "Module introuvable.\n";
    return;
	}

    float somme = 0;
    int count = 0;

    for(int i = 0; i < etudiants.size(); i++)
    {
        float moy = etudiants[i]->moyenneModule(code);

        if(moy != -1)
        {
            somme += moy;
            count++;
        }
    }

    if(count == 0)
    {
        cout << "Aucun etudiant inscrit dans ce module.\n";
        return;
    }

    cout << "Moyenne generale du module: "
         << somme / count << endl;
}

// ================= VERF SEMET =================


void Systeme::verifierSemestre()
{
    string cne;
    cout << "CNE etudiant: ";
    cin >> cne;

    Etudiant* e = rechercherEtudiant(cne);
	
    if(e != NULL)
    {
        float moy = e->calculerMoyenneGenerale();

        cout << "Moyenne semestre: " << moy << endl;

        if(e->semestreValide())
            cout << "Semestre valide\n";
        else
            cout << "Semestre non valide\n";
    }
    else
    {
        cout << "Etudiant introuvable\n";
    }
}

// ================= classement  =================

void Systeme::classementGeneral()
{
    if(etudiants.size() == 0)
    {
        cout << "Aucun etudiant.\n";
        return;
    }

    
    vector<Etudiant*> liste = etudiants;

    
    for(int i = 0; i < liste.size(); i++)
    {
        for(int j = i + 1; j < liste.size(); j++)
        {
            if(liste[i]->calculerMoyenneGenerale() < liste[j]->calculerMoyenneGenerale())
            {
                Etudiant* temp = liste[i];
                liste[i] = liste[j];
                liste[j] = temp;
            }
        }
    }

    // --------- Affichage ----------
    cout << "\n===== Classement General =====\n";

    for(int i = 0; i < liste.size(); i++)
    {
        cout << i+1 << ". "
             << liste[i]->getNom() << " "
             << liste[i]->getPrenom()
             << " | Moyenne: "
             << liste[i]->calculerMoyenneGenerale()
             << endl;
    }
    
}

// ================= filterparDecision  =================

void Systeme::filtrerParDecision()
{
	if(etudiants.size() == 0)
	{
    cout << "Aucun etudiant dans le systeme.\n";
    return;
	}

    string choix;
    cout << "afficher : 1 - Admis ou  2 - Ajourne: ";
    cin >> choix;

    for(int i = 0; i < etudiants.size(); i++)
    {
        float moy = etudiants[i]->calculerMoyenneGenerale();

        if( (choix == "1" && moy >= 10) || (choix == "2" && moy < 10) )
        {
            cout << etudiants[i]->getNom()
                 << " | Moyenne: " << moy << endl;
        }
    }
    
}

// ================= filterparFiliere  =================

void Systeme::filtrerParFiliere()
{
    string f;
    cout << "Filiere: ";
    cin >> f;
    for(int i = 0; i < etudiants.size(); i++)
        if(etudiants[i]->getFiliere() == f)
        
            cout << etudiants[i]->getNom() << " "
                 << etudiants[i]->getPrenom() << endl;
}



// ================= save  =================

void Systeme::sauvegarderTout()
{
    ofstream f("data.txt");
    for(int i = 0; i < etudiants.size(); i++)
    {
        Date d = etudiants[i]->getDate();
        f << etudiants[i]->getCNE() << " "
          << etudiants[i]->getCIN() << " "
          << etudiants[i]->getNom() << " "
          << etudiants[i]->getPrenom() << " "
          << etudiants[i]->getFiliere() << " "
          << d.jour << " " << d.mois << " " << d.annee << endl;
    }
    f.close();
    cout << "Donnees sauvegardees.\n";
}

// ================= charger  =================

void Systeme::chargerTout()
{
    ifstream f("data.txt");
    if(!f)
    {
        cout << "Fichier introuvable.\n";
        return;
    }

    string cin,cne, nom, prenom, filiere;
    Date d;

    while(f >> cne >> nom >> prenom >> filiere >> d.jour >> d.mois >> d.annee)
    {
        if(d.annee < 1990 || d.annee > 2009 || d.mois < 1 || d.mois > 12 ||d.jour < 1 || d.jour > 31)
        {
            cout << "Date invalide pour l'etudiant " << cne << endl;
            
        }

        etudiants.push_back(new Etudiant(cin,nom, prenom, d, cne, filiere));
    }

    f.close();
    cout << "Donnees chargees.\n";
}
