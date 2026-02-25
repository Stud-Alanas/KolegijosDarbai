#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Iveskite dvizenkli skaiciu: ";
    cin >> n;
    int desimtys = n / 10;
    int vienetai = n % 10;
    int suma = desimtys + vienetai;
    cout << "Skaitmenu suma: " << suma << endl;
    return 0;
}