#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef unsigned long long ULong;

const int N = 3e5 + 5;
const int Lg = 31;

Long sum[Lg];
multiset<int> ms;

int getBlock(int x) {
  int res = 0;
  while (x >= (1 << (res + 1))) {
    ++res;
  }
  return res;
}

void update(int x, bool add) {
  int val = 2 * add - 1;
  int block_id = getBlock(x);

  sum[block_id] += val * x;

  if (add) {
    ms.insert(x);
  } else {
    ms.erase(ms.find(x));
  }
}

int calc() {
  if (ms.empty()) return 0;

  Long curr_sum = 0;
  int res = (int) ms.size() - 1;

  for (int i = 0; i + 1 < Lg; ++i) {
    curr_sum += sum[i];
    if (curr_sum == 0) continue;
    auto it = ms.lower_bound(1LL << (i + 1));
    if (it == ms.end()) break;
    int nxt = *it;
    if (nxt >= (1LL << (i + 2))) continue;
    if (nxt > 2 * curr_sum) {
      --res;
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int q;
  cin >> q;

  while (q--) {
    char c;
    int x;
    cin >> c >> x;
    update(x, c == '+');
    cout << calc() << endl;
  }

}
