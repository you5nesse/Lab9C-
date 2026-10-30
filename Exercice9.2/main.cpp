
#include <iostream>
using namespace std;

class Technicien {
protected:
    float salaire;

public:
    Technicien(float s) {
        salaire = s;
    }

    void afficherSalaire() {
        cout << "Salaire Technicien : "
             << salaire << " DH" << endl;
    }
};


class Comptable {
protected:
    float salaire;

public:
    Comptable(float s) {
        salaire = s;
    }

    void afficherSalaire() {
        cout << "Salaire Comptable : "
             << salaire << " DH" << endl;
    }
};

class EmployePolyvalent : public Technicien, public Comptable {
public:
    EmployePolyvalent(float s1, float s2)
        : Technicien(s1), Comptable(s2) {
    }

    void afficherTousSalaires() {
        Technicien::afficherSalaire();
        Comptable::afficherSalaire();
    }
};

int main() {
    EmployePolyvalent e1(5000, 6000);

    e1.afficherTousSalaires();

    e1.Technicien::afficherSalaire();
    e1.Comptable::afficherSalaire();

    return 0;
}
