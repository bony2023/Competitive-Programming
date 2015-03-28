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
const int MOD = (1e9 + 7);

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

int main(void) {
	int n; sfi(n);
	ll a[n+5];
	rep(i, n) sfl(a[i]);
	
	int k=0;
	while(a[k]<a[k+1] && (k+1)<n)
	k++;
	
	if(k==(n-1)) {
		puts("yes");
		pf(1), pfi(1); return 0;
	}
	
	int l=k;
	while(a[k+1]<a[k] && (k+1)<n) k++;
	int r=k;
	
	rept(i, r+2, n-1) if(a[i-1]>a[i]) {
		puts("no");
		return 0;
	}
	
	if(r==(n-1) && l) {
		if(a[r]>a[l-1]) {
			puts("yes");
			pf(l+1), pfi(r+1);
			return 0;
		}
		else {
			puts("no");
			return 0;
		}
	}
	else if(l==0 && r!=(n-1)) {
		if(a[l]<a[r+1]) {
			puts("yes");
			pf(l+1), pfi(r+1);
			return 0;
		}
		else {
			puts("no");
			return 0;
		}
	}
	else if(l==0 && r==(n-1)) {
		if(a[l]>a[r]) {
			puts("yes");
			pf(l+1), pfi(r+1);
			return 0;
		}
		else {
			puts("no");
			return 0;
		}
	}
	else {
		if(a[r]>a[l-1] && a[l]<a[r+1]) {
			puts("yes");
			pf(l+1), pfi(r+1);
			return 0;
		}
		else {
			puts("no");
			return 0;
		}
	}
	return (0);
}