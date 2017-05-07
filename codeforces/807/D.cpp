#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

const int N = 121;
const int OO = 200;
const int P = 5;

Long curr_cnt[P];
Long stm[N][P];

int n;

int GetMaxScore(Long s, int n) {
  if (2 * s > n) {
    return 500;
  } else if (4 * s > n) {
    return 1000;
  } else if (8 * s > n) {
    return 1500;
  } else if (16 * s > n) {
    return 2000;
  } else if (32 * s > n) {
    return 2500;
  } else {
    return 3000;
  }
}

bool Check(int x) {
  int cnt[P];
  for (int i = 0; i < P; ++i) {
    if (stm[0][i] <= stm[1][i] || stm[0][i] == OO) {
      cnt[i] = curr_cnt[i];
    } else {
      cnt[i] = curr_cnt[i] + x;
    }
  }

  int max_score[P];
  int score[2][P];
  int tot_score[2] = { 0, 0 };

  for (int i = 0; i < P; ++i) {
    max_score[i] = GetMaxScore(cnt[i], n + x);
    for (int j = 0; j < 2; ++j) {
      if (stm[j][i] == OO) {
        score[j][i] = 0;
      } else {
        score[j][i] = max_score[i] - stm[j][i] * max_score[i] / 250;
      }
      tot_score[j] += score[j][i];
    }
  }

  return tot_score[0] > tot_score[1];
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  cin >> n;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < P; ++j) {
      cin >> stm[i][j];
      if (stm[i][j] != -1) {
        ++curr_cnt[j];
      } else {
        stm[i][j] = OO;
      }
    }
  }

  for (int x = 0; x < 1e7; ++x) {
    if (Check(x)) {
      cout << x;
      return 0;
    }
  }

  cout << -1;
}

