// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int points[] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N;
        cin >> N;
        
        int tp = 0;
        int to = 0;
        for (int i = 0; i < N; ++i) {
            int p;
            cin >> p;
            int o = p == 1 ? 18 : 25;
            p = points[p - 1];
            tp += p;
            to += o;
        }
        
        cout << (tp >= to ? "Champion" : "Practice harder") << endl;
    }

    return 0;
}
