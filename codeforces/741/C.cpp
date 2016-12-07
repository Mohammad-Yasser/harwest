#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define sz(v) (int)v.size()
#define all(c) (c).begin(),(c).end()
#define mem(s,v) memset(s,v,sizeof(s))

typedef vector<int> vi;

const int N = 200005;
const int MAX = 2 * N, MAXE = 2 * MAX;
int head[MAX], nxt[MAXE], to[MAXE];
int edgeCount;
void init() {
  edgeCount = 0;
  memset(head, -1, sizeof(head));
}
void addEdge(int f, int t) {
  nxt[edgeCount] = head[f];
  head[f] = edgeCount;
  to[edgeCount++] = t;
}
int low[MAX], tim[MAX], curtime;
int stk[MAX], stksz;
int compId[MAX], compnum;

void tarjanDFS(int cur) {
  low[cur] = tim[cur] = curtime++;
  stk[stksz++] = cur;
  for (int i = head[cur]; i != -1; i = nxt[i]) {
    int j = to[i];
    if (compId[j] == -1) {
      if (tim[j] == -1) tarjanDFS(j);
      low[cur] = min(low[cur], low[j]);
    }
  }
  if (low[cur] == tim[cur]) {
    do {
      compId[stk[stksz - 1]] = compnum;
    } while (stk[--stksz] != cur);
    compnum++;
  }
}

void SCC() {
  compnum = 0;
  curtime = 0;
  memset(compId, -1, sizeof(compId));
  memset(tim, -1, sizeof(tim));
  for (int i = 0; i < MAX; i++) {
    if (tim[i] == -1) tarjanDFS(i);
  }
}

int nodeId(int cur) {
  return 2 * cur;
}

int Not(int cur) {
  return cur ^ 1;
}

void addOr(int i, int j) {
  addEdge(Not(i), j);
  addEdge(Not(j), i);
}

void addImply(int i, int j) {
  addOr(Not(i), j);
}

int invComp[MAX], sortedOrder[MAX], in[MAX], sorSize;

vector<vi> adjComp;

void topo() {
  mem(in, 0), sorSize = 0;
  FOR (i , 0 , sz(adjComp))
    FOR (k , 0 , sz(adjComp[i]))
      in[adjComp[i][k]]++;
  queue<int> q;
  FOR (i , 0 , sz(adjComp))
    if (!in[i]) q.push(i);
  while (sz(q)) {
    int i = q.front();
    q.pop();
    sortedOrder[sorSize++] = i;
    FOR (k , 0 , sz(adjComp[i]))
      if (!--in[adjComp[i][k]]) q.push(adjComp[i][k]);
  }
}

int compres[MAX];

bool _2sat() {
  SCC();
  FOR (i , 0 , ::MAX/2)
  {
    if (compId[nodeId(i)] == compId[Not(nodeId(i))]) return false;
    invComp[compId[nodeId(i)]] = compId[Not(nodeId(i))];
    invComp[compId[Not(nodeId(i))]] = compId[nodeId(i)];
  }
  adjComp.clear(), adjComp.resize(compnum);
  FOR (ii , 0 , ::MAX)
  {
    for (int kk = head[ii]; kk != -1; kk = nxt[kk]) {
      int jj = to[kk];
      int i = compId[ii], j = compId[jj];
      if (i == j) continue;
      adjComp[i].pb(j);
    }
  }
  topo();
  mem(compres, -1);
  FOR (i , 0 , sorSize)
  {
    int id = sortedOrder[i];
    if (compres[id] != -1) continue;
    int invID = invComp[id];
    compres[id] = 0, compres[invID] = 1;
  }
  return true;
}


int frds[N][2];

void AddOpposite(int a, int b) {
  addImply(nodeId(a), Not(nodeId(b)));
  addImply(Not(nodeId(a)), nodeId(b));
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
#endif
  init();

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> frds[i][0] >> frds[i][1];
    --frds[i][0], --frds[i][1];
    AddOpposite(frds[i][0], frds[i][1]);

    AddOpposite(2 * i, 2 * i + 1);
  }

  if (!_2sat()) {
    cout << -1;
    return 0;
  }

  for (int i = 0; i < n; ++i) {
    cout << compres[compId[nodeId(frds[i][0])]] + 1 << ' '
      << compres[compId[nodeId(frds[i][1])]] + 1 << '\n';
  }
}
