#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct BIT {
    vector<ll> v;
    BIT(int s) {
        v = vector<ll>(s + 3, 0);
    }
    ll get(int i) {
        ++i;
        ll r = 0;
        while (i) {
            r += v[i - 1];
            i -= i & -i;
        }
        return r;
    }
    void add(int i, ll val) {
        ++i;
        while (i <= v.size()) {
            v[i - 1] += val;
            i += i & -i;
        }
    }
};

struct Line {
    int x1, y1, x2, y2;
};

struct hsrt {
    bool operator ()(const Line &a, const Line &b) const {
        return a.x1 < b.x1;
    }
};

struct vsrt {
    bool operator ()(const Line &a, const Line &b) const {
        return a.y1 < b.y1;
    }
};

unordered_map<int, vector<Line> > hor, ver;

map<int, int> cmpY;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    ll ans = 0;

    while (n--) {
        Line l;
        cin >> l.x1 >> l.y1 >> l.x2 >> l.y2;
        if (l.x1 > l.x2) swap(l.x1, l.x2);
        if (l.y1 > l.y2) swap(l.y1, l.y2);

        cmpY[l.y1], cmpY[l.y2];

        if (l.x1 == l.x2)
            ver[l.x1].push_back(l);
        else
            hor[l.y1].push_back(l);
    }

    int id = 1;
    for (auto &pr : cmpY)
        pr.second = id++;

    vector<Line> hL, vL;

    for (auto &pr : hor) {
        auto &vec = pr.second;
        sort(vec.begin(), vec.end(), hsrt());
        int mn = vec[0].x1, mx = vec[0].x2;
        for (Line &l : vec)
            if (l.x1 <= mx)
                mx = max(mx, l.x2);
            else
                hL.push_back( { mn, pr.first, mx, pr.first }), mn = l.x1, mx = l.x2;
        hL.push_back( { mn, pr.first, mx, pr.first });
    }

    sort(hL.rbegin(), hL.rend(), hsrt());

    for (auto &pr : ver) {
        auto &vec = pr.second;
        sort(vec.begin(), vec.end(), vsrt());
        int mn = vec[0].y1, mx = vec[0].y2;
        for (Line &l : vec)
            if (l.y1 <= mx)
                mx = max(mx, l.y2);
            else
                vL.push_back( { pr.first, mn, pr.first, mx }), mn = l.y1, mx = l.y2;
        vL.push_back( { pr.first, mn, pr.first, mx });
    }

    sort(vL.begin(), vL.end(), hsrt());

    multiset<Line, hsrt> curr;

    BIT bit(id);

    for (Line &l : hL)
        ans += l.x2 - l.x1 + 1;

    for (Line &l : vL) {
        ans += l.y2 - l.y1 + 1;
        while (hL.size() && hL.back().x1 <= l.x1) {
            swap(hL.back().x1, hL.back().x2); // To sort on x2
            curr.insert(hL.back());
            bit.add(cmpY[hL.back().y1], 1);
            hL.pop_back();
        }

        while (curr.size() && curr.begin()->x1 < l.x1) {
            bit.add(cmpY[curr.begin()->y1], -1);
            curr.erase(curr.begin());
        }
        ans -= bit.get(cmpY[l.y2]) - bit.get(cmpY[l.y1] - 1);
    }

    cout << ans;

}
