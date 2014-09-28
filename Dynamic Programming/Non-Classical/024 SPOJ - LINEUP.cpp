// Author : Bony Roopchandani
// LINEUP
// DP+Bitmasking

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

int dp[12][1<<12];

class LINEUP
{
	int A[12][12];
	
	public:
	
	void process()
	{
		memset(dp, -1, sizeof dp);
		
		rep(i, 11)
		rep(j, 11)
		sfi(A[i][j]);
		
		pfi(count(0, 0));
	}
	
	int count(int pos, int mask)
	{
		if(pos==11)
		{
			if(mask==(1<<11)-1)
			return 0;
			
			return -INF;
		}
		
		if(dp[pos][mask] != -1)
		return dp[pos][mask];
		
		int b=-INF;
		
		rep(i, 11)
		{
			int a=0;
			if(A[pos][i] && !(mask & (1<<i)))
			{
				a=A[pos][i]+count(pos+1, mask | (1<<i));
				b=max(a, b);
			}
		}
		
		return dp[pos][mask]=b;
	}
};

int main()
{
	int T; sfi(T);
	
	while(T--)
	{
		LINEUP L;
		L.process();
	}
	
	return (0);
}