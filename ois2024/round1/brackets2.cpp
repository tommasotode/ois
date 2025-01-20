#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  vector<int> sums(N + 1);
  partial_sum(A.begin(), A.end(), sums.begin() + 1);

  int M = sums[N];
  vector<vector<char>> m(N + 1, vector<char>(M + 1));
  m[N][0] = 'E';

  for (int i = N - 1; i >= 0; i--) {
    for (int d = 0; d <= sums[i]; d++) {
      m[i][d] = d >= A[i] && m[i + 1][d - A[i]] != '\0' ? ')'
              : m[i + 1][d + A[i]] != '\0' ? '('
              : '\0';
    }
  }

  if (m[0][0] == '\0') {
    cout << "-1" << endl;
    return 0;
  }

  int d = 0;
  for (int i = 0; i < N; i++) {
    cout << string(A[i], m[i][d]);
    d += A[i] * ((m[i][d] == '(') * 2 - 1);
  }

  cout << endl;
  return 0;
}
