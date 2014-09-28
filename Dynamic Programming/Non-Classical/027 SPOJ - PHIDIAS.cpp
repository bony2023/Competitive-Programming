// Author : Bony Roopchandani
// PHIDIAS
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

class Phidias
{
	int W[200+5], H[200+5];
	int dp[600+5][600+5];
	int N, ans;
	
	public:
	
	void process()
	{
		int w, h;
		sfi(w), sfi(h);
		
		memset(dp, -1, sizeof dp);
		
		sfi(N);
		ans=INF;
		
		rep(i, N)
		sfi(W[i]), sfi(H[i]);
		
		pfi(count(w, h));
	}
	
	int count(int w, int h)
	{
		if(dp[w][h] != -1)
		return dp[w][h];
		
		int ans=w*h;
		
		rep(i, N)
		{
			if(W[i]>w || H[i]>h)
			continue;
			
			ans=min(ans, (count(w, h-H[i])+count(w-W[i], H[i])));
			
			ans=min(ans, (count(w-W[i], h)+count(W[i], h-H[i])));
		}
		
		return dp[w][h]=ans;
	}
};

int main()
{
	int T; sfi(T);
	
	while(T--)
	{
		Phidias P;
		P.process();
	}
	
	return (0);
}