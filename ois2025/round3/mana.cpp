#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int N, K; cin >> N >> K;
  vector<int> C(N);
  for (int i = 0; i < N; i++) cin >> C[i];

  if (K < N) {
    cout << (accumulate(C.begin(), C.begin() + (K + 1), 0ll) - *max_element(C.begin(), C.begin() + (K + 1))) << endl;
    return 0;
  }

  long long s = (accumulate(C.begin(), C.end(), 0ll) - *max_element(C.begin(), C.end())) * (K / (N - 1));
  int mn = min(C[0], C[1]), mx = max(C[0], C[1]);
  queue<int> C2;
  for (int c : C) C2.push(c);
  C2.pop(); C2.pop();

  long long c = 0;
  for (int i = 0; i < N - 1; i++) {
    c += mn;
    int m = C2.front(); C2.pop();
    C2.push(mn);

    if (m < mx) mn = m;
    else {
      mn = mx;
      mx = m;
    }
  }

  if (K % (N - 1) == 0) {
    cout << s << endl;
    return 0;
  }

  s += mn;
  for (int i = 0; i < K % (N - 1) - 1; i++) {
    s += C2.front(); C2.pop();
  }

  cout << s << endl;
  return 0;
}
