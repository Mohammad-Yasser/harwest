#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

//ax+by=gcd(a,b)
int eGCD(int a, int b, int &x, int &y) {
  x = 1;
  y = 0;
  int nx = 0, ny = 1;
  int t, r;
  while (b) {
    r = a / b;
    t = a - r * b;
    a = b;
    b = t;
    t = x - r * nx;
    x = nx;
    nx = t;
    t = y - r * ny;
    y = ny;
    ny = t;
  }
  return a;
}

//(a*mi)%m=1
int modInv(int a, int m) {
  int mi, r;
  eGCD(a, m, mi, r);
  return (mi + m) % m;
}

bool forbidden[N];

vector<int> comp[N];

int nxt[N];
int max_seq[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    forbidden[x] = true;
  }

  for (int i = 1; i < m; ++i) {
    if (forbidden[i]) continue;
    comp[__gcd(i, m)].push_back(i);
  }

  for (int i = m - 1; i > 0; --i) {
    if (m % i != 0) continue;
    for (int j = 2 * i; j < m; j += i) {
      if (m % j != 0) continue;
      if (max_seq[j] > max_seq[nxt[i]]) {
        nxt[i] = j;
      }
    }
    max_seq[i] = max_seq[nxt[i]] + comp[i].size();
  }

  vector<int> prods;

  for (int i = 1; i != 0; i = nxt[i]) {
    for (int x : comp[i]) {
      prods.push_back(x);
    }
  }

  int curr_prod = 1;

  cout << prods.size() + !forbidden[0] << '\n';

  for (int p : prods) {
    int x = 1LL
      * modInv(curr_prod / __gcd(m, curr_prod), m / __gcd(m, curr_prod))
      * (p / __gcd(m, curr_prod)) % (m / __gcd(m, curr_prod));
    cout << x << ' ';
    curr_prod = p;
  }

  if (!forbidden[0]) {
    cout << 0;
  }

  return 0;
}
