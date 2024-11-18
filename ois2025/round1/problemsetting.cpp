#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int N; cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<int> B(N - 1);
    for (int i = 0; i < N - 1; i++) cin >> B[i];

    vector<int> indexes(N - 1);
    for (int i = 0; i < N - 1; i++) indexes[i] = i;
    sort(indexes.begin(), indexes.end(), [&B](int i, int j) {
      return B[i] > B[j];
    });

    for (int i : indexes) {
      int d = A[i] - A[i + 1];
      if (d > 0) {
        int add = min(d, B[i]);
        A[i + 1] += add;
        B[i] -= add;
      } else if (d < 0) {
        int add = min(-d, B[i]);
        A[i] += add;
        B[i] -= add;
      }

      int add = B[i] / 2;
      A[i] += add;
      A[i + 1] += add;
      B[i] -= add * 2;
    }

    while (true) {
      bool assigned = false;

      for (int i = 0; i < N - 1; i++) {
        if (B[i] == 0) continue;

        if (A[i] > A[i + 1]) {
          A[i + 1]++;
          B[i]--;
          assigned = true;
        } else if (A[i] < A[i + 1]) {
          A[i]++;
          B[i]--;
          assigned = true;
        }
      }

      if (!assigned) break;
    }

    cout << *min_element(A.begin(), A.end()) << endl;
  }

  return 0;
}
