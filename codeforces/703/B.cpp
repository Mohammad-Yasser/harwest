#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
bool cap[N];
int c[N];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  int k;
  cin >> k;
  long long sum = 0, sumcap = 0;
  for (int i = 0; i < n; ++i) cin >> c[i], sum += c[i];
  long long res = 0;
  for (int i = 0; i < k; ++i) {
    int tmp;
    cin >> tmp;
    cap[--tmp] = 1;
  }

  for (int i = 0; i < n; ++i) {
    if (cap[i])
      sumcap += c[i], res += (sum - sumcap) * c[i];
    else if (!cap[(i + 1) % n])
      res += c[i] * c[(i + 1) % n];
  }
  cout << res;
}
