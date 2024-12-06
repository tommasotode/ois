#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int N; cin >> N;
  vector<long long> H(N);
  for (int i = 0; i < N; i++) cin >> H[i];

  vector<double> h(H.begin(), H.end());
  for (int i = 0; i < N; i++) {
    int m = i - 1;
    for (int j = i - 2; j >= 0; j--) {
      double mh = double((H[m] - H[i]) * (i - j)) / (i - m) + (double) H[i];
      if ((double) H[j] >= mh) m = j;
      else if (mh > h[j]) h[j] = mh;
    }

    m = i + 1;
    for (int j = i + 2; j < N; j++) {
      double mh = double((H[m] - H[i]) * (j - i)) / (m - i) + (double) H[i];
      if ((double) H[j] >= mh) m = j;
      else if (mh > h[j]) h[j] = mh;
    }
  }

  for (int i = 0; i < N; i++) cout << ((long long) ceil(h[i]) - H[i]) << ' ';
  cout << endl;
  return 0;
}
