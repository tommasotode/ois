#include <bits/stdc++.h>

using namespace std;

#define try_place(c, i) if (c && (i) % (N + 1) != 0 && !t[i]) { \
  cout << (i) << ' ' << (len - 1 - (i)) << endl;                \
  t[i] = true;                                                  \
  break;                                                        \
}

int main() {
  int N; cin >> N;
  int gx = 0, gy = 0;

  if (N == 1) {
    cout << "1 1" << endl;
    cin >> gx >> gy;

    cout << (gx * 2) << ' ' << (gy * 2) << endl;
    cin >> gx >> gy;

    if (gx != -1 || gy != -1) throw exception();
    return 0;
  }

  int dur = 499 * (N + 1) / N / N;
  int len = dur * N + 1;
  vector<bool> t(len);
  vector<int> last;

  for (int i = 0; ; i++) {
    if (i == dur - 1) {
      int h = (gx + N) / (N + 1) * (N + 1);
      cout << h << ' ' << (len - 1 - h) << endl;
    } else {
      int d = len - 1 - gx - gy;
      int s = gx + d / 2;

      last.push_back(s);
      if (last.size() > 3) last.erase(last.begin());

      for (int x : last) cerr << x << ' ';
      cerr << endl;

      s = min(max(s + (s - last.front()) * (dur - i) / (int) last.size(), 0), len - 1);

      if (d % 2 == 0) {
        for (int m = 0; m < len; m++) {
          try_place(m <= s, s - m)
          try_place(m < len - s, s + m)
        }
      } else {
        for (int m = 0; m < len; m++) {
          try_place(m <= s, s - m)
          try_place(m < len - 1 - s, s + 1 + m)
        }
      }
    }

    cin >> gx >> gy;
    if (gx == -1 && gy == -1) break;
  }

  return 0;
}
