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
// Funkcija mokiniui ištrinti
void salintiMokini(string vardai[], int pazymiai[][MAX_PAZYMIU], int pazymiuKiekis[], int &mokiniuKiekis) {
    if (mokiniuKiekis == 0) {
        cout << "Sarasas tuscias.\n";
        return;
    }

    int nr;
    cout << "Iveskite mokinio numeri, kuri norite pasalinti (1-" << mokiniuKiekis << "): ";
    cin >> nr;

    if (nr < 1 || nr > mokiniuKiekis) {
        cout << "Tokio mokinio nera.\n";
        return;
    }

    nr--;

    for (int i = nr; i < mokiniuKiekis - 1; i++) {
        vardai[i] = vardai[i + 1];
        pazymiuKiekis[i] = pazymiuKiekis[i + 1];

        for (int j = 0; j < MAX_PAZYMIU; j++) {
            pazymiai[i][j] = pazymiai[i + 1][j];
        }
    }

    mokiniuKiekis--;
    cout << "Mokinys sekmingai pasalintas.\n";
}

int main() {
    string vardai[MAX_MOKINIU];
    int pazymiai[MAX_MOKINIU][MAX_PAZYMIU];
    int pazymiuKiekis[MAX_MOKINIU];
    int mokiniuKiekis = 0;
    int pasirinkimas;

    do {
        cout << "\n===== MOKINIU PAZYMIU SISTEMA =====\n";
        cout << "1. Prideti mokini\n";
        cout << "2. Rodyti visus mokinius\n";
        cout << "3. Rodyti konkretaus mokinio pazymius\n";
        cout << "4. Atnaujinti pazymi\n";
        cout << "5. Pasalinti mokini\n";
        cout << "0. Baigti darba\n";
        cout << "Pasirinkite veiksma: ";
        cin >> pasirinkimas;

        switch (pasirinkimas) {
            case 1:
                pridetiMokini(vardai, pazymiai, pazymiuKiekis, mokiniuKiekis);
                break;
            case 2:
                rodytiVisus(vardai, pazymiai, pazymiuKiekis, mokiniuKiekis);
                break;
            case 3:
                rodytiViena(vardai, pazymiai, pazymiuKiekis, mokiniuKiekis);
                break;
            case 4:
                atnaujintiPazymi(vardai, pazymiai, pazymiuKiekis, mokiniuKiekis);
                break;
            case 5:
                salintiMokini(vardai, pazymiai, pazymiuKiekis, mokiniuKiekis);
                break;
            case 0:
                cout << "Programa baigta.\n";
                break;
            default:
                cout << "Neteisingas pasirinkimas.\n";
        }

    } while (pasirinkimas != 0);

    return 0;
}