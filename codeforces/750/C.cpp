#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200005;
const int kMax = INT_MAX / 2;

pair<int, int> arr[N];

const int kDiv2 = 1899;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif

  int n;
  cin >> n;

  int max_rating = kMax, min_rating = -kMax;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i].first >> arr[i].second;
    sum += arr[i].first;
    if (arr[i].second == 1) {
      min_rating = max(min_rating, kDiv2 + 1);
    } else {
      max_rating = min(max_rating, kDiv2);
    }
    if (max_rating < min_rating) {
      cout << "Impossible\n";
      return 0;
    }

    max_rating += arr[i].first;
    min_rating += arr[i].first;

    max_rating = min(max_rating, kMax);
    min_rating = max(min_rating, -kMax);

    if (max_rating < min_rating) {
      cout << "Impossible\n";
      return 0;
    }

  }

  if (max_rating >= kMax / 2) {
    cout << "Infinity\n";
    return 0;
  }

  cout << max_rating << endl;

}
