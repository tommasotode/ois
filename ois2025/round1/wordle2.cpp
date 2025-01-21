#include <bits/stdc++.h>
using namespace std;

void attempt1(string s, unordered_set<char>& found) {
  cout << "? " << s << endl;
  string response; cin >> response;
  for (int i = 0; i < 5; i++) {
    if (response[i] != 'W') found.insert(s[i]);
  }
}

void attempt2(char c, string& answer) {
  cout << "? " << string(5, c) << endl;
  string response; cin >> response;
  for (int i = 0; i < 5; i++) {
    if (response[i] == 'G') answer[i] = c;
  }
}

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    unordered_set<char> found;
    attempt1("abcde", found);
    if (found.size() < 5) attempt1("fghij", found);
    if (found.size() < 5) attempt1("klmno", found);
    if (found.size() < 5) attempt1("pqrst", found);
    if (found.size() < 5) attempt1("uvwxy", found);

    auto it = found.begin();
    string answer(5, found.size() == 5 ? *it : 'z');
    if (found.size() == 5) it++;
    for (; it != found.end(); it++) attempt2(*it, answer);
    cout << "! " << answer << endl;
  }

  return 0;
}
