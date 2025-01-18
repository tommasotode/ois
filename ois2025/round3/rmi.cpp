#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int A, B, N; cin >> A >> B >> N;
  vector<int> F(N), S(N);
  for (int i = 0; i < N; i++) cin >> F[i];
  for (int i = 0; i < N; i++) cin >> S[i];

  int T = A + B;
  sort(F.begin(), F.end(), greater());
  sort(S.begin(), S.end());

  int X = N + 1;
  for (int f = 0, s = 0; f < N && s < N; f++) {
    if (F[f] + S[s] <= T) {
      X--; s++;
    }
  }

  int Y = 1;
  for (int f = 0, s = 0; f < N && s < N; s++) {
    if (F[f] + S[s] > T) {
      Y++; f++;
    }
  }

  cout << X << ' ' << Y << endl;
  return 0;
}
