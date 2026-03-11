#include <iostream>
#include <string>
using namespace std;

const int MAX_MOKINIU = 100;
const int MAX_PAZYMIU = 10;

// Funkcija naujo mokinio įvedimui
void pridetiMokini(string vardai[], int pazymiai[][MAX_PAZYMIU], int pazymiuKiekis[], int &mokiniuKiekis) {
    if (mokiniuKiekis >= MAX_MOKINIU) {
        cout << "Negalima prideti daugiau mokiniu. Sarasas pilnas.\n";
        return;
    }

    cout << "Iveskite mokinio varda: ";
    cin.ignore();
    getline(cin, vardai[mokiniuKiekis]);

    int kiek;
    do {
        cout << "Kiek pazymiu norite ivesti? (1-10): ";
        cin >> kiek;
    } while (kiek < 1 || kiek > MAX_PAZYMIU);

    pazymiuKiekis[mokiniuKiekis] = kiek;

    for (int i = 0; i < kiek; i++) {
        do {
            cout << "Iveskite " << i + 1 << "-aji pazymi: ";
            cin >> pazymiai[mokiniuKiekis][i];
        } while (pazymiai[mokiniuKiekis][i] < 1 || pazymiai[mokiniuKiekis][i] > 10);
    }

    mokiniuKiekis++;
    cout << "Mokinys sekmingai pridetas.\n";
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}