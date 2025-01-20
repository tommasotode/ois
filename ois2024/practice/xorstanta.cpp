#include <iostream>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int T; cin >> T;

  for (int i = 0; i < T; i++) {
    int N; cin >> N;

    int xAll = 0;
    for (int n = N / 4 * 4; n <= N; n++) xAll ^= n;

    int xA = 2;
    while (N >>= 1) xA <<= 1;
    xA--;

    cout << xA + (xAll ^ xA) << endl;
  }

  return 0;
}
