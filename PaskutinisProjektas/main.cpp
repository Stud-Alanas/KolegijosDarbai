#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const int MAX_FILMU = 100;

//Struktura filmui saugoti

struct Filmas {
    string pavadinimas;
    string rezisierius;
    int metai;
    string zanras;
    double ivertinimas;

};

//Funkcija kuri nuskaito filmus is failo
void nuskaitytiIsFailo(Filmas filmai[], int &kiekis) {
    ifstream fin;
    fin.open("filmai.txt");

    if (!fin.is_open()) {
        cout << "Nepavyko atidaryti filmai.txt failo.\n";
        return;
    }

    kiekis = 0;

    while (kiekis < MAX_FILMU && getline(fin, filmai[kiekis].pavadinimas, ';')) {
        getline(fin, filmai[kiekis].rezisierius, ';');

        fin >> filmai[kiekis].metai;

        fin.ignore(1000, ';');

        getline(fin, filmai[kiekis].zanras, ';');

        fin >> filmai[kiekis].ivertinimas;

        fin.ignore(1000, '\n');

        kiekis++;
    }

    fin.close();
}

//Funkcija issaugo filmus i faila
void issaugotiIFaila(Filmas filmai[], int kiekis) {
    ofstream fout;

    fout.open("filmai.txt");

    if (!fout.is_open()) {
        cout << "Nepavyko issaugoti duomenu i filmai.txt faila.\n";
        return;
    }

    fout << fixed << setprecision(1);

    for (int i = 0; i < kiekis; i++) {

        fout << filmai[i].pavadinimas << ";"
             << filmai[i].rezisierius << ";"
             << filmai[i].metai << ";"
             << filmai[i].zanras << ";"
             << filmai[i].ivertinimas << endl;
    }

    fout.close();
}
//funkcija parodo visus filmus
void rodytiVisus(Filmas filmai[], int kiekis) {
    if (kiekis == 0) {

        cout << "Filmu sarasas tuscias.\n";

        return;
    }

    cout << "\n===== FILMU KATALOGAS =====\n";

    cout << fixed << setprecision(1);

    for (int i = 0; i < kiekis; i++) {
        cout << i + 1 << ". "
             << filmai[i].pavadinimas << " | "
             << filmai[i].rezisierius << " | "
             << filmai[i].metai << " | "
             << filmai[i].zanras << " | "
             << filmai[i].ivertinimas << endl;
    }
}
//funkcija prideda nauja filma
void pridetiFilma(Filmas filmai[], int &kiekis) {
    if (kiekis >= MAX_FILMU) {

        cout << "Negalima prideti daugiau filmu.\n";

        return;
    }

    cout << "\n--- Naujo filmo pridejimas ---\n";

    cout << "Iveskite filmo pavadinima: ";
    getline(cin, filmai[kiekis].pavadinimas);

    cout << "Iveskite rezisieriu: ";
    getline(cin, filmai[kiekis].rezisierius);

    cout << "Iveskite metus: ";
    cin >> filmai[kiekis].metai;
    cin.ignore(1000, '\n');

    cout << "Iveskite zanra: ";
    getline(cin, filmai[kiekis].zanras);

    cout << "Iveskite ivertinima: ";
    cin >> filmai[kiekis].ivertinimas;
    cin.ignore(1000, '\n');

    kiekis++;

    issaugotiIFaila(filmai, kiekis);

    cout << "Filmas sekmingai pridetas.\n";
}

//Funkcija redaguoja pasirinkta filma
void redaguotiFilma(Filmas filmai[], int kiekis) {
    if (kiekis == 0) {
        cout << "Filmu sarasas tuscias.\n";
        return;
    }

    rodytiVisus(filmai, kiekis);

    int nr;
    cout << "\nIveskite filmo numeri, kuri norite redaguoti: ";
    cin >> nr;
    cin.ignore(1000, '\n');

    if (nr < 1 || nr > kiekis) {
        cout << "Tokio filmo nera.\n";
        return;
    }

    nr--;

    cout << "Iveskite nauja pavadinima: ";
    getline(cin, filmai[nr].pavadinimas);

    cout << "Iveskite nauja rezisieriu: ";
    getline(cin, filmai[nr].rezisierius);

    cout << "Iveskite naujus metus: ";
    cin >> filmai[nr].metai;
    cin.ignore(1000, '\n');

    cout << "Iveskite nauja zanra: ";
    getline(cin, filmai[nr].zanras);

    cout << "Iveskite nauja ivertinima: ";
    cin >> filmai[nr].ivertinimas;
    cin.ignore(1000, '\n');

    issaugotiIFaila(filmai, kiekis);

    cout << "Filmas sekmingai redaguotas.\n";
}

//funkcija kuri pasalina filma
void salintiFilma(Filmas filmai[], int &kiekis) {
    if (kiekis == 0) {
        cout << "Filmu sarasas tuscias.\n";
        return;
    }

    rodytiVisus(filmai, kiekis);

    int nr;
    cout << "\nIveskite filmo numeri, kuri norite pasalinti: ";
    cin >> nr;
    cin.ignore(1000, '\n');

    if (nr < 1 || nr > kiekis) {
        cout << "Tokio filmo nera.\n";
        return;
    }

    nr--;

    for (int i = nr; i < kiekis - 1; i++) {
        filmai[i] = filmai[i + 1];
    }

    kiekis--;

    issaugotiIFaila(filmai, kiekis);

    cout << "Filmas sekmingai pasalintas.\n";
}

//Funkcija kuri daro paieska pagal pavadinima
void ieskotiPagalPavadinima(Filmas filmai[], int kiekis) {
    if (kiekis == 0) {
        cout << "Filmu sarasas tuscias.\n";
        return;
    }

    string tekstas;
    bool rasta = false;

    cout << "Iveskite ieskoma pavadinima arba jo dali: ";
    getline(cin, tekstas);

    cout << "\n--- Paieskos rezultatai ---\n";

    for (int i = 0; i < kiekis; i++) {
        if (filmai[i].pavadinimas.find(tekstas) != string::npos) {
            cout << i + 1 << ". "
                 << filmai[i].pavadinimas << " | "
                 << filmai[i].rezisierius << " | "
                 << filmai[i].metai << " | "
                 << filmai[i].zanras << " | "
                 << filmai[i].ivertinimas << endl;

            rasta = true;
        }
    }

    if (!rasta) {
        cout << "Filmu pagal toki pavadinima nerasta.\n";
    }
}

//Funkcija kuri rikiuoja filmus pagal metus
void rikiuotiPagalMetus(Filmas filmai[], int kiekis) {
    for (int i = 0; i < kiekis - 1; i++) {
        for (int j = i + 1; j < kiekis; j++) {
            if (filmai[i].metai > filmai[j].metai) {
                Filmas laikinas = filmai[i];
                filmai[i] = filmai[j];
                filmai[j] = laikinas;
            }
        }
    }

    issaugotiIFaila(filmai, kiekis);

    cout << "Filmai surikiuoti pagal metus nuo seniausio iki naujausio.\n";
}

//funkcija kuri apskaiciuoja vidutini ivertinima
void rodytiVidutiniIvertinima(Filmas filmai[], int kiekis) {
    if (kiekis == 0) {
        cout << "Filmu sarasas tuscias.\n";
        return;
    }

    double suma = 0;

    for (int i = 0; i < kiekis; i++) {
        suma = suma + filmai[i].ivertinimas;
    }

    double vidurkis = suma / kiekis;

    cout << fixed << setprecision(2);
    cout << "Vidutinis filmu ivertinimas: " << vidurkis << endl;
}

//funkcija kuri sukuria ataskaita(ispausdina txt faila)
void sukurtiAtaskaita(Filmas filmai[], int kiekis) {
    ofstream fout;
    fout.open("ataskaita.txt");

    if (!fout.is_open()) {
        cout << "Nepavyko sukurti ataskaita.txt failo.\n";
        return;
    }

    fout << "FILMU KATALOGO ATASKAITA\n\n";
    fout << fixed << setprecision(1);

    for (int i = 0; i < kiekis; i++) {
        fout << i + 1 << ". "
             << filmai[i].pavadinimas << " | "
             << filmai[i].rezisierius << " | "
             << filmai[i].metai << " | "
             << filmai[i].zanras << " | "
             << filmai[i].ivertinimas << endl;
    }

    fout.close();

    cout << "Ataskaita sukurta faile ataskaita.txt\n";
}

int main() {
    Filmas filmai[MAX_FILMU];
    int kiekis = 0;
    int pasirinkimas;

    nuskaitytiIsFailo(filmai, kiekis);
    do {
        cout << "\n===== FILMU KATALOGO SISTEMA =====\n";
        cout << "1. Rodyti visus filmus\n";
        cout << "2. Prideti nauja filma\n";
        cout << "3. Redaguoti filma\n";
        cout << "4. Pasalinti filma\n";
        cout << "5. Ieskoti filmo pagal pavadinima\n";
        cout << "6. Rikiuoti filmus pagal metus\n";
        cout << "7. Rodyti vidutini filmu ivertinima\n";
        cout << "8. Sukurti ataskaita i faila\n";
        cout << "0. Baigti darba\n";
        cout << "Pasirinkite veiksma: ";

        cin >> pasirinkimas;
        cin.ignore(1000, '\n');

        switch (pasirinkimas) {
            case 1:
                rodytiVisus(filmai, kiekis);
                break;

            case 2:
                pridetiFilma(filmai, kiekis);
                break;

            case 3:
                redaguotiFilma(filmai, kiekis);
                break;

            case 4:
                salintiFilma(filmai, kiekis);
                break;

            case 5:
                ieskotiPagalPavadinima(filmai, kiekis);
                break;

            case 6:
                rikiuotiPagalMetus(filmai, kiekis);
                break;

            case 7:
                rodytiVidutiniIvertinima(filmai, kiekis);
                break;

            case 8:
                sukurtiAtaskaita(filmai, kiekis);
                break;

            case 0:
                issaugotiIFaila(filmai, kiekis);
                cout << "Programa baigta.\n";
                break;

            default:
                cout << "Neteisingas pasirinkimas.\n";
        }

    } while (pasirinkimas != 0);


    return 0;
}