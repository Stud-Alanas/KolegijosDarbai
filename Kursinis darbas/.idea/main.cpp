#include <iostream>
#include <fstream>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

// Globalus skaitikliai - skaiciuoja palyginimus ir sukeitimus
long long palyginimai = 0;
long long sukeitimai = 0;

// =============================================================
// ITERPIMO RIKIAVIMAS (Insertion Sort)
// =============================================================
void iterpimoRikiavimas(int masyvas[], int n) {
    for (int i = 1; i < n; i++) {
        int dabartinis = masyvas[i]; // Imam elementa, kuri dedam i vieta
        int j = i - 1;

        // Stumiam didesnius elementus i desine
        while (j >= 0) {
            palyginimai++;
            if (masyvas[j] > dabartinis) {
                masyvas[j + 1] = masyvas[j];
                sukeitimai++;
                j--;
            } else {
                break;
            }
        }
        masyvas[j + 1] = dabartinis; // Istatom elementa i vieta
    }
}

// =============================================================
// SULIEJIMO RIKIAVIMAS (Merge Sort)
// =============================================================

// Sujungia dvi jau surikiuotas dalis i viena surikiuota
void sulieti(int masyvas[], int kaire, int vidurys, int desine) {
    int n1 = vidurys - kaire + 1;
    int n2 = desine - vidurys;

    // Laikini masyvai dviem pusem
    int* kaireDalis = new int[n1];
    int* desineDalis = new int[n2];

    for (int i = 0; i < n1; i++)
        kaireDalis[i] = masyvas[kaire + i];
    for (int j = 0; j < n2; j++)
        desineDalis[j] = masyvas[vidurys + 1 + j];

    int i = 0, j = 0, k = kaire;

    // Lyginam ir dedam mazesnius pirma
    while (i < n1 && j < n2) {
        palyginimai++;
        if (kaireDalis[i] <= desineDalis[j]) {
            masyvas[k] = kaireDalis[i];
            i++;
        } else {
            masyvas[k] = desineDalis[j];
            j++;
            sukeitimai++; // skaiciuojam, kai elementas perkeliamas is desines
        }
        k++;
    }

    // Likusius elementus tiesiog perkeliam
    while (i < n1) { masyvas[k++] = kaireDalis[i++]; }
    while (j < n2) { masyvas[k++] = desineDalis[j++]; }

    delete[] kaireDalis;
    delete[] desineDalis;
}

// Pagrindine rekursyvi funkcija - dalina masyva i puses
void suliejimoRikiavimas(int masyvas[], int kaire, int desine) {
    if (kaire < desine) {
        int vidurys = (kaire + desine) / 2;
        suliejimoRikiavimas(masyvas, kaire, vidurys);
        suliejimoRikiavimas(masyvas, vidurys + 1, desine);
        sulieti(masyvas, kaire, vidurys, desine);
    }
}

// =============================================================
// DUOMENU GENERAVIMAS
// =============================================================
void generuotiNesurikiuotus(int masyvas[], int n) {
    srand(42); // fiksuota sekla, kad tas pats rezultatas kiekviena karta
    for (int i = 0; i < n; i++) {
        masyvas[i] = rand() % 100000;
    }
}

void generuotiSurikiuotus(int masyvas[], int n) {
    for (int i = 0; i < n; i++) {
        masyvas[i] = i;
    }
}

void generuotiAtvirksciai(int masyvas[], int n) {
    for (int i = 0; i < n; i++) {
        masyvas[i] = n - i;
    }
}

// Kopijuoja viena masyva i kita
void kopijuoti(int saltinis[], int paskirtis[], int n) {
    for (int i = 0; i < n; i++) {
        paskirtis[i] = saltinis[i];
    }
}

// =============================================================
// PAGRINDINE FUNKCIJA
// =============================================================
int main() {
    const int DYDZIU = 3;
    const int KARTU = 5;
    int dydziai[DYDZIU] = {5000, 10000, 50000};

    // Skiriam atminti pakankamai dideliam masyvui
    int* originalas = new int[50000];
    int* darbinis = new int[50000];

    ofstream f("rezultatai.csv");
    f << "Tipas;Dydis;Algoritmas;Laikas_us;Palyginimai;Sukeitimai\n";

    for (int t = 0; t < 3; t++) {
        string tipas;
        if (t == 0) tipas = "Nesurikiuoti";
        else if (t == 1) tipas = "Atvirksciai";
        else tipas = "Surikiuoti";

        cout << "\n=== " << tipas << " duomenys ===\n";

        for (int d = 0; d < DYDZIU; d++) {
            int n = dydziai[d];

            // Sugeneruojam originalia duomenu kopija
            if (t == 0) generuotiNesurikiuotus(originalas, n);
            else if (t == 1) generuotiAtvirksciai(originalas, n);
            else generuotiSurikiuotus(originalas, n);

            // ----- ITERPIMO RIKIAVIMAS -----
            long long bendrasLaikas = 0;
            long long pal = 0, suk = 0;

            for (int k = 0; k < KARTU; k++) {
                kopijuoti(originalas, darbinis, n);
                palyginimai = 0;
                sukeitimai = 0;

                auto pradzia = high_resolution_clock::now();
                iterpimoRikiavimas(darbinis, n);
                auto pabaiga = high_resolution_clock::now();

                bendrasLaikas += duration_cast<microseconds>(pabaiga - pradzia).count();
                pal = palyginimai;
                suk = sukeitimai;
            }
            long long vid = bendrasLaikas / KARTU;

            cout << "Iterpimo  n=" << n << ": " << vid << " us, palyg="
                 << pal << ", suk=" << suk << "\n";
            f << tipas << ";" << n << ";Iterpimo;" << vid << ";"
              << pal << ";" << suk << "\n";

            // ----- SULIEJIMO RIKIAVIMAS -----
            bendrasLaikas = 0;
            for (int k = 0; k < KARTU; k++) {
                kopijuoti(originalas, darbinis, n);
                palyginimai = 0;
                sukeitimai = 0;

                auto pradzia = high_resolution_clock::now();
                suliejimoRikiavimas(darbinis, 0, n - 1);
                auto pabaiga = high_resolution_clock::now();

                bendrasLaikas += duration_cast<microseconds>(pabaiga - pradzia).count();
                pal = palyginimai;
                suk = sukeitimai;
            }
            vid = bendrasLaikas / KARTU;

            cout << "Suliejimo n=" << n << ": " << vid << " us, palyg="
                 << pal << ", suk=" << suk << "\n";
            f << tipas << ";" << n << ";Suliejimo;" << vid << ";"
              << pal << ";" << suk << "\n";
        }
    }

    delete[] originalas;
    delete[] darbinis;
    f.close();

    cout << "\nRezultatai issaugoti faile rezultatai.csv\n";
    return 0;
}