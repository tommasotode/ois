#include <bits/stdc++.h>
using namespace std;

struct node {
  float value;
  int left;
  bool operator<(const node& o) const { return value < o.value; }
};

int find_pool(int N, int M, int P, vector<int> A, vector<int> B) {
  vector<node> nodes(N);
  nodes[0].value = 1;

  vector<list<int>> adj(N);
  for (int i = 0; i < M; i++) {
    adj[A[i]].push_back(B[i]);
    nodes[B[i]].left++;
  }

  queue<int> q({0});
  while (!q.empty()) {
    int currI = q.front(); q.pop();
    node& curr = nodes[currI];
    float split = curr.value / (float) adj[currI].size();

    for (int nextI : adj[currI]) {
      node& next = nodes[nextI];
      next.value += split;
      if (--next.left == 0) q.push(nextI);
    }
  }

  return int(max_element(nodes.begin() + (N - P), nodes.end()) - nodes.begin());
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int N, M, P; cin >> N >> M >> P;
  vector<int> A(M), B(M);
  for (int i = 0; i < M; i++) cin >> A[i] >> B[i];

  cout << find_pool(N, M, P, A, B) << endl;
  return 0;
}
