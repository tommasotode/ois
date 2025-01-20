#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  string S1, S2, S3; cin >> S1 >> S2 >> S3;
  size_t i1 = 0, i2 = 0, i3 = 0;
  string ans = "";

  while (i1 < S1.size() && i2 < S2.size() && i3 < S3.size()) {
    char c = S1[i1];

    if (S2[i2] != c || S3[i3] != c) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }

    array<int, 3> n{1, 1, 1};
    while (S1[++i1] == c) n[0]++;
    while (S2[++i2] == c) n[1]++;
    while (S3[++i3] == c) n[2]++;
    sort(n.begin(), n.end());
    ans += string(n[1], c);
  }

  if (i1 < S1.size() || i2 < S2.size() || i3 < S3.size()) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  cout << ans << endl;
  return 0;
}
