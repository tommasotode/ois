// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        string N;
        cin >> N;

        int len = N.length();
        if (len == 1) {
            cout << (N == "0" ? "0" : "-1") << endl;
            continue;
        }

        // len >= 2
        int pen = N[len - 2] - '0';
        int ult = N[len - 1] - '0';
        if ((pen * 10 + ult) % 25 == 0) {
            cout << "0" << endl;
            continue;
        }
        if ((ult * 10 + pen) % 25 == 0) {
            cout << "1" << endl;
            continue;
        }

        // non finisce per 00, 25, 50, 75, 52, 05 o 75 -> almeno una cifra viene da fuori
        int n0 = false;
        bool n2 = false;
        bool n5 = false;
        bool n7 = false;
        for (int i = 0; i < len - 2; i++) {
            switch (N[i]) {
                case '0': if (n0 < 2) n0++; break;
                case '2': n2 = true; break;
                case '5': n5 = true; break;
                case '7': n7 = true; break;
            }
        }

        // qui abbiamo un resoconto di cosa abbiamo a disposizione
        // se una cifra è già posto, provo a vedere se posso completare con quello che ho a disposizione
        // se non posso, è come se nessuna cifra fosse già a posto
        // a quel punto guardo se ho due elementi che mi permettono di fare 00, 25, 50 o 75

        // prima cifra a posto
        if (pen == 0 || pen == 5) {
            if (n0 > 0) {
                cout << "1" << endl;
                continue;
            }
        } else if (pen == 2 || pen == 7) {
            if (n5) {
                cout << "1" << endl;
                continue;
            }
        }
        // seconda cifra a posto
        if (ult == 0) {
            if (n0 > 0 || n5) {
                cout << "1" << endl;
                continue;
            }
        } else if (ult == 5) {
            if (n2 || n7) {
                cout << "1" << endl;
                continue;
            }
        }

        // o 2 o impossibile
        for (int i = len - 2; i < len; i++) {
            switch (N[i]) {
                case '0': if (n0 < 2) n0++; break;
                case '2': n2 = true; break;
                case '5': n5 = true; break;
                case '7': n7 = true; break;
            }
        }

        cout << (n0 == 2 || n2 && n5 || n5 && n0 > 0 || n7 && n5 ? "2" : "-1") << endl;
    }

    return 0;
}
