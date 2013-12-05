#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#define PB push_back

using namespace std;

string s;
vector<char> st;

int main () {
  cin >> s;
  for (int i=0; i<s.size(); i++) {
    if (st.size() > 0 && st.back() == s[i])
      st.pop_back();
    else
      st.PB(s[i]);
  }
  for (int i=0; i<st.size(); i++)
    cout << st[i];
  cout << endl;
}