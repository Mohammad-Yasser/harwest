#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

const int N = 1003;
const int K = 8;
const int OO = N;

int memo[N][1 << K];
bool vis[N][1 << K];

vector<int> occurrences[K];
int pos[N];
int arr[N];

int n;
int k;

int Solve(int ind, int mask) {
  if (mask == (1 << K) - 1) {
    return 0;
  }
  if (ind == n) {
    return -OO;
  }

  int &ret = memo[ind][mask];
  if (vis[ind][mask]) {
    return ret;
  }
  vis[ind][mask] = true;

  ret = Solve(ind + 1, mask);

  for (int j = k; j < k + 2 && ((mask >> arr[ind]) & 1) == 0; ++j) {
    if (occurrences[arr[ind]].size() > pos[ind] + j - 1) {
      ret = max(ret,
        j
          + Solve(occurrences[arr[ind]][pos[ind] + j - 1] + 1,
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

  int low = 1, high = N / 8, mid;
  while (low <= high) {
    mid = (low + high) / 2;
    memset(vis, false, sizeof vis);
    k = mid;
    int tmp = max(0, Solve(0, 0));
    if (tmp != 0) {
      res = max(res, tmp);
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  cout << res;
}
