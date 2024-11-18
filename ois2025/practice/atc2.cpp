#include <bits/stdc++.h>
using namespace std;

struct node { int x, y; };

int dist_sq(node a, node b) {
  int dx = a.x - b.x, dy = a.y - b.y;
  return dx * dx + dy * dy;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int N; cin >> N;
  string r; getline(cin, r);

  vector<node> m;
  for (int y = 0; y < N; y++) {
    getline(cin, r);
    for (int x = 0; x < N; x++) {
      if (r[x] == 'T') m.push_back({x, y});
    }
  }

  size_t T = m.size();
  unordered_set<size_t> nv;
  vector<int> closest_d(T, INT_MAX);
  for (size_t i = 0; i < T; i++) nv.insert(i);
  closest_d[0] = 0;

  long long t = 0;
  while (!nv.empty()) {
    size_t n = *min_element(nv.begin(), nv.end(), [&closest_d](size_t a, size_t b) {
      return closest_d[a] < closest_d[b];
    });

    nv.erase(n);
    t += closest_d[n];

    for (size_t i = 0; i < T; i++) {
      if (dist_sq(m[n], m[i]) < closest_d[i]) {
        closest_d[i] = dist_sq(m[n], m[i]);
      }
    }
  }

  cout << t << endl;
  return 0;
}
