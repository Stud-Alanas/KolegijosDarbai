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
// Funkcija visiems mokiniams parodyti
void rodytiVisus(string vardai[], int pazymiai[][MAX_PAZYMIU], int pazymiuKiekis[], int mokiniuKiekis) {
    if (mokiniuKiekis == 0) {
        cout << "Sarasas tuscias.\n";
        return;
    }

    cout << "\n--- Visi mokiniai ir ju pazymiai ---\n";
    for (int i = 0; i < mokiniuKiekis; i++) {
        cout << i + 1 << ". " << vardai[i] << " -> ";
        for (int j = 0; j < pazymiuKiekis[i]; j++) {
            cout << pazymiai[i][j] << " ";
        }
        cout << endl;
    }
}

// Funkcija vieno mokinio informacijos parodymui
void rodytiViena(string vardai[], int pazymiai[][MAX_PAZYMIU], int pazymiuKiekis[], int mokiniuKiekis) {
    if (mokiniuKiekis == 0) {
        cout << "Sarasas tuscias.\n";
        return;
    }

    int nr;
    cout << "Iveskite mokinio numeri (1-" << mokiniuKiekis << "): ";
    cin >> nr;

    if (nr < 1 || nr > mokiniuKiekis) {
        cout << "Tokio mokinio nera.\n";
        return;
    }

    nr--;

    cout << "\nMokinys: " << vardai[nr] << endl;
    cout << "Pazymiai: ";
    for (int i = 0; i < pazymiuKiekis[nr]; i++) {
        cout << pazymiai[nr][i] << " ";
    }
    cout << endl;
}

// Funkcija pažymiui atnaujinti
void atnaujintiPazymi(string vardai[], int pazymiai[][MAX_PAZYMIU], int pazymiuKiekis[], int mokiniuKiekis) {
    if (mokiniuKiekis == 0) {
        cout << "Sarasas tuscias.\n";
        return;
    }

    int mokNr;
    cout << "Iveskite mokinio numeri (1-" << mokiniuKiekis << "): ";
    cin >> mokNr;

    if (mokNr < 1 || mokNr > mokiniuKiekis) {
        cout << "Tokio mokinio nera.\n";
        return;
    }

    mokNr--;

    cout << "Mokinys: " << vardai[mokNr] << endl;
    cout << "Esami pazymiai:\n";
    for (int i = 0; i < pazymiuKiekis[mokNr]; i++) {
        cout << i + 1 << ". " << pazymiai[mokNr][i] << endl;
    }

    int pazNr;
    cout << "Kuri pazymi norite pakeisti? (1-" << pazymiuKiekis[mokNr] << "): ";
    cin >> pazNr;

    if (pazNr < 1 || pazNr > pazymiuKiekis[mokNr]) {
        cout << "Tokio pazymio nera.\n";
        return;
    }

    int naujas;
    do {
        cout << "Iveskite nauja pazymi (1-10): ";
        cin >> naujas;
    } while (naujas < 1 || naujas > 10);

    pazymiai[mokNr][pazNr - 1] = naujas;
    cout << "Pazymys sekmingai atnaujintas.\n";
}

int main() {

    return 0;
}