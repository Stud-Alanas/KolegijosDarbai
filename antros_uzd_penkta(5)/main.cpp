#include <iostream>
using namespace std;

int main() {
    int a,b,c,d,e;
    cout << "Iveskite 5 sveikuosius skaicius: ";
    cin >> a >> b >> c >> d >> e;
    int suma = a + b + c + d + e;
    double vidurkis = suma / 5.0;
    cout << "Vidurkis: " << vidurkis << endl;
    return 0;
}