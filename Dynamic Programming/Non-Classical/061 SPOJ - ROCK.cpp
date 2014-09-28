// Author : Bony Roopchandani
// ROCK
// DP

// INCLUDES
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
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
#define ll long long
#define mp make_pair
#define nl printf("\n")
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

int L;
char rock[200+5];
int dp[200+5][200+5];

int count(int l, int r)
{
	int c=0;
	
	rept(i, l, r)
	{
		c=(rock[i]=='1')?c+1:c;
	}
	
	if(c>((r-l+1)>>1))
	return (r-l+1);
	else
	return 0;
}

int F(int l, int r)
{
	if(l>r || l>=L || r>=L)
	return 0;
	
	else if(dp[l][r] != -1)
	return dp[l][r];
	
	int P=count(l, r);
	if(P) return P;
	
	int ans=0;
	
	rept(i, l+1, r)
	{
		ans=max(ans, F(l, i-1)+F(i, r));
	}
	
	return dp[l][r]=ans;
}

int main(void)
{
	int T; sfi(T);
	
	while(T--)
	{
		memset(dp, -1, sizeof dp);
		
		sfi(L);
		sfs(rock);
		
		pfi(F(0, L-1));
	}
	
	return (0);
}