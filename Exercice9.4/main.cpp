
#include <iostream>
#include <string>
using namespace std;

// Classe de base
class Utilisateur {
protected:
    int identifiant;
    string login;

public:
    Utilisateur(int id, string l) {
        identifiant = id;
        login = l;
    }

    void afficher() {
        cout << "Identifiant : " << identifiant << endl;
        cout << "Login : " << login << endl;
    }
};

// Classe Administrateur
class Administrateur : virtual public Utilisateur {
protected:
    string droitsAcces;

public:
    Administrateur(int id, string l, string d)
        : Utilisateur(id, l) {
        droitsAcces = d;
    }

    void gererSysteme() {
        cout << "Gestion du systeme : "
             << droitsAcces << endl;
    }
};

// Classe Moderateur
class Moderateur : virtual public Utilisateur {
protected:
    int niveauModeration;

public:
    Moderateur(int id, string l, int n)
        : Utilisateur(id, l) {
        niveauModeration = n;
    }

    void modererContenu() {
        cout << "Moderation du contenu - Niveau : "
             << niveauModeration << endl;
    }
};

// Classe SuperUtilisateur
class SuperUtilisateur : public Administrateur, public Moderateur {
public:
    SuperUtilisateur(int id, string l, string d, int n)
        : Utilisateur(id, l),
          Administrateur(id, l, d),
          Moderateur(id, l, n) {
    }

    void afficherInfos() {
        Utilisateur::afficher();
        cout << "Droits d'acces : " << droitsAcces << endl;
        cout << "Niveau de moderation : "
             << niveauModeration << endl;
    }
};

int main() {
    SuperUtilisateur* s = nullptr;
    int choix;

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Creer un SuperUtilisateur" << endl;
        cout << "2. Afficher les informations" << endl;
        cout << "3. Gerer le systeme" << endl;
        cout << "4. Moderer le contenu" << endl;
        cout << "0. Quitter" << endl;
        cout << "Votre choix : ";
        cin >> choix;

        switch (choix) {
        case 1: {
            int id, niveau;
            string login, droits;

            cout << "Identifiant : ";
            cin >> id;

            cout << "Login : ";
            cin >> login;

            cout << "Droits d'acces : ";
            cin >> droits;

            cout << "Niveau de moderation : ";
            cin >> niveau;

            delete s;
            s = new SuperUtilisateur(id, login, droits, niveau);

            cout << "SuperUtilisateur cree !" << endl;
            break;
        }

        case 2:
            if (s != nullptr)
                s->afficherInfos();
            else
                cout << "Creez d'abord un utilisateur." << endl;
            break;

        case 3:
            if (s != nullptr)
                s->gererSysteme();
            else
                cout << "Creez d'abord un utilisateur." << endl;
            break;

        case 4:
            if (s != nullptr)
                s->modererContenu();
            else
                cout << "Creez d'abord un utilisateur." << endl;
            break;

        case 0:
            cout << "Fin du programme." << endl;
            break;

        default:
            cout << "Choix invalide !" << endl;
        }

    } while (choix != 0);

    delete s;
    return 0;
}
