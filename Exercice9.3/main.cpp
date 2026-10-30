
#include <iostream>
#include <string>
using namespace std;


class Vehicule {
protected:
    string marque;
    string modele;

public:
    Vehicule(string m, string mod) {
        marque = m;
        modele = mod;
    }

    void afficher() {
        cout << "Marque : " << marque << endl;
        cout << "Modele : " << modele << endl;
    }
};

class Thermique : virtual public Vehicule {
protected:
    float consommation;

public:
    Thermique(string m, string mod, float c)
        : Vehicule(m, mod) {
        consommation = c;
    }

    void afficherThermique() {
        cout << "Consommation : "
             << consommation << " L/100km" << endl;
    }
};


class Electrique : virtual public Vehicule {
protected:
    float autonomie;

public:
    Electrique(string m, string mod, float a)
        : Vehicule(m, mod) {
        autonomie = a;
    }

    void afficherElectrique() {
        cout << "Autonomie : "
             << autonomie << " km" << endl;
    }
};


class Hybride : public Thermique, public Electrique {
public:
    Hybride(string m, string mod, float c, float a)
        : Vehicule(m, mod),
          Thermique(m, mod, c),
          Electrique(m, mod, a) {
    }

    void afficherCaracteristiques() {
        Vehicule::afficher();
        Thermique::afficherThermique();
        Electrique::afficherElectrique();
    }
};

int main() {
    Hybride h1("Toyota", "Prius", 4.5, 60);

    h1.afficherCaracteristiques();

    return 0;
}
