#include <bits/stdc++.h>
#include <iostream> 
#include <cstdio>
#include <algorithm>
#include <vector> 
#include <set> 
#include <string> 
#include <cstring> 
#include <cstdlib>
#include <climits>
#include <cctype>
#include <cmath>
#include <sstream>
#include <ctime>
#include <set>
#include <map>
#include <numeric>
#include <utility>
#include <deque>
#include <queue>
#include <stack>
#include <iomanip>
#include <complex>
#include <list>
#include <bitset>
#include <fstream>
#include <limits>
#include <memory.h>

using namespace std;

#define REP(i,n) for( (i)=0 ; (i)<(n) ; (i)++ )
#define rep(i,x,n) for( (i)=(x) ; (i)<(n) ; (i)++ )
#define REV(i,n) for( (i)=(n) ; (i)>=0 ; (i)-- )
#define FORIT(it,x) for( (it)=(x).begin() ; (it)!=(x).end() ; (it)++ )
#define foreach(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define rforeach(it,c) for(__typeof((c).rbegin()) it=(c).rbegin();it!=(c).rend();++it)
#define foreach2d(i, j, v) foreach(i,v) foreach(j,*i)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define SZ(x) ((int)(x).size())
#define MMS(x,n) memset(x,n,sizeof(x))
#define mms(x,n,s) memset(x,n,sizeof(x)*s)
#define pb push_back
#define mp make_pair
#define NX next_permutation
#define UN(x) sort(all(x)),x.erase(unique(all(x)),x.end())
#define CV(x,n) count(all(x),(n))
#define FIND(x,n) find(all(x),(n))-(x).begin()
#define SET_DIFF(x,y,z) set_difference(all(x) , all(y) , back_inserter(z))
#define ACC(x) accumulate(all(x),0)
#define PPC(x) __builtin_popcount(x)
#define LZ(x) __builtin_clz(x)
#define TZ(x) __builtin_ctz(x)
#define mxe(x) *max_element(all(x))
#define mne(x) *min_element(all(x))
#define low(x,i) lower_bound(all(x),i)
#define upp(x,i) upper_bound(all(x),i)
#define NXPOW2(x) (1ll << ((int)log2(x)+1))
#define FIB(x) (pow((1+sqrt(5))/2,(x))-pow((1-sqrt(5))/2,(x)))/sqrt(5)
#define EPS numeric_limits<double>::epsilon()
#define PR(x) cout << #x << " = " << (x) << endl ;
#define INF 0x3f

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef pair<int, int> pii;

const int OO = (int) 2e9;
const double eps = 1e-9;

int main() 
{ 
	string s ;
	cin >> s ;
	int im=0 ;
	for (;im<s.size() && s[im]!='^' ;im++) ;

	ll left=0 ;
	cerr << im ;
	for (int i=0 ; i<im ; i++)
	{
		if (s[i]>='0' && s[i]<='9')
		left+=(im-i)*(s[i]-'0') ;
	}
	cerr << left ;
	for (int i=im ; i<s.size() ; i++)
		{
			if (s[i]>='0' && s[i]<='9')
			left-=(i-im)*(s[i]-'0') ;
		}
	if (left==0) cout << "balance" ;
	else if (left>0) cout << "left" ;
	else cout << "right" ;
	
	return 0;
}
