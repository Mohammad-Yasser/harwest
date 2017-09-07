#include <bits/stdc++.h>

using namespace std;

typedef long long Long;

template<class T>
struct BIT {
    vector<T> v;

    BIT() {
        v.resize(1 << 19, 0);
    }

    T Get(int i) {
        i++;
        T r = 0;
        while (i) {
            r += v[i - 1];
            i -= i & -i;
        }
        return r;
    }

    void Add(int i, T val = 1) {
        i++;
        while (i <= (int) v.size()) {
            v[i - 1] += val;
            i += i & -i;
        }
    }
};

BIT<int> bit;


const int N = 2e5 + 5;

struct Query {
    int l, d, r, u;
} queries[N];

map<pair<int, int>, int> mp;
vector<int> bit_queries[N];


int cols[N];
int n;

void addQ(int row, int col) {
    if (min(row, col) < 1 or max(row, col) > n)
        return;
    bit_queries[col].push_back(row);
}


void pushQ(const Query &query) {
    addQ(query.u - 1, query.l - 1);
    addQ(query.u - 1, query.r);
    addQ(query.d, query.l - 1);
    addQ(query.d, query.r);
    addQ(n, query.r);
}

void process() {
    for (int i = 1; i <= n; ++i) {
        bit.Add(cols[i]);
        for (int rq : bit_queries[i]) {
            mp[{rq, i}] = bit.Get(rq);
        }
    }
}

Long nC2(Long n) {
    return n * (n - 1) / 2;
}

Long getAns(const Query &query) {
    Long res = nC2(n);
    res -= nC2(query.l - 1);
    res -= nC2(n - query.r);
    res -= nC2(query.u - 1);
    res -= nC2(n - query.d);

    res += nC2(mp[{query.u - 1, query.l - 1}]);
    res += nC2(query.u - 1 - mp[{query.u - 1, query.r}]);
    res += nC2(query.l - 1 - mp[{query.d, query.l - 1}]);


    int tmp = n - query.d - (mp[{n, query.r}] - mp[{query.d, query.r}]);
    res += nC2(tmp);

    return res;
}

int main() {
#ifdef Local
    freopen("test.in", "r", stdin);
#endif

    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> cols[i];
    }

    for (int i = 1; i <= q; ++i) {
        cin >> queries[i].l >> queries[i].d >> queries[i].r >> queries[i].u;
        swap(queries[i].u, queries[i].d);
        pushQ(queries[i]);
    }

    process();


    for (int i = 1; i <= q; ++i) {
        cout << getAns(queries[i]) << '\n';
    }

}