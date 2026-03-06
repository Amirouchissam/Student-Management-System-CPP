#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>
using namespace std;

struct Date
{
    int jour, mois, annee;
};

class Personne
{
public:
    Personne(string cin, string nom, string prenom, Date d);
    ~Personne();

    // getters
    string getCIN();
    string getNom();
    string getPrenom();
    Date getDate();

    // setters
    void setNom(string);
    void setPrenom(string);
    void setDate(Date);

private:
    const string CIN;  
    string nom;
    string prenom;
    Date dateN;
};

#endif

