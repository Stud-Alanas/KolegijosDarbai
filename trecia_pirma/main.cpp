#include <iostream>
using namespace std;

int main() {
    int p1, p2, p3, p4, p5;
    cout << "Iveskite 5 pazymius: ";
    cin >> p1 >> p2 >> p3 >> p4 >> p5;

    double vidurkis = (p1 + p2 + p3 + p4 + p5) /5.0;

    if (vidurkis >= 5.0 ) cout << "Pazymiu vidurkis teigiamas!" << endl;
    else cout << "Pazymiu vidurkis yra neigiamas..." << endl;

    cout << "Pazymiu vidurkis: " << vidurkis << endl;
    return 0;
}