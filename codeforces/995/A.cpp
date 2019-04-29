#ifndef Local
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef pair<int, int> Cell;

const int N = 101;

int grid[4][N], old_grid[4][N];
int n;

struct Move {
  int car_id;
  int r, c;

  Move(int i, int r, int c) :
    car_id(i), r(r), c(c) {
  }
};

Cell getSpace(bool empty) {
  for (int i = 0; i < n; ++i) {
    if (!grid[1][i] == empty) return {1 , i};
    if (!grid[2][i] == empty) return {2 , i};
  }
  return {-1,-1};
}

Cell getParking(int car_id) {
  for (int i = 0; i < n; ++i) {
    if (grid[0][i] == car_id) return {0 , i};
    if (grid[3][i] == car_id) return {3 , i};
  }
  assert(false);
  return {-1,-1};
}

vector<Cell> getPath(const Cell& start) {
  Cell to = getParking(grid[start.first][start.second]);
  Cell curr = start;
  vector<Cell> path;
  while (curr != to) {
    if (curr.second < to.second) {
      ++curr.second;
    } else if (curr.second > to.second) {
      --curr.second;
    } else if (curr.first < to.first) {
      ++curr.first;
    } else if (curr.first > to.first) {
      --curr.first;
    }

    path.emplace_back(curr);
  }
  return path;
}

vector<Move> moveEmptySpace(const Cell& from, const Cell& to,
  const Cell& block) {
  vector<Move> res;
  Cell curr = from, prev = from;
  if (curr.first == block.first) {
    curr.first ^= 3;
    if (grid[curr.first][curr.second] != 0) {
      res.emplace_back(grid[curr.first][curr.second], prev.first, prev.second);
    }
    swap(grid[curr.first][curr.second], grid[prev.first][prev.second]);
    prev = curr;
  }
  while (curr != to) {
    if (curr.second < to.second) {
      ++curr.second;
    } else if (curr.second > to.second) {
      --curr.second;
    } else if (curr.first < to.first) {
      ++curr.first;
    } else if (curr.first > to.first) {
      --curr.first;
    }

    if (grid[curr.first][curr.second] != 0) {
      res.emplace_back(grid[curr.first][curr.second], prev.first, prev.second);
    }
    swap(grid[curr.first][curr.second], grid[prev.first][prev.second]);
    prev = curr;
  }
  return res;
}

vector<Move> solve() {
  vector<Move> res;

  while (true) {
    for (int i = 0; i < n; ++i) {
      if (grid[0][i] == grid[1][i] && grid[0][i] != 0) {
        res.emplace_back(grid[0][i], 0, i);
        grid[1][i] = 0;
      }
      if (grid[2][i] == grid[3][i] && grid[2][i] != 0) {
        res.emplace_back(grid[3][i], 3, i);
        grid[2][i] = 0;
      }
    }

    auto empty_space = getSpace(true);
    if (empty_space.first == -1) {
      cout << -1;
      exit(0);
    }

    auto car_place = getSpace(false);
    if (car_place.first == -1) break;
    auto path = getPath(car_place);
    path.pop_back();

    for (auto& cell : path) {
      auto emptySpaceMovements = moveEmptySpace(empty_space, cell, car_place);
      res.insert(res.end(), emptySpaceMovements.begin(),
        emptySpaceMovements.end());
      res.emplace_back(grid[car_place.first][car_place.second], cell.first,
        cell.second);
      swap(grid[car_place.first][car_place.second],
        grid[cell.first][cell.second]);
      empty_space = car_place;
      car_place = cell;
    }
  }

  return res;
}

void test(const vector<Move>& moves) {
  vector<Cell> car_places(2 * n + 1, make_pair(-1, -1));
  for (int i = 1; i < 3; ++i) {
    for (int j = 0; j < n; ++j) {
      if (old_grid[i][j] != 0) {
        car_places[old_grid[i][j]] = {i , j};
      }
    }
  }
  for (auto& move : moves) {
    auto from = car_places[move.car_id];
    if (old_grid[move.r][move.c] != 0 && move.r != 0 && move.r != 3) {
      cout << old_grid[move.r][move.c] << " " << move.car_id << " "
        << move.r + 1 << " " << move.c + 1 << endl;
      assert(false);
    }
    old_grid[car_places[move.car_id].first][car_places[move.car_id].second] = 0;
    old_grid[move.r][move.c] = move.car_id;
    car_places[move.car_id] = {move.r,move.c};
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int k;
  cin >> n >> k;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> grid[i][j];
      old_grid[i][j] = grid[i][j];
    }
  }

  auto res = solve();

  cout << res.size() << endl;
  assert(res.size() < 20000);
  for (auto& move : res) {
    cout << move.car_id << " " << move.r + 1 << " " << move.c + 1 << endl;
  }
}
