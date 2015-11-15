#include<bits/stdc++.h>
using namespace std;

// Couldn't get a simpler solution :( Hope this is correct.
typedef int ll;
const int SIZE = 300005;

struct SegmentTree {
    struct node {
        int from, to;
        ll sum;
    } nodes[SIZE];

    ll val[100005];

    void createTree(int node = 1, int from = 1, int to = 100005) {
        nodes[node] = {from,to,0};
        if (from == to) return;
        createTree(2 * node , from , (from + to) / 2);
        createTree(2 * node + 1, (from + to) / 2 + 1 , to);
    }

    ll query(int from , int to,int node =1) {

        if (nodes[node].from > to or nodes[node].to < from) return 0;
        if (nodes[node].from >= from && nodes[node].to <= to) return nodes[node].sum;
        return max(query(from , to,2 * node ), query(from , to,2 * node + 1));
    }

    void update(int index,ll diff,int node = 1) {
        if (index < nodes[node].from or index > nodes[node].to) return;
        if (nodes[node].from == nodes[node].to) {
            nodes[node].sum = max(nodes[node].sum ,diff);
            val[index] = max(val[index],diff);
            return;
        }
        update (index, diff , 2 * node);
        update (index, diff , 2 * node + 1);
        nodes[node].sum = max(nodes[2 * node].sum , nodes[2 * node + 1].sum);
    }
};

SegmentTree tree;

pair<int, int> points[100005];

unordered_map<int, queue<int> > mp;
int ans[100005];
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> points[i].first >> points[i].second;

    sort(points, points + n);

    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        mp[tmp].push(i);
    }

    for (int i = 0; i < n; ++i) {
        int mx = tree.query(0, points[i].second);
        int s = points[i].second - points[i].first;
        while (mp[s].size() && mp[s].front() < mx)
            mp[s].pop();
        if (!mp[s].size()) {
            cout << "NO";
            return 0;
        }
        tree.update(points[i].second,mp[s].front()) ;
        ans[mp[s].front()] = i;
        mp[s].pop();
    }
    cout << "YES\n";

    for (int i = 0; i < n; ++i)
        cout << points[ans[i]].first << ' ' << points[ans[i]].second << '\n';

    return 0;
}
