#include <bits/stdc++.h>

using namespace std;

typedef long long Long;

const int N = 2e5 + 5;
const int END = N - 1;

int a[N];

pair<int, int> nxt[N];
vector<int> children[N];

Long dist[N];

int n;

pair<int, int> getNext(int i) {
  int x = i;
  int y = 0;
  for (int k = 0; k < 2; ++k) {
    y += a[x];
    x = x - a[x] * (2 * k - 1);
    if (x <= 0 || x > n) {
      return {END , y};
    }
  }
  return {x , y};
}

void buildNext() {
  for (int i = 2; i <= n; ++i) {
    nxt[i] = getNext(i);
    children[nxt[i].first].push_back(i);
  }
}

void buildDist(int x = END) {
  for (int v : children[x]) {
    dist[v] = nxt[v].second + dist[x];
    buildDist(v);
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  cin >> n;
  for (int i = 2; i <= n; ++i) {
    cin >> a[i];
  }

  buildNext();
  memset(dist, -1, sizeof dist);
  dist[END] = 0;
  buildDist();

  for (int i = 1; i < n; ++i) {
    a[1] = i;
    auto tmp = getNext(1);
    if (dist[tmp.first] == -1) {
      cout << -1 << '\n';
      continue;
    }
    cout << tmp.second + dist[tmp.first] << '\n';
  }

  return 0;

}
