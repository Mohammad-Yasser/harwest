#include <bits/stdc++.h>
using namespace std;

const int N = 15;
const int K = 9;
const int D = 4;
const int kMaxState = 14745601;
const int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };

int n, m, k;

void Print(vector<pair<int, int>> pos) {
  for (auto p : pos) {
    cout << "(" << p.first << "," << p.second << ")\n";
  }
  cout << "-----------" << endl;
}

void Print(vector<int> pos) {
  for (auto p : pos) {
    cout << p << "\n";
  }
  cout << "-----------" << endl;
}

vector<int> UnserializeState(int serialized_state) {
  vector<int> unserialized_state(k + 1);

  unserialized_state[0] = serialized_state % N;
  serialized_state /= N;

  unserialized_state[1] = serialized_state % N;
  serialized_state /= N;

  for (int i = 2; i < unserialized_state.size(); ++i) {
    unserialized_state[i] = serialized_state % D;
    serialized_state /= D;
  }
  return unserialized_state;
}

int SerializeState(const vector<int>& unserialized_state) {

  if (unserialized_state.size() == 0) {
    return 0;
  }

  int serialized_state = 0;

  for (int i = unserialized_state.size() - 1; i > 1; --i) {
    serialized_state += unserialized_state[i];
    if (i - 1 > 1) {
      serialized_state *= D;
    } else {
      serialized_state *= N;
    }
  }

  serialized_state += unserialized_state[1];
  serialized_state *= N;

  serialized_state += unserialized_state[0];
  return serialized_state;
}

pair<int, int> GetNewPos(pair<int, int> prev, int dir) {
  return {prev.first + dx[dir] , prev.second + dy[dir]};
}

vector<int> GetStateFromPositions(const vector<pair<int, int>>& positions) {
  vector<int> state(positions.size() + 1);

  state[0] = positions[0].first;
  state[1] = positions[0].second;

  for (int i = 2; i < state.size(); ++i) {
    for (int d = 0; d < 4; ++d) {
      if (GetNewPos(positions[i - 2], d) == positions[i - 1]) {
        state[i] = d;
      }
    }
  }

  return state;
}

vector<pair<int, int>> GetPositionsFromState(const vector<int>& state) {
  vector<pair<int, int>> positions(state.size() - 1);
  positions[0] = {state[0] ,state[1]};

  for (int i = 1; i < positions.size(); ++i) {
    positions[i] = GetNewPos(positions[i - 1], state[i + 1]);
  }

  return positions;
}

char grid[N][N];
bool vis[kMaxState];

bool InRange(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

void CanGoAndIsGoal(const vector<pair<int, int>>& positions, int dir,
bool& can_go, bool& is_goal) {
  can_go = true;

  auto new_pos = GetNewPos(positions[0], dir);
  can_go &= InRange(new_pos.first, new_pos.second);
  for (int i = 1; i + 1 < positions.size(); ++i) {
    can_go &= (new_pos != positions[i]);
  }

  can_go &= (grid[new_pos.first][new_pos.second] != '#');
  is_goal = can_go && (grid[new_pos.first][new_pos.second] == '@');
}

vector<int> GetNewUnserializedState(int state, int dir, bool& can_go,
bool& is_goal) {
  auto unserialized_state = UnserializeState(state);

  auto pos = GetPositionsFromState(unserialized_state);

  CanGoAndIsGoal(pos, dir, can_go, is_goal);
  if (!can_go) return {};

  for (int i = unserialized_state.size() - 1; i > 2; --i) {
    unserialized_state[i] = unserialized_state[i - 1];
  }

  unserialized_state[2] = dir ^ 1;

  auto new_pos = GetNewPos(
    make_pair(unserialized_state[0], unserialized_state[1]), dir);

  unserialized_state[0] = new_pos.first;
  unserialized_state[1] = new_pos.second;

  return unserialized_state;
}

int GetNewSerializedState(int state, int dir, bool& can_go, bool& is_goal) {
  auto new_unserialized_state = GetNewUnserializedState(state, dir, can_go,
    is_goal);

  int new_serialized_state = SerializeState(new_unserialized_state);

  return new_serialized_state;
}

int Bfs(int initial_state) {
  queue<int> q;
  q.push(initial_state);
  vis[initial_state] = true;

  int level = 0;

  while (!q.empty()) {
    int sz = q.size();
    while (sz--) {
      int state = q.front();

      q.pop();

      for (int dir = 0; dir < 4; ++dir) {
        bool can_go, is_goal;
        int new_state = GetNewSerializedState(state, dir, can_go, is_goal);

        if (!can_go) continue;

        if (vis[new_state]) continue;
        if (is_goal) return level + 1;

        q.push(new_state);
        vis[new_state] = true;
      }

    }
    ++level;
  }

  return -1;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif

  cin >> n >> m;
  vector<pair<int, int>> positions(K);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> grid[i][j];
      if (isdigit(grid[i][j])) {
        k = max(k, grid[i][j] - '0');
        positions[grid[i][j] - '1'] = {i,j};
      }
    }
  }

  positions.erase(positions.begin() + k, positions.end());
  auto unserialized_state = GetStateFromPositions(positions);
  int serialized_state = SerializeState(unserialized_state);

  cout << Bfs(serialized_state);

}
