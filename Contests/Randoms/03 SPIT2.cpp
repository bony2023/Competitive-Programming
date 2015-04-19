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

int n, k;
ll dp[100][100];

ll F(int pos, int cons) {
	if(pos==n)
		return 1;
	if(dp[pos][cons] != -1)
		return dp[pos][cons];
	ll ret=0;
	if(cons==(k-1)) {
		ret+=F(pos+1, 0);
	}
	else {
		ret+=(F(pos+1, cons+1)+F(pos+1, 0));
	}
	return dp[pos][cons]=ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--) {
		cin>>k>>n;
		memset(dp, -1, sizeof dp);
		cout<<F(0, 0)<<endl;
	}
	return (0);
}