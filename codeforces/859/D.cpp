#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef long double Double;

const int Levels = 8;
const int N = 1 << Levels;

Double memo_exp[N][N];
Double memo_p[N][N];

struct Nodes {
  int level, left, right, mid;
  int score;
} nodes[N];

Double p[N][N];
int n;

Double getP(int node_id, int winner) {
  auto& node = nodes[node_id];
  if (node.level == 0) {
    assert(node.left == winner);
    return 1;
  }
  auto& res = memo_p[node_id][winner];
  if (res == res) return res;

  res = 0;

  for (int i = node.left; i <= node.mid; ++i) {
    int w = i;
    if (winner <= node.mid) {
      w = node.mid + 1 - node.left + i;
    }

    res += getP(node_id * 2 + !(winner > node.mid), w) * p[winner][w];
  }

  res *= getP(node_id * 2 + (winner > node.mid), winner);

  return res;
}

Double getMaxExpected(int node_id, int winner) {
  auto& node = nodes[node_id];
  if (node.level == 0) {
    return 0;
  }

  auto& res = memo_exp[node_id][winner];
  if (res == res) return res;

  res = 0;

  res = getMaxExpected(node_id * 2 + (winner > node.mid), winner);
  Double other = 0;

  for (int i = node.left; i <= node.mid; ++i) {
    int w = i;
    if (winner <= node.mid) {
      w = node.mid + 1 - node.left + i;
    }

    int child = node_id * 2 + !(winner > node.mid);

    Double tmp = getMaxExpected(child, w);
    other = max(other, tmp);

    res += getP(child, w) * getP(child ^ 1, winner) * p[winner][w] * node.score;
  }

  res += other;

  return res;
}

void build(int node_id, int left, int right, int level, int score) {
  auto& node = nodes[node_id];
  node.left = left;
  node.right = right;
  int mid = (left + right) / 2;
  node.mid = mid;
  node.level = level;
  node.score = score;

//  cout << node_id << ' ' << left << ' ' << right << ' ' << mid << ' ' << level
//    << ' ' << score << endl;
  if (level == 0) return;

  build(node_id * 2, left, mid, level - 1, score / 2);
  build(node_id * 2 + 1, mid + 1, right, level - 1, score / 2);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  memset(memo_exp, -1, sizeof memo_exp);
  memset(memo_p, -1, sizeof memo_p);

  cin >> n;

  build(1, 1, 1 << n, n, (1 << n) / 2);

  for (int i = 1; i <= (1 << n); ++i) {
    for (int j = 1; j <= (1 << n); ++j) {
      cin >> p[i][j];
      p[i][j] /= 100;
    }
  }

  Double res = 0;
  for (int i = 1; i <= (1 << n); ++i) {
    res = max(res, getMaxExpected(1, i));
  }

  cout << fixed << setprecision(10) << res;

}

