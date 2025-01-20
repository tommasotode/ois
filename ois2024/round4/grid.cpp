#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int N, M, R, G, B; cin >> N >> M >> R >> G >> B;
  if (B != 0) return 1;

  bool red_first = true;

  if (N % 2 == 1 && M % 2 == 1) {
    if (abs(R - G) != 1) {
      cout << "NO" << endl;
      return 0;
    }

    red_first = R > G;
  } else if (R != G) {
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) cout << ((i + j) % 2 == red_first ? 'G' : 'R');
    cout << endl;
  }

  return 0;
}
