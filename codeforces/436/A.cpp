#include <bits/stdc++.h>
using namespace std;
int n, x;
vector<pair<int, int> > car, fruit;
pair<int, int> tmp;
vector<bool> crb, ftb;
int stp = 0, t = 0, stt = 0;

void dd() {
    while (1) {
        int mxi = -1;
        if (t) {
            for (int i = 0; i < car.size(); ++i)
                if (crb[i] && (mxi == -1 or car[i].first > car[mxi].first)
                        && car[i].second <= x)
                    mxi = i;
            if (mxi == -1)
                break;
            x += car[mxi].first;
            crb[mxi] = 0;
        } else {

            for (int i = 0; i < fruit.size(); ++i)
                if (ftb[i] && (mxi == -1 or fruit[i].first > fruit[mxi].first)
                        && fruit[i].second <= x)
                    mxi = i;
            if (mxi == -1)
                break;
            x += fruit[mxi].first;
            ftb[mxi] = 0;
        }
        t = !t;
        ++stp;
    }
}

int main() {

    cin >> n >> x;
    int xt = x;
    while (cin >> n >> tmp.second >> tmp.first)
        if (n)
            car.push_back(tmp);
        else
            fruit.push_back(tmp);
    crb.resize(car.size());
    ftb.resize(fruit.size());
    fill(crb.begin(), crb.end(), 1);
    fill(ftb.begin(), ftb.end(), 1);
    t = 0;
    dd();
    stt = stp;
    stp = 0;
    t = 1;
    x = xt;
    fill(crb.begin(), crb.end(), 1);
    fill(ftb.begin(), ftb.end(), 1);
    dd();
    cout << max(stt, stp);
}
