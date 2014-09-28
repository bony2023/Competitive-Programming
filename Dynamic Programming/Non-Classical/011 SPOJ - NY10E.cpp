// Author : Bony Roopchandani
// NY10E
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
typedef list < int >LI;
typedef list < ll > LLL;
typedef map < int, bool > MIB;
typedef map < int, int >MII;
typedef map < int, ll > MIL;
typedef map < ll, int >MLI;
typedef pair < int, int >PII;
typedef pair < int, PII > PIII;
typedef pair < int, PIII > PIIII;
typedef pair < int, ll > PIL;
typedef pair < ll, int >PLI;
typedef set < int >SI;
typedef set < ll > SLL;
typedef vector < int >VI;
typedef vector < ll > VLL;
typedef vector < string > VS;

ll dp[70][20];

class DecDigits
{
  public:

	ll count(int N, int K)
	{
		if (N <= 0 || K < 0)
			return 0;

		if (dp[N][K] != -1)
			return dp[N][K];

		ll ans = 0;

		  ans += count(N - 1, K) + count(N, K - 1);

		  return dp[N][K] = ans;
	}
	
	void init()
	{
		ll ans;
		
		rep(i, 71)
		fill(dp[i], dp[i]+11, -1);
		
		rep(i, 10)
		dp[1][i]=1;
		
		rept(i, 1, 70)
		dp[i][0]=1;
		
		count(70, 9);
		
		rept(i, 1, 70)
		{
			ans=0;
			
			rep(j, 10)
			{
				ans+=dp[i][j];
			}
			
			dp[i][10]=ans;
		}
	}
};

int main()
{
	DecDigits D;
	D.init();
	dp[0][10]=0;
	
	int T; sfi(T);
	int C=1, N;
	
	while(T--)
	{
		sfi(N), sfi(N);
		
		pf(C++), pfl(dp[N][10]);
	}
	
	return (0);
}