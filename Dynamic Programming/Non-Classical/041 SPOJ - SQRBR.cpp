// Author : Bony Roopchandani
// SQRBR
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

bool POS[50]={0};
int dp[50][50];
int mx;

int f(int pos, int more)
{
	mx=max(mx, more);
	
	if(pos==1)
	{
		if(more == 1)
    	return 1;
    	else if(more>1)
   	return 0;
	}
	else if(dp[pos][more] != -1)
	return dp[pos][more];
	
	
	if(POS[pos]==true)
	{
		if(more==0)
		return dp[pos][more]=0;
		else
		return dp[pos][more]=f(pos-1, more-1);
	}
	else
	if(more==0)
	return dp[pos][more]=f(pos-1, 1);
	else
	return dp[pos][more]=f(pos-1, more+1)+f(pos-1, more-1);
}

int main()
{
	int N, K, T;
	sfi(T);
	
	while(T--)
	{
		memset(dp, -1, sizeof dp);
		sfi(N), sfi(K);
		
		int x;
		
		rep(i, K)
		sfi(x), POS[x]=true;
		
		pfi(f(2*N, 0));
		
		memset(POS, 0, sizeof POS);
	}
	
	return (0);
}