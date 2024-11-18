#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define sum(v) accumulate(v.begin(), v.end(), 0)

vi best;

void magic(vi& line, int L, int x) {
  if (x == L) {
    if (sum(line) > sum(best)) best = line;
    return;
  }

  if (line[x] > 0) {
    magic(line, L, x + 1);
    return;
  }

  for (int l = min(x, 9); l >= 1; l--) {
    if (line[x - l] % l == 0 || l % line[x - l] == 0) {
      line[x] = l;
      magic(line, L, x + 1);
      line[x] = 0;
    }
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int N, L; cin >> N >> L;

  vi X(N);
  for (int i = 0; i < N; i++) cin >> X[i];

  vi E(N);
  for (int i = 0; i < N; i++) cin >> E[i];

  vi line(L);
  for (int i = 0; i < N; i++) line[X[i]] = E[i];
  magic(line, L, 0);

  for (int i = 0; i < L; i++) cout << best[i] << ' ';
  cout << endl;
  return 0;
}
