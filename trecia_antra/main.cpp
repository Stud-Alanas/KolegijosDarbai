#include <iostream>
using namespace std;

int main() {
   int egzaminoVertinimas;
    cout << "Iveskite egzamino vertinima(1-10): ";
    cin >> egzaminoVertinimas;
    if (egzaminoVertinimas == 10) cout << "Puiku" << endl;
    else if (egzaminoVertinimas >= 9 ) cout << "labai gerai" << endl;
    else if (egzaminoVertinimas >= 7 ) cout << "gerai" << endl;
    else if (egzaminoVertinimas >= 5 ) cout << "patenkinamai" << endl;
    else cout << "Egzaminas neislaikytas" << endl;
    return 0;
}