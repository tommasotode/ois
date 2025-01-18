#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  string A, B; cin >> A >> B;

  string C = "";
  for (int i = 0; i < min(A.size(), B.size()); i++) {
    if (A[i] < B[i]) {
      C.push_back(A[i] + 1);

      if (C == B) {
        C[i] = A[i];

        for (int j = i + 1; j <= A.size(); j++) {
          C.push_back('z');

          if (j == A.size() || A[j] != 'z') {
            cout << C << endl;
            return 0;
          }
        }

        cout << C << endl;
        return 1;
      }

      cout << C << endl;
      return 0;
    }

    C.push_back(A[i]);
  }

  C.push_back('a');
  cout << (C == B ? "-1" : C) << endl;
  return 0;
}
