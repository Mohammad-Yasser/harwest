#include <bits/stdc++.h>
using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define getMSB(x) (__builtin_clzll(x))

typedef long long Long;
typedef unsigned long long ULong;

bool ask(int x, int y) {
  cout << "? " << x << " " << y << endl;

//  cout << "Ans: " ;
//  cout << (x % a >= y % a) << endl;
//  return (x % a >= y % a);

  char res;
  cin >> res;
  return res == 'x';
}

int getPw2() {
  int res = 0;
  while (!ask(1 << res, 1 << (res + 1))) {
    ++res;
  }
  return 1 << res;
}

int play_game() {
  int pw2 = getPw2();
  int diff = 0;

  for (int i = pw2; i > 0; i /= 2) {
    if (!ask(pw2, pw2 + diff + i)) {
      diff += i;
    }
  }
  int res = pw2 + diff;
  if (res == 1) {
    if (!ask(0, 1)) {
      ++res;
    }
  } else {
    ++res;
  }
  return res;
}

int main() {
//  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
//  freopen("test.in", "r", stdin);
#else
//#define endl '\n'
#endif

  string s;
  while (cin >> s) {
    if (s != "start") return 0;
    cout << "! " << play_game() << endl;
  }

}
