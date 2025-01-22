#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

void place_mask(vector<vi>& tiling, int base_x, int base_y, int base_id, vector<string> mask) {
  for (size_t off_y = 0; off_y < mask.size(); off_y++) {
    for (size_t off_x = 0; off_x < mask[off_y].size(); off_x++) {
      if (mask[off_y][off_x] != ' ') tiling[base_y + off_y][base_x + off_x] = base_id + mask[off_y][off_x] - 'A';
    }
  }
}

int main() {
  int N; cin >> N;
  vector<vi> tiling(N, vi(N));

  int base_x = 0;
  int base_y = 0;
  int id = 1;
  int size = N;

  while (true) {
    if (size <= 2) break;

    if (size == 3) {
      tiling[base_y][base_x] = id;
      tiling[base_y][base_x + 1] = id;
      tiling[base_y][base_x + 2] = id;
      tiling[base_y + 1][base_x + 1] = id;
      id++;
      break;
    }

    if (size == 5) {
      place_mask(tiling, base_x, base_y, id, {
        "ABBBC",
        "AABCC",
        "AD CE",
        "DDFEE",
        "DFFFE"
      });
      id += 6;
      break;
    }

    if (size == 7) {
      place_mask(tiling, base_x, base_y, id, {
        " ABCCCD",
        "AABBCDD",
        "AEEBFGD",
        "EEHFFGG",
        "IHHHFGJ",
        "IIKKLJJ",
        "IKKLLLJ"
      });
      id += 12;
      break;
    }

    if (size == 10) {
      place_mask(tiling, base_x, base_y, id, {
        "AAABBCDDDE",
        "FABBCCGDEE",
        "FFHIICGGJE",
        "FHHKIILGJJ",
        "MMHKKLLNJO",
        "PMMQKLNNOO",
        "PPQQRRSNTO",
        "PUQRRSSVTT",
        "UUWWXSVVYT",
        "UWWXXXVYYY"
      });
      id += 25;
      break;
    }

    int s = (size - 1) / 2;

    tiling[base_y][base_x] = id;
    tiling[base_y][base_x + 1] = id;
    tiling[base_y][base_x + 2] = id;
    tiling[base_y + 1][base_x + 1] = id;
    for (int i = 1; i < s; i++) {
      tiling[base_y + 1][base_x + i * 2] = id + i;
      tiling[base_y + 1][base_x + i * 2 + 1] = id + i;
      tiling[base_y][base_x + i * 2 + 1] = id + i;
      tiling[base_y][base_x + i * 2 + 2] = id + i;
    }
    id += s;

    int end_x = base_x + size - 1, end_y = base_y + size - 1;
    tiling[end_y][end_x] = id;
    tiling[end_y][end_x - 1] = id;
    tiling[end_y][end_x - 2] = id;
    tiling[end_y - 1][end_x - 1] = id;
    for (int i = 1; i < s; i++) {
      tiling[end_y - 1][end_x - i * 2] = id + i;
      tiling[end_y - 1][end_x - i * 2 - 1] = id + i;
      tiling[end_y][end_x - i * 2 - 1] = id + i;
      tiling[end_y][end_x - i * 2 - 2] = id + i;
    }
    id += s;

    s = size / 2 - 1;

    int adjusted_y = base_y + size % 2;
    tiling[adjusted_y][end_x] = id;
    tiling[adjusted_y + 1][end_x] = id;
    tiling[adjusted_y + 2][end_x] = id;
    tiling[adjusted_y + 1][end_x - 1] = id;
    for (int i = 1; i < s; i++) {
      tiling[adjusted_y + i * 2][end_x - 1] = id + i;
      tiling[adjusted_y + i * 2 + 1][end_x - 1] = id + i;
      tiling[adjusted_y + i * 2 + 1][end_x] = id + i;
      tiling[adjusted_y + i * 2 + 2][end_x] = id + i;
    }
    id += s;

    end_y -= size % 2;
    tiling[end_y][base_x] = id;
    tiling[end_y - 1][base_x] = id;
    tiling[end_y - 2][base_x] = id;
    tiling[end_y - 1][base_x + 1] = id;
    for (int i = 1; i < s; i++) {
      tiling[end_y - i * 2][base_x + 1] = id + i;
      tiling[end_y - i * 2 - 1][base_x + 1] = id + i;
      tiling[end_y - i * 2 - 1][base_x] = id + i;
      tiling[end_y - i * 2 - 2][base_x] = id + i;
    }
    id += s;

    base_x += 2;
    base_y += 2;
    size -= 4;
  }

  cout << id - 1 << endl;
  for (int j = 0; j < N; j++) {
    for (int i = 0; i < N; i++) cout << tiling[j][i] << ' ';
    cout << endl;
  }

  return 0;
}
