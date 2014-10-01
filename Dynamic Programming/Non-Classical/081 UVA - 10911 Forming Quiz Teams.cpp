// Author : Bony Roopchandani
// 10911 - Forming Quiz Teams
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

double get(int x1, int y1, int x2, int y2)
{
	int a=x2-x1;
	int b=y2-y1;
	
	return hypot(a, b);
}

double dist[20][20];
bool vis[1<<20];
int N;
double dp[1<<20];

double F(int bitmask)
{
	if(bitmask==((1<<(2*N))-1))
	return 0.0;
	
	if(vis[bitmask])
	return dp[bitmask];
	
	vis[bitmask]=1;
	
	double ans=INF<<2;
	
	int i, j;
	
	for(i=0; i<2*N; i++)
	if(!(bitmask & (1<<i)))
	break;
	
	for(j=i+1; j<2*N; j++)
	if(!(bitmask & (1<<j)))
	ans=min(ans, dist[i][j]+F(bitmask | (1<<i) | (1<<j)));
	
	return dp[bitmask]=ans;
}

int main(void)
{
	int cs=1;
	
	while(sfi(N) && N)
	{
		string x;
		int X[2*N], Y[2*N];
		
		rep(i, 2*N)
		{
			cin>>x;
			sfi(X[i]), sfi(Y[i]);
		}
		
		rep(i, 2*N)
		{
			rept(j, i+1, 2*N-1)
			dist[i][j]=get(X[i], Y[i], X[j], Y[j]);
		}
		
		memset(vis, 0, sizeof vis);
		
		printf("Case %d: %.2lf\n", cs++, F(0));
	}
	
	return (0);
}