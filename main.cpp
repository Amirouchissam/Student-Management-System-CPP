#include <iostream>
#include "Systeme.h"
#include <cstdlib>

using namespace std;

int main()
{
    Systeme s;
    int choixPrincipal;

    do
    {
        system("cls"); 

        cout << "\n=============================\n";
        cout << "1. Espace Etudiant\n";
        cout << "2. Espace Administration\n";
        cout << "0. Quitter\n";
        cout << "Choix: ";
        cin >> choixPrincipal;

        // ================== ESPACE ETUDIANT ==================
        if(choixPrincipal == 1)
        {
            int choixEtud;

            do
            {
                system("cls");

                cout << "\n--- Espace Etudiant ---\n";
                cout << "1. Voir moyenne + decision semestre\n";
                cout << "0. Retour\n";
                cout << "Choix: ";
                cin >> choixEtud;

                system("cls");

                switch(choixEtud)
                {
                    case 1:
                        s.verifierSemestre();
                        system("pause");   
                        break;

                    case 0:
                        break;

                    default:
                        cout << "Choix invalide.\n";
                        system("pause");
                }

            } while(choixEtud != 0);
        }

        // ================== ESPACE ADMIN ==================
        else if(choixPrincipal == 2)
        {
            int choixAdmin;

            do
            {
                system("cls");

                cout << "\n--- Espace Administration ---\n";
                cout << "1. Ajouter module\n";
                cout << "2. Ajouter etudiant\n";
                cout << "3. Inscrire etudiant\n";
                cout << "4. Ajouter controle\n";
                cout << "5. afficher Tous les etudients \n";
                cout << "6 .afficher Tous les modules \n";
                cout << "7. Moyenne generale par module\n";
                cout << "8. Rechercher et afficher etudient \n";
                cout << "9. Classement general\n";
                cout << "10. Filtrer par decision\n";
                cout << "11. Filtrer par Filiere\n";
                cout << "12. Sauvegarder data.txt\n";
                cout << "13. Charger data.txt\n";
                cout << "0. Retour\n";
                cout << "Choix: ";
                cin >> choixAdmin;

                system("cls");

                switch(choixAdmin)
                {
                    case 1: s.ajouterModule(); break;
                    case 2: s.ajouterEtudiant(); break;
                    case 3: s.inscrireEtudiant(); break;
                    case 4: s.ajouterControle(); break;
                    case 5: s.afficherTousEtudiants(); break;
                    case 6: s.afficherTousModules(); break ;
                    case 7: s.moyenneGeneraleParModule(); break;
                    case 8: s.rechercherEtAfficherEtudiant();; break;
                    case 9: s.classementGeneral(); break;
                    case 10: s.filtrerParDecision(); break;
                    case 11: s.filtrerParFiliere(); break ;
                    case 12: s.sauvegarderTout(); break;
                    case 13: s.chargerTout(); break;
                    case 0: break;
                    default: cout << "Choix invalide.\n";
                }

                if(choixAdmin != 0)
                    system("pause");

            } while(choixAdmin != 0);
        }

    } while(choixPrincipal != 0);

    return 0;
}
