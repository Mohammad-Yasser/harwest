#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

struct Trie {
  struct Node {
    int cnt = 0;
    Node *left_ = nullptr, *right_ = nullptr;
    Node* left() {
      if (left_) return left_;
      return left_ = new Node();
    }
    Node* right() {
      if (right_) return right_;
      return right_ = new Node();
    }

  }* head = new Node();

  int AddAndGet(const string& n, int val) {
    Node* curr = head;
    for (char c : n)
      if (c == '0') {
        curr = curr->left();
      } else {
        curr = curr->right();
      }
    return curr->cnt += val;
  }

} trie;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    char op;
    string n;
    cin >> op >> n;
    for (char& c : n) c = '0' + (c & 1);
    n = string(19 - n.size(), '0') + n;
//    cout << n << endl;
    if (op == '+') trie.AddAndGet(n, 1);
    if (op == '-') trie.AddAndGet(n, -1);
    if (op == '?') cout << trie.AddAndGet(n, 0) << '\n';
  }
}
