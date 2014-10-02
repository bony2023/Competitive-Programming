// Author : Bony Roopchandani
// 10651 - Pebble Solitaire
// DP+Bitmask

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

int dp[1<<12];

int F(int bitmask)
{
	if(__builtin_popcount(bitmask)<2)
	return __builtin_popcount(bitmask);
	
	if(dp[bitmask] != -1)
	return dp[bitmask];

	int ans=__builtin_popcount(bitmask);
	
	rep(i, 12)
	{
		if((bitmask & (1<<i)) && (bitmask & (1<<(i+1))) && (i+1)<12)
		{
			if(!(bitmask & (1<<(i-1))) && (i-1)>=0)
			{
				int x=bitmask;
				x |= (1<<(i-1));
				x &= ~(1<<(i+1));
				x &= ~(1<<i);
				ans=min(ans, F(x));
			}
			
			if(!(bitmask & (1<<(i+2))) && (i+2)<12)
			{
				int x=bitmask;
				x |= (1<<(i+2));
				x &= ~(1<<i);
				x &= ~(1<<(i+1));
				ans=min(ans, F(x));
			}
		}
	}
	return dp[bitmask]=ans;
}

int main(void)
{
//	in("input.txt");
	
	int T; sfi(T);
	char str[20];
	
	while(T--)
	{
		sfs(str);
		
		int bit=0;
		
		for(int i=strlen(str)-1, j=0; i>=0; i--, j++)
		{
			if(str[i]=='o')
			{
				bit |= (1<<j);
			}
		}
		
		memset(dp, -1, sizeof dp);
		pfi(F(bit));
	}
	
	return (0);
}