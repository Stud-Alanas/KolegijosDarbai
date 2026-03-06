#include <iostream>
#include <iomanip>
using namespace std;
//apvalinti skaičius iki dviejų po kablelio..
double apvalinti(double x) {
    int t = (int)(x * 100 + 0.5);
    return t / 100.0;
}
// aprašau valiutas
void gautiKursus( int valiuta, double &bendras, double &pirkti, double &parduoti ) {
   // Euras
    if (valiuta == 1) {
        bendras = 1.0;
        pirkti = 1.0;
        parduoti = 1.0;
    }
    //GBP
    else if (valiuta == 2) {
        bendras = 0.8729;
        pirkti = 0.8600;
        parduoti = 0.9220;
    }
    //USD
    else if (valiuta == 3) {
        bendras = 1.1793;
        pirkti = 1.1460;
        parduoti = 1.2340;
    }
    //INR
    else if (valiuta == 4) {
        bendras = 104.6918;
        pirkti = 101.3862;
        parduoti = 107.8546;
    }
}
void spausdintiValiutas () {
    cout << "Valiutos:\n";
    cout << "1 - EUR\n";
    cout << "2 - GBP\n";
    cout << "3 - USD\n";
    cout << "4 - INR\n";
}

string gautiValiuta (int v) {
    if (v == 1) return "EUR";
    if (v == 2) return "GBP";
    if (v == 3) return "USD";
    if (v == 4) return "INR";
}
int main() {
    int pasirinkimas = -1;
    while (pasirinkimas != 0) {
        cout << "\n== Valiutos keitykla ===\n";
        cout << "1 - Kurso palyginimas\n";
        cout << "2 - Pirkti valiuta ( EUR -> Valiuta )\n";
        cout << "3 - Parduoti valiuta ( Valiutos -> EUR )\n";
        cout << "Pasirinkimas: ";
        cin >> pasirinkimas;

        switch (pasirinkimas) {
            case 1: {
                int v;
                double bendras, pirkti, parduoti;
                cout << "\n--- Kurso palyginimas ---\n";
                spausdintiValiutas();
                cout << "Pasirinkite valiuta: ";
                cin >> v;
                string valiuta = gautiValiuta(v);
                if (v < 1 || v > 4) {
                    cout << "Blogas pasirinkimas.\n";
                    break;
                }
                gautiKursus(v, bendras, pirkti, parduoti);

                cout << fixed << setprecision(4);
                cout << "Bendras kursas: 1 EUR = " << bendras << valiuta << " \n";
                cout << "Pirkti kursas: 1 EUR = " << pirkti << valiuta << " \n";
                cout << "Parduoti kursas: 1 " << valiuta << " = " << parduoti << " EUR \n";
                break;

            }
            case 2: {
                int v;
                double bendras, pirkti, parduoti;
                double eur, rezultatas;

                cout << "\n--- Pirkti valiuta ---\n";
                spausdintiValiutas();
                cout << "Kuria valiuta perki?: ";
                cin >> v;
                string valiuta = gautiValiuta(v);

                if (v < 1 || v > 4) {
                    cout << "Blogas pasirinkimas.\n";
                    break;
                }
                cout << "Ivesk EUR kieki: ";
                cin >> eur;

                gautiKursus(v, bendras, pirkti, parduoti);
                rezultatas = eur * pirkti;
                rezultatas = apvalinti(rezultatas);

                cout << fixed << setprecision(2);
                cout << eur << " EUR --> " << rezultatas << valiuta << " \n";
                break;
            }
                case 3: {
                int v;
                double bendras, pirkti, parduoti;
                double kiekis, eur;

                cout << "\n--- Parduoti valiuta ---\n";
                spausdintiValiutas();
                cout << "Kuria valiuta parduodi?: ";
                cin >> v;
                string valiuta = gautiValiuta(v);

                if (v < 1 || v > 4) {
                    cout << "Blogas pasirinkimas.\n";
                    break;
                }
                cout << "Ivesk EUR kieki: ";
                cin >> kiekis;
                gautiKursus(v, bendras, pirkti, parduoti);
                eur = kiekis * parduoti;
                eur = apvalinti(eur);

                cout << fixed << setprecision(2);
                cout << kiekis << valiuta << " -> " << eur << " EUR \n";
                break;
            }
            case 0:
                cout << "Geros dienos\n";
                break;
                default:
                cout << "Neteisingas pasirinkimas.\n";
        }
    }
    return 0;
}