#include <bits/stdc++.h>

using namespace std;

const int MOD = round(1e9 + 7);
typedef long long Long;

const int N = 1e6 + 5;

struct Node {
  Node* left = nullptr;
  Node* right = nullptr;
  int size = 0;

  Node* getLeft() {
    if (left != nullptr) return left;
    return left = new Node();
  }

  Node* getRight() {
    if (right != nullptr) return right;
    return right = new Node();
  }
};

Node* root = new Node();

void add(int x, bool remove = false) {
  Node* curr = root;
  root->size += (remove ? -1 : 1);
  for (int i = 31; i >= 0; --i) {
    bool dir = ((x >> i) & 1);
    if (dir == false) {
      curr = curr->getLeft();
    } else {
      curr = curr->getRight();
    }
    curr->size += (remove ? -1 : 1);
  }
}

int count(int p, int l) {
  Node* curr = root;
  int res = 0;
  for (int i = 31; i >= 0; --i) {
    if (curr->size == 0) break;
    bool dir = (((l ^ p) >> i) & 1);
    if (dir == false) {
      res += (((p >> i) & 1) ? 1 : 0) * curr->getRight()->size;
      curr = curr->getLeft();
    } else {
      res += (((p >> i) & 1) ? 0 : 1) * curr->getLeft()->size;
      curr = curr->getRight();
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  int q;
  cin >> q;

  while (q--) {
    int type, p, l;

    cin >> type >> p;
    if (type == 3) {
      cin >> l;
      cout << count(p, l) << '\n';
    } else {
      add(p, type == 2);
    }

  }

  return 0;
}
