#include <bits/stdc++.h>

using namespace std;
using child_list = vector<forward_list<int>>;

struct node_info { int h, mdh; };

void dfs(child_list& cl, int n, int h, vector<node_info>& infos) {
  infos[n].h = infos[n].mdh = h;

  for (int c : cl[n]) {
    dfs(cl, c, h + 1, infos);
    infos[n].mdh = max(infos[n].mdh, infos[c].mdh);
  }
}

int pota(int N, vector<int> P) {
  child_list cl(N);
  for (int n = 1; n < N; n++) cl[P[n]].push_front(n);

  vector<node_info> infos(N);
  dfs(cl, 0, 0, infos);

  vector<int> s(N);
  for (node_info info : infos) {
    s[info.h]++;
    if (info.mdh < N - 1) s[info.mdh + 1]--;
  }

  int c = 0, m = 0;
  for (int d : s) {
    c += d;
    m = max(m, c);
  }

  return N - m;
}
