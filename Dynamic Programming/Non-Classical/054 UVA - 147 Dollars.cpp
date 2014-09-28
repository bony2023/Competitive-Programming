// Author : Bony Roopchandani
// 147 - Dollars
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

int C[]={10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
ll dp[30000+5][11+5];

ll F(int RemS, int c)
{
	if(!RemS)
	return 1;
	else if(c>=11)
	return 0;
	
	if(dp[RemS][c] != -1)
	return dp[RemS][c];
	
	ll ans=0;
	
	for(int i=0; i*C[c]<=RemS; i++)
	{
		ans+=F(RemS-i*C[c], c+1);
	}
	
	return dp[RemS][c]=ans;
}

int main(void)
{
	double a;
	memset(dp, -1, sizeof dp);

	while(1)
	{
		scanf("%lf", &a);
		
		if(a==0.00)
		break;
		
		int T=round(a*100.0);
		
		printf("%6.2lf%17lld\n", a, F(T, 0));
	}
	
	return (0);
}