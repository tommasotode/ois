// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main() {
  // uncomment the two following lines if you want to read/write from files
  ifstream cin("input.txt");
  ofstream cout("output.txt");

  int N;
  cin >> N;

  string S;
  cin >> S;

  stack<int> open;
  for (int i = 0; i < N; i++) {
    if (S[i] == '(') open.push(i);
  }

  vector<pair<int, int>> swaps;
  int d = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == '(') {
      d++;
      continue;
    }

    if (--d < 0) {
      int o = open.top();
      open.pop();
      swaps.push_back({i, o});
      S[o] = ')';
      d = 1;
    }
  }

  cout << swaps.size() << '\n';
  for (auto& [left, right] : swaps) cout << left << ' ' << right << '\n';

  return 0;
}
