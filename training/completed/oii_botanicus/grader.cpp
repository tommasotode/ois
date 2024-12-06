#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int pota(int N, vector<int> P);

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    int soluzione = pota(N, P);
    cout << soluzione << "\n";
}
