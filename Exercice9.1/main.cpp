
#include <iostream>
#include <string>
using namespace std;

// Classe Personne
class Personne {
protected:
    string nom;
    string prenom;

public:
    Personne(string n, string p) {
        nom = n;
        prenom = p;
    }

    void afficher() {
        cout << "Nom : " << nom << endl;
        cout << "Prenom : " << prenom << endl;
    }
};

class Chercheur {
protected:
    string domaineRecherche;

public:
    Chercheur(string d) {
        domaineRecherche = d;
    }

    void afficher() {
        cout << "Domaine de recherche : "
             << domaineRecherche << endl;
    }
};

class EnseignantChercheur : public Personne, public Chercheur {
public:
    EnseignantChercheur(string n, string p, string d)
        : Personne(n, p), Chercheur(d) {
    }

    void afficher() {
        Personne::afficher();
        Chercheur::afficher();
    }
};

int main() {
    EnseignantChercheur e1("Ahmed", "Ali", "Intelligence Artificielle");

    e1.afficher();

    return 0;
}
