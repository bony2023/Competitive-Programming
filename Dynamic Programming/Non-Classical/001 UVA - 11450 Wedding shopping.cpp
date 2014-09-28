// Author : Bony Roopchandani
// 11450 - Wedding shopping
// DP - Top Down Approach

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

class Wedding
{
	int dp[200+5][20+5];
	int A[20+5][20+5];
	int M, C;
	
	public:
	
	Wedding()
	{
		rep(i, 200+5)
		fill(dp[i], dp[i]+20+5, -1);
	}
	
	void process()
	{
		sfi(M), sfi(C);
		
		rep(i, C)
		{
			sfi(A[i][0]);
			
			rept(j, 1, A[i][0])
			sfi(A[i][j]);
		}
		
		int P=get(M, 0);
		
		if(P<0)
		puts("no solution");
		else
		pfi(P);
	}
	
	int get(int CMoney, int CItem)
	{
		if(CMoney<0)
		return -INF;
		
		if(CItem==C)
		return M-CMoney;
		
		if(dp[CMoney][CItem] != -1)
		return dp[CMoney][CItem];
		
		int ans=-INF;
		
		rept(j, 1, A[CItem][0])
		{
			ans=max(ans, get(CMoney-A[CItem][j], CItem+1));
		}
		
		return dp[CMoney][CItem]=ans;
	}
};

int main()
{
//	freopen("input.txt", "r", stdin);
	
	int T; sfi(T);
	
	while(T--)
	{
		Wedding W;
		W.process();
	}
	return (0);
}