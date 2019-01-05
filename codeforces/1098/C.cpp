#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef unsigned long long ULong;

const int N = 3e5 + 5;

Long getMinS(int n, int branch) {
  Long last = 1;
  Long res = 1;
  int level = 1;
  --n;
  while (last * branch <= n) {
    ++level;
    last *= branch;
    n -= last;
    res += last * level;
  }
  res += n * (level + 1);
  return res;
}

int getMinBranch(int n, Long s) {
  int low = 1, high = N - 1, mid, ans = N;
  while (low <= high) {
    mid = (low + high) / 2;
    if (getMinS(n, mid) <= s) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return ans;
}

int cnt_level[N];
int max_in_level[N];

int parent[N];

void buildTree(int n, Long s, int branch) {
  max_in_level[1] = 1;
  for (int i = 1; i <= n; ++i) {
    if (i > 1) max_in_level[i] = min(N, branch * max_in_level[i - 1]);
    ++cnt_level[i];
    s -= i;
  }

  int last_level = 1;
  for (int i = n; s < 0; --i) {
    if (cnt_level[last_level] == max_in_level[last_level]) {
      ++last_level;
    }

    int tmp = i - last_level;
    if (s + tmp <= 0) {
      s += tmp;
      ++cnt_level[last_level];
      --cnt_level[i];
    } else {
      ++cnt_level[i + s];
      --cnt_level[i];
      s = 0;
    }
  }

  int nxt_node = 2;
  int level_begin = 1;

  for (int level = 2; nxt_node <= n; ++level) {
    int nxt_begin = nxt_node;
    for (int i = 0; i < cnt_level[level]; ++i) {
      parent[nxt_node++] = level_begin + i / branch;
    }
    level_begin = nxt_begin;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  Long n, s;
  cin >> n >> s;

  if (1LL * n * (n + 1) / 2 < s) {
    cout << "No";
    return 0;
  }

  if (2 * n - 1 > s) {
    cout << "No";
    return 0;
  }

  cout << "Yes" << endl;

  int branch = getMinBranch(n, s);
  buildTree(n, s, branch);
  for (int i = 2; i <= n; ++i) {
    cout << parent[i] << " ";
  }
}
