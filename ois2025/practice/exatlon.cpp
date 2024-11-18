#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int N; cin >> N; cin.ignore();
  vector<string> board(N);
  for (int i = 0; i < N; i++) getline(cin, board[i]);

  int best_r = 0, best_b = 0;
  for (int first_col = 0; first_col < N; first_col++) {
    vector<int> r, b;
    for (int row = 0; row < N; row++) {
      bool red = board[row][first_col] == 'R';
      (red ? r : b).push_back((int) min(board[row].find(red ? 'A' : 'R', first_col), (size_t) N) - first_col);
    }

    sort(r.begin(), r.end()); sort(b.begin(), b.end());
    for (size_t i = 0; i < r.size(); i++) best_r = max(best_r, r[i] * int(r.size() - i));
    for (size_t i = 0; i < b.size(); i++) best_b = max(best_b, b[i] * int(b.size() - i));
  }

  if (best_r > best_b) cout << "1 " << best_r << endl;
  else if (best_r < best_b) cout << "2 " << best_b << endl;
  else cout << "0 " << best_r << endl;

  return 0;
}
