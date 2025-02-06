#include <bits/stdc++.h>
using namespace std;

int dist_sq(int x1, int y1, int x2, int y2) {
  int dx = x1 - x2, dy = y1 - y2;
  return dx * dx + dy * dy;
}

int main() {
  int x1, y2; cin >> x1 >> y2;
  int _; cin >> _ >> _;
  int x2, y1; cin >> x2 >> y1;
  cin >> _ >> _;

  x1 <<= 1; y1 <<= 1; x2 <<= 1; y2 <<= 1;
  int xm = (x1 + x2) / 2, ym = (y1 + y2) / 2;
  int rad_sqx = (x1 - x2) / 2; rad_sqx *= rad_sqx;
  int rad_sqy = (y1 - y2) / 2; rad_sqy *= rad_sqy;

  int N; cin >> N;
  int K = 0;

  for (int i = 0; i < N; i++) {
    int x, y; cin >> x >> y;
    x <<= 1; y <<= 1;
    int a = 0, o = 0;
  
    int d = dist_sq(x, y, xm, y1);
    if (d > rad_sqx) a++;
    else if (d < rad_sqx) o++;

    d = dist_sq(x, y, x2, ym);
    if (d > rad_sqy) a++;
    else if (d < rad_sqy) o++;

    d = dist_sq(x, y, xm, y2);
    if (d > rad_sqx) a++;
    else if (d < rad_sqx) o++;

    d = dist_sq(x, y, x1, ym);
    if (d > rad_sqy) a++;
    else if (d < rad_sqy) o++;

    K += a == 2 && o == 2;
  }

  cout << K << endl;
  return 0;
}
