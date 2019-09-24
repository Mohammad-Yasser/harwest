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

// gp_hash_table<int, int> table;

const int N = 2e5 + 5;
int initial[N];
int arr[N];

struct Event {
  int type;
  int p, x;
};

int n;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> initial[i];
  }

  int q;
  cin >> q;
  vector<Event> events(q);
  for (auto& event : events) {
    cin >> event.type;
    if (event.type == 1) {
      cin >> event.p >> event.x;
      --event.p;
    } else {
      cin >> event.x;
    }
  }

  memset(arr, -1, sizeof arr);
  int curr_x = 0;
  while (!events.empty()) {
    auto event = events.back();
    events.pop_back();
    if (event.type == 1) {
      if (arr[event.p] == -1) {
        arr[event.p] = max(curr_x, event.x);
      }
    } else {
      curr_x = max(curr_x, event.x);
    }
  }

  for (int i = 0; i < n; ++i) {
    if (arr[i] == -1) {
      arr[i] = max(curr_x, initial[i]);
    }
    cout << arr[i] << " ";
  }
  cout << endl;

}
