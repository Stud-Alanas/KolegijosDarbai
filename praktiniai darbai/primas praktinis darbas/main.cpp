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
int main() {
    int pasirinkimas = -1;
    while (pasirinkimas != 0) {
        cout << "\n== Valiutos keitykla ===\n";
        cout << "1 - Kurso palyginimas\n";
        cout << "2 - Pirkti valiuta (is EUR -> Valiuta)\n";
        cout << "3 - Parduoti valiuta (is Valiutos -> EUR)\n";
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
                if (v < 1 || v > 4) {
                    cout << "Blogas pasirinkimas.\n";
                    break;
                }
                gautiKursus(v, bendras, pirkti, parduoti);

                cout << fixed << setprecision(4);
                cout << "Bendras kursas: 1 EUR = " << bendras << "(Pasirinkta valiuta)\n";
                cout << "Pirkti kursas: 1 EUR = " << pirkti << "(Pasirinkta valiuta)\n";
                cout << "Parduoti kursas: 1 (valiuta) = " << parduoti << "EUR\n";
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
                cout << eur << " EUR --> " << rezultatas << "(valiuta)\n";
                break;
            }
        }
    }
    return 0;
}