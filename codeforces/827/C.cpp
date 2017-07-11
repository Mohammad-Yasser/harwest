#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << ' ' << x << endl;

typedef long long Long;

const int N = 1e5 + 5;
const int SqrtN = sqrt(N) + 2;
const int E = 11;

const string DNA("ATGC");
string s;

struct Block {
  int cnt[E][E][4];
  Block() {
    memset(cnt, 0, sizeof cnt);
  }
} blocks[SqrtN];

void add(int ind, char c, int val = 1) {
  int block_id = ind / SqrtN;
  for (int j = 1; j < E; ++j) {
    blocks[block_id].cnt[j][ind % j][c] += val;
  }
}

int query(int l, int r, char c, int length, int rem) {
  if (l > r) return 0;

  int start_block_id = l / SqrtN;
  int end_block_id = r / SqrtN;

  int res = 0;

  for (int block_id = start_block_id + 1; block_id < end_block_id; ++block_id) {
    res += blocks[block_id].cnt[length][rem][c];
  }

  while (l / SqrtN == start_block_id && l <= r) {
    res += (s[l] == c && l % length == rem);
    ++l;
  }

  if (start_block_id < end_block_id) {
    while (r / SqrtN == end_block_id) {
      res += (s[r] == c && r % length == rem);
      --r;
    }
  }

  return res;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  cin >> s;

  for (char& c : s) {
    c = DNA.find(c);
  }

  for (int i = 0; i < s.size(); ++i) {
    add(i, s[i]);
  }

  int q;
  cin >> q;

  while (q--) {
    int type;
    cin >> type;

    if (type == 1) {
      int x;
      char c;

      cin >> x >> c;
      --x;

      c = DNA.find(c);

      add(x, s[x], -1);
      s[x] = c;
      add(x, s[x], 1);

    } else {
      int l, r;
      string tmp;
      cin >> l >> r >> tmp;
      --l, --r;

      int res = 0;
      for (int i = 0; i < tmp.size(); ++i) {
        res += query(l, r, DNA.find(tmp[i]), tmp.size(), (i + l) % tmp.size());
      }
      cout << res << '\n';
    }
  }

  return 0;
}
