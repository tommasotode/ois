#include <bits/stdc++.h>

using namespace std;

using sii = set<pair<int, int>>;

int perror2(const char* s) {
  perror(s);
  return 2;
}

void send(FILE* s, const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);

  vfprintf(s, fmt, args);
  fputc('\n', s);
  fflush(s);

  va_end(args);
}

#define is_trap(x, y) traps.find({x, y}) != traps.end()

#define stop(s, r) do {    \
  send(pos, "-1 -1"); \
  cout << s << endl;       \
  return r;                \
} while (0)

void print_field(sii& traps, int gx, int gy) {
  int x1 = max(gx - 100, 0), x2 = gx + 150;
  int y1 = max(gy - 15, 0), y2 = gy + 35;

  cout << y2 << '\n';
  for (int y = y2; y >= y1; y--) {
    cout << "   ";
    for (int x = x1; x <= x2; x++) {
      bool trap = is_trap(x, y), g = x == gx && y == gy;
      cout << (g && trap ? 'O' : trap ? '#' : g ? '+' : '.');
    }
    cout << '\n';
  }
  cout << y1 << "\n   " << x1 << string(x2 - x1, ' ') << x2 << endl;
}

bool move(int N, int i, sii& traps, int& gx, int& gy) {
  int dur = 499 * (N + 1) / N / N;
  double f = (double) i / dur * 1.3;
  cout << f << endl;
  int b = (int) (f * N * 1);
  for (int j = 0; j < N; j++) {
    if (j < b) gx++;
    else gy++;

    if (is_trap(gx, gy)) return true;
  }

  return false;
}

int main() {
  int g[2], t[2];
  if (pipe(g) < 0) return perror2("Grasshopper pipe");
  if (pipe(t) < 0) return perror2("Trap pipe");

  pid_t p = fork();
  if (p < 0) perror2("fork");

  if (p == 0) {
    if (close(g[1]) < 0) return perror2("close grasshopper write");
    if (close(t[0]) < 0) return perror2("close trap read");
    if (dup2(g[0], STDIN_FILENO) < 0) return perror2("dup2 grasshopper stdin");
    if (dup2(t[1], STDOUT_FILENO) < 0) return perror2("dup2 trap stdout");
    if (close(g[0]) < 0) return perror2("close grasshopper read");
    if (close(t[1]) < 0) return perror2("close trap write");

    execl("./gh", "./gh", nullptr);
    return perror2("execl");
  }

  int N; cin >> N;

  if (close(g[0]) < 0) return perror2("close grasshopper read");
  if (close(t[1]) < 0) return perror2("close trap write");
  if (dup2(t[0], STDIN_FILENO) < 0) return perror2("dup2 trap stdin");
  if (close(t[0]) < 0) return perror2("close grasshopper write");

  FILE* pos = fdopen(g[1], "w");
  send(pos, "%i", N);
  srand((unsigned int) time(nullptr));

  int gx = 0, gy = 0;
  sii traps;

  for (int i = 0; i < 500; i++) {
    int tx, ty; cin >> tx >> ty;
    if (tx == gx && ty == gy) stop("Output error: trap placed on the grasshopper", 1);
    if (is_trap(tx, ty)) stop("Output error: trap already placed", 1);

    traps.insert({tx, ty});
    bool caught = move(N, i, traps, gx, gy);
    print_field(traps, gx, gy);

    this_thread::sleep_for(chrono::milliseconds(50));
    if (caught) stop("The grasshopper was caught!", 0);

    send(pos, "%i %i", gx, gy);
  }

  stop("Output error: placed > 500 traps", 1);
}
