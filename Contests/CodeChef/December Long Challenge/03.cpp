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

int N, K;
ll a[25], toBe;
bool vis[25], done;
map<pair<ll, pair<int, int> >, bool> dp;

bool  F(ll currSum, int taken, int sets)
{
	if(done) return true;
	
	if(taken==N && sets==K) {
		done=true;
		return true;
	}
	else if(taken==N || sets==K) return false;
	
	if(dp.count(mp(currSum, mp(taken, sets)))) return dp[mp(currSum, mp(taken, sets))];
	
	bool ret=false;
	
	rep(i, N)
	{
		if(!vis[i] && (currSum+a[i])<=toBe)
		{
			vis[i]=1;
			if((currSum+a[i])==toBe) ret |= F(0, taken+1, sets+1);
			ret |= F(currSum+a[i], taken+1, sets);
			vis[i]=0;
		}
	}
	
	return dp[mp(currSum, mp(taken, sets))]=ret;
}

int main(void)
{
	int T; sfi(T);
	
	while(T--)
	{
		sfi(N), sfi(K);
		ll sum=0;
		rep(i, N) {
			sfl(a[i]), sum+=a[i];
		}

		if(sum%K || K>N) {
			puts("no");
			continue;
		}

		toBe=sum/K;
		memset(vis, 0, sizeof vis);
		done=false;
		if(F(0, 0, 0)) puts("yes");
		else
		puts("no");
		dp.clear();
	}
	return (0);
}