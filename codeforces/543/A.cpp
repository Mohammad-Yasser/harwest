// Not My Code
// ya rab
#include <bits/stdc++.h>
#include <ext/hash_map>

using namespace std;
using namespace __gnu_cxx;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REV(i,b,a) for(int i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back
#define oo (1<<30)
#define sz(v) (int)v.size()
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define mem(s,v) memset(s,v,sizeof(s))
#define ppc(x) __builtin_popcount((x))
#define iter(it,s) for(__typeof(s.begin())it = s.begin();it!=s.end();it++)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int n, a[505], md;
int memo[2][505][505];
int B, M;
int rec(int i, int b, int m) {
  if (b > B)
    return 0;
  if (m == M)
    return 1;
  if (i == n)
    return 0;
  int &res = memo[i][b][m];
  if (res != -1)
    return res;
  res = 0;
  res += rec(i, b + a[i], m + 1) % md;
  res += rec(i + 1, b, m) % md;
  res %= md;
  return res;
}

int bt() {
  for (int i = n - 1; i >= 0; i--) {
    for (int m = M; m >= 0; m--)
    for (int b = B; b >= 0; b--) {
      {
        int &res = memo[i % 2][b][m];
        if (m == M) {
          res = 1;
          continue;
        }
        res =  memo[(i + 1) % 2][b][m];
        if (b + a[i] <= B)
          (res += memo[i % 2][b + a[i]][m + 1]) %= md;
      }
    }
  }
  return memo[0][0][0];
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.in", "rt", stdin);
//  freopen("o.txt", "wt", stdout);
#endif
  ios::sync_with_stdio(false);
  cin >> n >> M >> B >> md;
  FOR (i , 0 , n)
    cin >> a[i];
  cout << bt() << endl;
  return 0;
}