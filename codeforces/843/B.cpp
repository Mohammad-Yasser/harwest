#include <bits/stdc++.h>

using namespace std;

const int N = 50005;


vector<tuple<int, int, int>> nodes;

unsigned int Random(int n) {
    unsigned int r = rand();
    r *= 12387;
    r += rand();
    r *= 234987;
    r += rand();
    r *= 123945;
    r += rand();
    r %= n;
    return r;
}

bool vis[N];
int cnt_vis;


void query(int ind) {
    ++cnt_vis;
    vis[ind] = true;
    cout << "? " << ind << endl;
    int val, nxt;
    cin >> val >> nxt;
    assert(val != -1);
    nodes.emplace_back(val, nxt, ind);
}


int main() {
#ifdef Local
//    freopen("test.in", "r", stdin);
#else
    //#define endl '\n'
#endif

    srand(time(0));

    int n, start, x;
    cin >> n >> start >> x;


    query(start);
    for (int i = 0; i < 1000; ++i) {
        int ind = Random(n) + 1;
        if (vis[ind]) {
            i -= (cnt_vis < n - 500);
            continue;
        }
        query(ind);
    }


    sort(nodes.begin(), nodes.end());

    if (get<0>(nodes[0]) >= x) {
        cout << "! " << get<0>(nodes[0]);
        return 0;
    }

    int curr_node = start;
    for (auto node : nodes) {
        if (get<0>(node) < x) {
            curr_node = get<1>(node);
        }
    }

    while (curr_node != -1) {
        cout << "? " << curr_node << endl;
        assert(++cnt_vis < 2000);
        int val, nxt;
        cin >> val >> nxt;

        assert(val != -1);

        if (val >= x) {
            cout << "! " << val << endl;
            return 0;
        }
        curr_node = nxt;
    }

    cout << "! -1" << endl;


    return 0;
}
