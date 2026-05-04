#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_MENU = 50;
const double PVM = 0.21;

//sukuriame struktura vienam patiekalui
struct menuItemType {
    string menuItem;
    double menuPrice;
};
//skaitom failą kaip masyvą
void getData(menuItemType menuList[], int &menuSize) {
    ifstream fin;
    fin.open("menu.txt");

    if (!fin.is_open()) {
        cout << "Nepavyko atidaryti menu.txt failo.\n";
        return;
    }

    menuSize = 0;
//nuskaitom patiekalo pavadinima iki musu faile ;
    while (!fin.eof() && menuSize < MAX_MENU) {
        getline(fin, menuList[menuSize].menuItem, ';');

        if (menuList[menuSize].menuItem == "") {
            break;
        }

        fin >> menuList[menuSize].menuPrice;
        fin.ignore(1000, '\n');

        menuSize++;
    }

    fin.close();
}
//ispausdiname visa meniu ekrane
void showMenu(menuItemType menuList[], int menuSize) {
    cout << "\n===== PUSRYCIU MENIU =====\n";
    cout << fixed << setprecision(2);

    for (int i = 0; i < menuSize; i++) {
        cout << i + 1 << ". " << menuList[i].menuItem
             << " - " << menuList[i].menuPrice << " EUR\n";
    }

    cout << "0. Baigti pasirinkima\n";
}

void printCheck(menuItemType menuList[], int kiekiai[], int menuSize) {
    ofstream fout;
    fout.open("receipt.txt");

    double suma = 0;

    cout << fixed << setprecision(2);
    fout << fixed << setprecision(2);

    cout << "\nSveiki atvyke i restorana \"Pusryciu restoranas\"\n\n";
    fout << "Sveiki atvyke i restorana \"Pusryciu restoranas\"\n\n";

    cout << "Jusu uzsakymas:\n";
    fout << "Jusu uzsakymas:\n";

    bool arYra = false;

    for (int i = 0; i < menuSize; i++) {
        if (kiekiai[i] > 0) {
            double eilutesSuma = menuList[i].menuPrice * kiekiai[i];

            cout << kiekiai[i] << " x " << menuList[i].menuItem
                 << "  " << menuList[i].menuPrice << " EUR"
                 << " = " << eilutesSuma << " EUR\n";

            fout << kiekiai[i] << " x " << menuList[i].menuItem
                 << "  " << menuList[i].menuPrice << " EUR"
                 << " = " << eilutesSuma << " EUR\n";

            suma = suma + eilutesSuma;
            arYra = true;
        }
    }

    if (!arYra) {
        cout << "Nieko nepasirinkote.\n";
        fout << "Nieko nepasirinkote.\n";
        fout.close();
        return;
    }

    double mokestis = suma * PVM;
    double galutineSuma = suma + mokestis;

    cout << "\nTarpine suma: " << suma << " EUR\n";
    cout << "Mokesciai (21%): " << mokestis << " EUR\n";
    cout << "Galutine suma: " << galutineSuma << " EUR\n";

    fout << "\nTarpine suma: " << suma << " EUR\n";
    fout << "Mokesciai (21%): " << mokestis << " EUR\n";
    fout << "Galutine suma: " << galutineSuma << " EUR\n";

    fout.close();

    cout << "\nSaskaita irasyta i faila receipt.txt\n";
}

int main() {
    menuItemType menuList[MAX_MENU];
    int kiekiai[MAX_MENU];

    int menuSize = 0;
    int pasirinkimas;
    int porcijos;

    for (int i = 0; i < MAX_MENU; i++) {
        kiekiai[i] = 0;
    }

    getData(menuList, menuSize);

    if (menuSize == 0) {
        cout << "Meniu tuscias arba nepavyko nuskaityti duomenu.\n";
        return 0;
    }

    cout << "Sveiki atvyke i restorana \"Pusryciu restoranas\"\n";

    do {
        showMenu(menuList, menuSize);

        cout << "\nPasirinkite patiekalo numeri: ";
        cin >> pasirinkimas;

        if (pasirinkimas > 0 && pasirinkimas <= menuSize) {
            cout << "Kiek porciju norite? ";
            cin >> porcijos;

            if (porcijos > 0) {
                kiekiai[pasirinkimas - 1] = kiekiai[pasirinkimas - 1] + porcijos;
                cout << "Patiekalas pridetas.\n";
            }
            else {
                cout << "Porciju kiekis turi buti didesnis uz 0.\n";
            }
        }
        else if (pasirinkimas != 0) {
            cout << "Tokio patiekalo nera.\n";
        }

    } while (pasirinkimas != 0);

    printCheck(menuList, kiekiai, menuSize);

    return 0;
}