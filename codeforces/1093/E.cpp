#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef unsigned long long ULong;

const int N = 2e5 + 5;
const int BlockSize = 1770;
const int BlockCnt = N / BlockSize + 1;

struct Block {
  int start = N, end = 0;
  vector<int> elements;

  void add(int x) {
    auto it = lower_bound(elements.begin(), elements.end(), x);
    elements.insert(it, x);
  }

  void remove(int x) {
    auto it = lower_bound(elements.begin(), elements.end(), x);
    elements.erase(it);
  }

  int countLessThanOrEqual(int x) {
    auto it = upper_bound(elements.begin(), elements.end(), x);
    return it - elements.begin();
  }

} blocks[BlockCnt];

int a[N];
int b[N];
int pos_in_a[N];
int n;

void build() {
  for (int i = 1; i <= n; ++i) {
    blocks[i / BlockSize].add(b[i]);
    if (blocks[i / BlockSize].start == N) {
      blocks[i / BlockSize].start = i;
    }
    blocks[i / BlockSize].end = i;
  }
}

int query(int ra, int rb) {
  int res = 0;
  for (int i = 0; i < BlockCnt; ++i) {
    auto& block = blocks[i];
    if (block.end <= rb) {
      res += block.countLessThanOrEqual(ra);
    } else {
      for (int j = block.start; j <= rb; ++j) {
        res += (b[j] <= ra);
      }
    }
  }
  return res;
}

int f(int la, int ra, int lb, int rb) {
  if (la == 1 && lb == 1) {
    return query(ra, rb);
  }
  return f(1, ra, 1, rb) - f(1, ra, 1, lb - 1) - f(1, la - 1, 1, rb)
    + f(1, la - 1, 1, lb - 1);
}

void update(int x, int y) {
  blocks[x / BlockSize].add(b[y]);
  blocks[x / BlockSize].remove(b[x]);

  blocks[y / BlockSize].add(b[x]);
  blocks[y / BlockSize].remove(b[y]);

  swap(b[x], b[y]);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int m;
  cin >> n >> m;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    pos_in_a[a[i]] = i;
  }

  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
    b[i] = pos_in_a[b[i]];
  }

  build();

  while (m--) {
    int type;
    cin >> type;

    if (type == 1) {
      int la, ra, lb, rb;
      cin >> la >> ra >> lb >> rb;
      cout << f(la, ra, lb, rb) << endl;
    } else {
      int x, y;
      cin >> x >> y;
      update(x, y);
    }
  }

}