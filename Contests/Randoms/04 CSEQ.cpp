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
#define nl printf("\n")
#define out(a) freopen(a, "w", stdout)
#define pb push_back
#define pf(a) printf("%d ",a)
#define pfi(a) printf("%d\n",a)
#define pfl(a) printf("%lld\n",(ll)a)
#define pfs(a) printf("%s\n",a)
#define rep(i, n) for(int i=0; i<n; i++)
#define repd(i, a, b) for(int i=a; i>=b; i--)
#define repl(i, n) for(ll i=0; i<n; i++)
#define repld(i, a, b) for(ll i=a; i>=b; i--)
#define replt(i, a, b) for(ll i=a; i<=b; i++)
#define rept(i, a, b) for(int i=a; i<=b; i++)
#define sfi(a) scanf("%d",&a)
#define sfl(a) scanf("%lld",&a)
#define sfs(a) scanf("%s",a)
#define ss second
#define sz size()

// CONSTS
const double EPS = (1e-11);
const double PI = acos(-1.0);
const int INF = 9999999;
const int MOD = (1e6 + 3);

// TYPEDEFS
typedef list < int > LI;
typedef list < ll > LLL;
typedef map < int, bool > MIB;
typedef map < int, int > MII;
typedef map < int, ll > MIL;
typedef map < ll, int > MLI;
typedef pair < int, int > PII;
typedef pair < int, PII > PIII;
typedef pair < int, PIII > PIIII;
typedef pair < int, ll > PIL;
typedef pair < ll, int > PLI;
typedef set < int > SI;
typedef set < ll > SLL;
typedef vector < int > VI;
typedef vector < ll > VLL;
typedef vector < string > VS;

ll fact[MOD+5];
int n, l, r;

void initFact() {
	fact[0]=fact[1]=1;
	rept(i, 2, MOD-1) {
		fact[i]=(fact[i-1]*i)%MOD;
	}
}

ll ModPow(ll a, ll b) {
	ll ret=1;
	while(b>0) {
		if(b&1) {
			ret=(ret*a)%MOD;
		}
		a=(a*a)%MOD;
		b>>=1;
	}
	return ret;
}

ll solve() {
	int N=r-l+1;
	ll num=(fact[N+n]%MOD*(ModPow(fact[N], MOD-2)%MOD))%MOD;
	ll den=ModPow(fact[n], MOD-2)%MOD;
	ll res=(num*den)%MOD;
	return res=(res-1+MOD)%MOD;
}

int main(void) {
	initFact();
	int T; sfi(T);
	while(T--) {
		sfi(n), sfi(l), sfi(r);
		pfl(solve());
	}
	return (0);
}