// Author : Bony Roopchandani
// 

// INCLUDES
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// MACROS
#define all(a) a.begin(), a.end()
#define bg begin()
#define en end()
#define ff first
#define in(a) freopen(a, "r", stdin)
#define ll long long
#define mp make_pair
#define out(a) freopen(a, "w", stdout)
#define pb push_back
#define rep(i, n) for(int i=0; i<n; i++)
#define repd(i, a, b) for(int i=a; i>=b; i--)
#define rept(i, a, b) for(int i=a; i<=b; i++)
#define ss second
#define sz size()

// CONSTS
const double EPS = (1e-11);
const double PI = acos(-1.0);
const int INF = 9999999;
const int MOD = (1e9 + 7);

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.ff<b.ff;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	int n, days, x, curr=0;
	vector<int> res;
	vector<pair<int, int> > a;
	cin>>n>>days;
	rept(i, 1, n) {
		cin>>x;
		a.pb(mp(x, i));
	}
	sort(all(a), cmp);
	rep(i, a.sz) {
		if(curr+a[i].ff<=days) {
			curr+=a[i].ff;
			res.pb(a[i].ss);
		}
	}
	if(!res.size())
		cout<<0;
	else {
		cout<<res.size()<<endl;
		rep(i, res.size())
			cout<<res[i]<<" ";
	}
	return (0);
}