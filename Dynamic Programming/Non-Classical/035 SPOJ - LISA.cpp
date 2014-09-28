// Author : Bony Roopchandani
// LISA
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

ll dp[100+5][100+5];
char expr[100+5];

ll getMax(int a, int b)
{
	if(a==b)
	return expr[a]-'0';
	
	else
	if(dp[a][b] != -1)
	return dp[a][b];
	
	else {
	ll ans=0;
	
	for(int op=a+1; op<=b; op+=2)
	{
		if(expr[op]=='+')
		{
			ans=max(ans, getMax(a, op-1) + getMax(op+1, b));
		}
		else if(expr[op]=='*')
		{
			ans=max(ans, getMax(a, op-1) * getMax(op+1, b));
		}
	}
	
	return dp[a][b]=ans;
	}
}

ll getMin(int a, int b)
{
	if(a==b)
	return expr[a]-'0';
	
	else if(dp[a][b] != -1)
	return dp[a][b];
	
	else
	{
		ll ans=INF<<2;
		
		for(int op=a+1; op<=b; op+=2)
		{
			if(expr[op]=='+')
			ans=min(ans, getMin(a, op-1) + getMin(op+1, b));
			
			else if(expr[op]=='*')
			ans=min(ans, getMin(a, op-1) * getMin(op+1, b));
		}
		
		return dp[a][b]=ans;
	}
}

int main()
{
	int T; sfi(T);
	
	while(T--)
	{
		sfs(expr);
		
		memset(dp, -1, sizeof dp);
		printf("%lld ", getMax(0, strlen(expr)-1));
		
		memset(dp, -1, sizeof dp);
		pfl(getMin(0, strlen(expr)-1));
	}
	
	return (0);
}