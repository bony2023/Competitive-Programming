// Author : Bony Roopchandani
// TOURIST
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
#define in(x) freopen(x, "r", stdin)
#define ll long long
#define mp make_pair
#define nl printf("\n")
#define out(x) freopen(x, "w", stdout)
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

char foo[100+5][100+5];
int dp[100+5][100+5][100+5];
int R, C;

int cost(int x1, int y1, int x2, int y2)
{
	if(x1==x2 && y1== y2)
	{
		if(foo[x1][y1]=='*')
		return 1;
		else
		return 0;
	}
	
	int f=0;
	
	if(foo[x1][y1]=='*') f++;
	if(foo[x2][y2]=='*') f++;
	
	return f;
}

int F(int x1, int y1, int x2)
{
	int y2=(x1+y1)-x2;
	
	if(x1==R-1 && y1==C-1 && x2==R-1 && y2==C-1)
	return 0;
	
	else if(x1>=R || x2>=R || y1>=C || y2>=C)
	return -INF;
	
	else if(dp[x1][y1][x2] != -1)
	return dp[x1][y1][x2];
	
	int ans=-INF;
	
	if(foo[x1][y1+1] != '#' && foo[x2+1][y2] != '#')
	ans=cost(x1, y1+1, x2+1, y2)+F(x1, y1+1, x2+1);
	
	if(foo[x1][y1+1] != '#' && foo[x2][y2+1] != '#')
	ans=max(ans, cost(x1, y1+1, x2, y2+1)+F(x1, y1+1, x2));
	
	if(foo[x1+1][y1] != '#' && foo[x2][y2+1] != '#')
	ans=max(ans, cost(x1+1, y1, x2, y2+1)+F(x1+1, y1, x2));
	
	if(foo[x1+1][y1] != '#' && foo[x2+1][y2] != '#')
	ans=max(ans, cost(x1+1, y1, x2+1, y2)+F(x1+1, y1, x2+1));
	
	return dp[x1][y1][x2]=ans;
}

int main(void)
{
	int T; sfi(T);
	
	while(T--)
	{
		sfi(C), sfi(R);
		
		memset(dp, -1, sizeof dp);
		
		rep(i, R)
		sfs(foo[i]);
		
		int ans=0;
		
		if(foo[0][0]=='*') ans++, foo[0][0]='.';
		
		if(foo[R-1][C-1]=='*') ans++, foo[R-1][C-1]='.';
		
		ans+=F(0, 0, 0);
		
		pfi(max(0, ans));
	}
	
	return (0);
}