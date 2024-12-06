#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool ordina(int N, vector<int> V, vector<int> &L);

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    cin >> N;

    vector<int> V(N);
    for (int i = 0; i < N; ++i) {
        cin >> V[i];
    }

    vector<int> L;
    bool risposta = ordina(N, V, L);

    if (risposta) {
        cout << "YES" << endl;

        size_t M = L.size();
        cout << M << endl;

        for (size_t i = 0; i < M; ++i) {
            cout << L[i] << " ";
        }
        cout << endl;

    } else {
        cout << "NO" << endl;
    }
}
