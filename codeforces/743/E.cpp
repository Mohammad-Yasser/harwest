#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

const int N = 1003;
const int K = 8;
const int OO = N;

int memo[N][N / 8 + 1][1 << K];
bool vis[N][N / 8 + 1][1 << K];

vector<int> occurrences[K];
int pos[N];
int arr[N];

int n;

int Solve(int ind, int k, int mask) {
  if (mask == (1 << K) - 1) {
    return 0;
  }
  if (ind == n) {
    return -OO;
  }

  int &ret = memo[ind][k][mask];
  if (vis[ind][k][mask]) {
    return ret;
  }
  vis[ind][k][mask] = true;

  ret = Solve(ind + 1, k, mask);

  for (int j = k; j < k + 2 && ((mask >> arr[ind]) & 1) == 0; ++j) {
    if (occurrences[arr[ind]].size() > pos[ind] + j - 1) {
      ret = max(ret,
        j
          + Solve(occurrences[arr[ind]][pos[ind] + j - 1] + 1, k,
            mask | (1 << arr[ind])));
    }
  }


  return ret;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif

  cin >> n;
  set<int> st;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    --arr[i];
    st.insert(arr[i]);
    pos[i] = occurrences[arr[i]].size();
    occurrences[arr[i]].push_back(i);
  }

  int res = st.size();
  for (int k = 1; k <= N / 8 + 1; ++k) {
    res = max(res, Solve(0, k, 0));
  }

  cout << res;
}
