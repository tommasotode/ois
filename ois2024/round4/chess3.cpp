// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool chess3(vector<string>& board);
char raycast(vector<string>& board, int x, int y, int dx, int dy);
bool is_inside(int x, int y);
pair<int, int> findQueen(vector<string>& board);

int main() {
  // uncomment the two following lines if you want to read/write from files
  ifstream cin("input.txt");
  ofstream cout("output.txt");

  int T;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    vector<string> board(8);
    for (int i = 0; i < 8; ++i)
      cin >> board[i];

    cout << (chess3(board) ? "YES" : "NO") << endl;
  }

  return 0;
}

bool chess3(vector<string>& board) {
  auto [qx, qy] = findQueen(board);

  for (int dx = -1; dx <= 1; dx += 2) {
    int px = qx + dx;
    int py = qy + 1;
    if (is_inside(px, py) && board[py][px] == 'P') return true;
  }

  for (int dx = -1; dx <= 1; dx += 2) {
    for (int dy = -1; dy <= 1; dy += 2) {
      char p = raycast(board, qx, qy, dx, dy);
      if (p == 'B' || p == 'Q') return true;
    }
  }

  for (auto [dx, dy] : {make_pair(1, 0), make_pair(0, 1), make_pair(-1, 0), make_pair(0, -1)}) {
    char p = raycast(board, qx, qy, dx, dy);
    if (p == 'R' || p == 'Q') return true;
  }

  for (int mx = -1; mx <= 1; mx += 2) {
    for (int my = -1; my <= 1; my += 2) {
      for (int n = 1; n <= 2; n++) {
        int cx = qx + mx * n;
        int cy = qy + my * (3 - n);
        if (is_inside(cx, cy) && board[cy][cx] == 'N') return true;
      }
    }
  }

  return false;
}

char raycast(vector<string>& board, int x, int y, int dx, int dy) {
  while (true) {
    x += dx;
    y += dy;
    if (!is_inside(x, y)) return '.';

    char piece = board[y][x];
    if (piece != '.') return isupper(piece) ? piece : '.';
  }
}

bool is_inside(int x, int y) {
  return x >= 0 && x < 8 && y >= 0 && y < 8;
}

pair<int, int> findQueen(vector<string>& board) {
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 8; x++) {
      if (board[y][x] == 'q') return {x, y};
    }
  }
}
