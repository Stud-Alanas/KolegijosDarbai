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

    return 0;
}