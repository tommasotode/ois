#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int N, K; cin >> N >> K; K--;
  vector<int> V(N);
  for (int i = 0; i < N; i++) cin >> V[i];

  vector<bool> visited(N);
  int curr = 0;
  int c;

  for (c = 0; curr != K; c++) {
    if (visited[curr]) {
      cout << "-1" << endl;
      return 0;
    }

    visited[curr] = true;
    curr = V[curr] - 1;
  }

  cout << c << endl;
  return 0;
}
