// Author : Bony Roopchandani
// 10496 - Collecting Beepers
// DP - TSP

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

int dist[20][20], N;
int dp[14][1<<14];

int TSP(int pos, int bitmask)
{
	if(bitmask==((1<<(N+1))-1))
	return dist[pos][0];
	
	if(dp[pos][bitmask] != -1)
	return dp[pos][bitmask];
	
	int ans=INF<<2;
	
	rept(i, 0, N)
	{
		if(i != pos && !((1<<i)&bitmask))
		{
			ans=min(ans, dist[pos][i]+TSP(i, bitmask | (1<<i)));
		}
	}
	
	return dp[pos][bitmask]=ans;
}

int main()
{
	int T; sfi(T);
	int A, B;
	int X[20], Y[20];
	
	while(T--)
	{
		memset(dp, -1, sizeof dp);
		sfi(A), sfi(B);
		sfi(X[0]), sfi(Y[0]);
		
		sfi(N);
		
		rept(i, 1, N)
		sfi(X[i]), sfi(Y[i]);
		
		rep(i, N+1)
		rep(j, N+1)
		dist[i][j]=abs(X[i]-X[j])+abs(Y[i]-Y[j]);
		
		printf("The shortest path has length %d\n", TSP(0, 1));
	}
	
	return (0);
}