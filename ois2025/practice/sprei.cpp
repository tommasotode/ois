#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int M;

bool adj(const vi& a, const vi& b) {
  int diff = -1;

  for (int i = 0; i < M; i++) {
    if (a[i] != b[i]) {
      if (diff != -1) return false;

      diff = i;
    }
  }

  return abs(a[diff] - b[diff]) == 1;
}

bool valid(set<vi>& chosen) {
  for (const vi& a : chosen) {
    for (const vi& b : chosen) {
      if (a != b && adj(a, b)) return false;
    }
  }

  return true;
}

size_t sprei(vector<vi>& A, set<vi>& chosen, int N, size_t i) {
  if (i == A.size()) return valid(chosen) ? N - (int) chosen.size() : numeric_limits<size_t>::max();

  size_t best = sprei(A, chosen, N, i + 1);
  chosen.insert(A[i]);
  best = min(best, sprei(A, chosen, N, i + 1));
  chosen.erase(A[i]);
  return best;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int N, B; cin >> N >> M >> B;
  if (N == pow(B, M)) {
    cout << N / 2 << endl;
    return 0;
  }

  vector<vi> A(N, vi(M));
  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) cin >> A[j][i];
  }

  if (M == 1) {
    sort(A.begin(), A.end(), [](vi& a, vi& b) { return a[0] < b[0]; });

    vi blocks{0};
    for (int i = 0; i < N; i++) {
      blocks.back()++;
      if (i < N - 1 && A[i][0] != A[i + 1][0] - 1) blocks.push_back(0);
    }

    int t = 0;
    for (int b : blocks) t += b / 2;
    cout << t << endl;
    return 0;
  }

  if (N > 10) return 1;

  set<vi> chosen;
  cout << sprei(A, chosen, N, 0) << endl;
  return 0;
}
