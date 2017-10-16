#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef long double Double;

const int N = 2e5 + 5;
const int MaxLog = log2(N) + 5;

int arr[N];
int first[N];
int ans[N];
int n;

int Log[N];
int sparse_table[N][MaxLog];

int combine(int a, int b) {
  return a | b;
}

void buildSparseTable() {
  int cnt = -1;
  for (int i = 0; i < n; i++) {
    if (!((i + 1) & i)) cnt++;
    sparse_table[i][0] = arr[i];
    Log[i + 1] = cnt;
  }
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 0; (i + (1 << j)) <= n; i++) {
      int a = sparse_table[i][j - 1];
      int b = sparse_table[i + (1 << (j - 1))][j - 1];
      sparse_table[i][j] = combine(a, b);
    }
  }
}

int getOr(int st, int en) {
  if (st > en) swap(st, en);
  int L = Log[en - st + 1];
  int a = sparse_table[st][L], b = sparse_table[en - (1 << L) + 1][L];
  return combine(a, b);
}

bool valid(int ind) {
  return ind >= 0 && ind < n;
}

int getFirst(int ind, int dir) {
  int low = 0, high = n + 1, mid, ans;
  while (low <= high) {
    mid = (low + high) / 2;
    int j = ind + mid * dir;

    if (valid(j) && getOr(ind, j) == arr[ind]) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return ans;
}

unordered_map<int, int> last_occ;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  Long res = 1LL * n * (n - 1) / 2;

  buildSparseTable();

  for (int i = 0; i < n; ++i) {
    int right = getFirst(i, 1) + 1;
    int left = getFirst(i, -1);

    if (last_occ.count(arr[i])) {
      left = min(left, i - (last_occ[arr[i]] + 1));
    }

    ++left;

    last_occ[arr[i]] = i;


    res -= 1LL * right * left - 1;
  }

  cout << res;

  return 0;
}
