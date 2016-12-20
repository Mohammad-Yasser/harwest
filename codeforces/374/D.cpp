#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const auto EPS = 1e-9;

const int N = 1000006;

string seq;

int a[N];
int events_cnt, a_size;

template<class T>
struct BIT {
  vector<T> v;
  BIT(int s) {
    Resize(s);
  }
  void Resize(int s) {
    s = 1 << (int) ceil(log(1.0 * s) / log(2.) + EPS);
    v.resize(s);
  }
  T GetIndex(int val) {
    val++;
    T r = 0;
    while (val) {
      r += v[val - 1];
      val -= val & -val;
    }
    return r;
  }
  void Add(int val, T cnt = 1) {
    val++;
    while (val <= (int) v.size()) {
      v[val - 1] += cnt;
      val += val & -val;
    }
  }
  int Find(T index) {
    int s = 0;
    int m = v.size() >> 1;
    while (m) {
      if (v[s + m - 1] < index) index -= v[(s += m) - 1];
      m >>= 1;
    }
    return s;
  }
};

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("test.in", "rt", stdin);
  //  freopen("out.txt", "wt", stdout);
#endif

  cin >> events_cnt >> a_size;

  for (int i = 0; i < a_size; ++i) {
    cin >> a[i];
    --a[i];
  }

  BIT<int> bit(N);
  int curr_length = 0;
  for (int i = 0; i < events_cnt; ++i) {
    int event;
    cin >> event;

    if (event == -1) {
      int a_ind = 0;
      while (a_ind < a_size && a[a_ind] < curr_length) {
        int seq_ind = bit.Find(a[a_ind] + 1 - a_ind);
        bit.Add(seq_ind, -1);
        ++a_ind;
      }
      curr_length -= a_ind;
    } else {
      bit.Add(seq.size());
      seq += '0' + event;
      ++curr_length;
    }
  }

  string res;
  for (int i = 0; i < curr_length; ++i) {
    int seq_ind = bit.Find(i + 1);
    res += seq[seq_ind];
  }

  if (res.size() == 0) {
    res = "Poor stack!\n";
  }

  cout << res;

  return 0;
}
