// Author : Bony Roopchandani
// MAXWOODS
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

int dp[2][200+5][200+5];
int R, C;
char foo[200+5][200+5];

bool valid(int i, int j)
{
	return (i>=0 && j>=0 && i<R && j<C && foo[i][j] != '#');
}

int F(int curr, int i, int j)
{
	if(!valid(i, j))
	return 0;
	
	int& ans=dp[curr][i][j];
	
	if(ans != -1)
	return ans;
	
	if(foo[i][j]=='T')
	{
		ans=1;
	}
	else ans=0;
	
	ans+=max(F(1-curr, i+1, j), F(curr, i, j-(2*curr)+1));
		
	return ans;
}

int main(void)
{
//	in("input.txt");
	
	int T; sfi(T);
	
	while(T--)
	{
		sfi(R), sfi(C);
		
		memset(dp, -1, sizeof dp);

		rep(i, R)
		sfs(foo[i]);
		
		int P=F(0, 0, 0);
		
		if(P<=0)
		pfi(0);
		else pfi(P);
	}
	
	return (0);
}