#include <bits/stdc++.h>
using namespace std;
using vb = vector<bool>;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int N, M; cin >> N >> M;
  if (N > M) {
    cout << "-1" << endl;
    return 0;
  }

  vector<vb> level(N, vb(M));
  level[0][0] = true;
  int x = 0, y = 0;
  for (int i = 0; i < 2 * N - 2; i++) {
    if (i % 2 == 0) x++;
    else y++;
    level[y][x] = true;
  }

  while (++x < M) level[N - 1][x] = true;

  for (int py = 0; py < N; py++) {
    for (int px = 0; px < M; px++) {
      cout << (level[py][px] ? '.' : '#');
    }

    cout << endl;
  }

  return 0;
}
