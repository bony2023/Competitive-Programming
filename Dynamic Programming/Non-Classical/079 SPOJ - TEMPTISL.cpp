// Author : Bony Roopchandani
// TEMPTISL
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

int N, K, A, B;
ll dp[50+5][50+5];

ll F(int currVertex, int totVis)
{
	if(totVis>K)
	return 0;
	
	if(currVertex>N)
	currVertex-=N;
	
	if(currVertex<1)
	currVertex+=N;
	
	if(totVis==K && currVertex==B)
	return 1;
	
	if(dp[totVis][currVertex] != -1)
	return dp[totVis][currVertex];
	
	return dp[totVis][currVertex]=F(currVertex+1, totVis+1)+F(currVertex-1, totVis+1);
}

int main(void)
{
	while(1)
	{
		sfi(N), sfi(K);
		
		if(N==-1 && K==-1)
		break;
		
		memset(dp, -1, sizeof dp);
		
		sfi(A), sfi(B);
		
		pfl(F(A, 0));
	}
	
	return (0);
}