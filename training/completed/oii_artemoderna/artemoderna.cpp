#include <vector>

using namespace std;

bool ordina(int N, vector<int> V, vector<int>& L) {
  int l = 0, h = 0;

  for (int r = 1; r <= N; r++) {
    if (r == N || V[r] > V[r - 1]) {
      if (V[r - 1] < h) return false;
      L.push_back(r - l);
      h = V[l];
      l = r;
    }
  }

  return true;
}
