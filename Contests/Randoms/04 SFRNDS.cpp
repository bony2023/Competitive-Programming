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

ll Pow(ll a, ll b, int MOD) {
	ll ret=1;
	while(b>0) {
		if(b&1) {
			ret*=a;
			ret%=MOD;
		}
		a*=a;
		a%=MOD;
		b>>=1;
	}
	return ret;
}

ll invMod(ll n, int MOD) {
	return Pow(n, MOD-2, MOD);
}

ll Fact(int N) {
	ll ret=1;
	repd(i, N, max(N-5+1, 1)) {
		ret*=i;
		ret%=MOD;
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	ll den=invMod(120, MOD);
	int T; 
	cin>>T;
	while(T--) {
		int N; cin>>N;
		if(N<6) {
			cout<<"FIGHT"<<endl;
			continue;
		}
		ll res=Fact(N-1)*den;
		cout<<res%MOD<<endl;
	}
	return (0);
}