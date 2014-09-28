// Author : Bony Roopchandani
// 10130 - SuperSale
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

int N, G;
int P[1000+5], W[1000+5];
int MW[100+5];
int dp[1000+5][30+5];

int F(int pos, int RemW)
{
	if(RemW<=0)
	return 0;
	
	if(dp[pos][RemW] != -1)
	return dp[pos][RemW];
	
	int ans=0;
	
	rept(i, pos, N-1)
	{
		if(RemW>=W[i])
		ans=max(ans, P[i]+F(i+1, RemW-W[i]));
	}
	
	return dp[pos][RemW]=ans;
}

int main(void)
{
//	freopen("input.txt","r", stdin);
	
	int T; sfi(T);
	
	while(T--)
	{
		memset(dp, -1, sizeof dp);
		
		sfi(N);
		
		rep(i, N)
		sfi(P[i]), sfi(W[i]);
		
		sfi(G);
		
		rep(i, G)
		{
			sfi(MW[i]);
		}
		
		int P=0;
		
		rep(i, G)
		{
			P+=F(0, MW[i]);
		}
		
		pfi(P);
	}
	
	return (0);
}