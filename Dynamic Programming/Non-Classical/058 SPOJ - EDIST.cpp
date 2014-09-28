// Author : Bony Roopchandani
// EDIST
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

char A[2000+5], B[2000+5];
int dp[2000+5][2000+5];

int diff(int i, int j)
{
	return (A[i]==B[j])?0:1;
}

int F(int a, int b)
{
	rept(i, 0, a)
	dp[i][0]=i;
	
	rept(j, 0, b)
	dp[0][j]=j;
	
	rept(i, 1, a)
	rept(j, 1, b)
	{
		dp[i][j]=min(diff(i-1, j-1)+dp[i-1][j-1], min(1+dp[i-1][j], 1+dp[i][j-1]));
	}
	
	return dp[a][b];
}

int main(void)
{
	int T; sfi(T);
	
	while(T--)
	{
		memset(dp, 0, sizeof dp);
		
		sfs(A), sfs(B);

		pfi(F(strlen(A), strlen(B)));
	}
	
	return (0);
}