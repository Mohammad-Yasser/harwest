#include <bits/stdc++.h>
using namespace std;

// That can be solved as a simple linear programming problem graphically.

int main() {
    int x, y;
    cin >> x >> y;
    if (x <= 2 * y && y <= 2 * x)
        cout << (x + y) / 3;
    //   If that point is feasible, then it'll be the maximum. //
    else if (2 * x < y)
        // (x<y/2) is wrong because it is integer division :D
        cout << x;
    else
        cout << y;
    /* I check the feasible region by these conditions.
     * Depending on the feasible region, I choose the optimal solution.
     * Of course there are other ways to solve this problem.
     * If anything is unclear, you can send me. I like explanation :D
     */
}
