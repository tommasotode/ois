// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long peaks(vector<int>& V, int N) {
    long long P = 0;
    for (int i = 0; i < N; i++) {
        int left = i > 0 ? V[i - 1] : 0;
        int right = i < N - 1 ? V[i + 1] : 0;
        if (left < V[i] && V[i] > right) P++;
    }
    return P;
}

int main() {
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    vector<int> B(M);
    for (int i = 0; i < M; i++)
        cin >> B[i];

    cout << (peaks(A, N) * peaks(B, M)) << endl;

    return 0;
}
