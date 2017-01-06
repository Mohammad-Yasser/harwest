#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 101;

unordered_set<string> users;

struct Message {
  string sender;
  string text;
  string plain;

  unordered_set<string> possible_senders;

  void Reset() {
    *this = Message();
    possible_senders = users;
  }

  void Process() {
    int colon_pos = plain.find(':');
    sender = plain.substr(0, colon_pos);
    text = plain.substr(colon_pos + 1);
    plain = text;

    for (char& c : text) {
      if (!isalnum(c)) {
        c = ' ';
      }
    }

    stringstream ss;
    ss << text;

    string word;
    while (ss >> word) {
      possible_senders.erase(word);
    }
  }

} messages_[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
//  freopen("wa.txt", "w", stdout);
#endif

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    users.clear();
    users.reserve(2 * n);

    for (int i = 0; i < n; ++i) {
      string user;
      cin >> user;
      users.insert(user);
    }

    int m;
    cin >> m;
    cin.ignore();
    for (int i = 0; i < m; ++i) {
      messages_[i].Reset();
      getline(cin, messages_[i].plain);
      messages_[i].Process();
    }
    for (int k = 0; k < 203; ++k) {
      for (int i = 0; i < m; ++i) {
        if (messages_[i].possible_senders.size() == 0) {
          cout << "Impossible\n";
          goto end_;
        }
        if (messages_[i].sender != "?"
          && messages_[i].possible_senders.count(messages_[i].sender) == 0) {
          cout << "Impossible\n";
          goto end_;
        }
        if (messages_[i].sender == "?"
          && (messages_[i].possible_senders.size() == 1 || k > 101)) {
          messages_[i].sender = *messages_[i].possible_senders.begin();
        }
        if (i + 1 < m) {
          messages_[i + 1].possible_senders.erase(messages_[i].sender);
        }
        if (i > 0) {
          messages_[i - 1].possible_senders.erase(messages_[i].sender);
        }
      }
    }

    for (int i = 0; i < m; ++i) {
      cout << messages_[i].sender << ':' << messages_[i].plain << '\n';
    }

    end_: ;
  }

}
