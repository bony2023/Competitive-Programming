// Author : Bony Roopchandani
// UPSUB
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

int n;
char foo[100+5];
int mx=0;
vector<int> Hash[100+5];
char tmp[100+5];

bool cmp(int x, int y)
{
	return foo[x]<=foo[y];
}

void compute_lis()
{
	int dp[n+5];
	dp[0]=1;
	int j;
	
	rept(i, 1, n-1)
	{
		j=0;
		
		rep(k, i)
		{
			if(foo[i]>=foo[k])
			j=max(dp[k], j);
		}
		
		dp[i]=j+1;
		mx=max(dp[i], mx);
	}
	
	rep(i, n)
	Hash[dp[i]].pb(i);
	
	rept(i, 1, mx)
		sort(all(Hash[i]), cmp);
}

void get(int k, char prev, int prevv)
{
	if(k==mx+1)
	{
		tmp[k-1]=0;
		puts(tmp);
	}
	
	rep(i, Hash[k].sz)
	{
		if(Hash[k][i]>prevv && foo[Hash[k][i]]>=prev)
		{
			tmp[k-1]=foo[Hash[k][i]];
			get(k+1, foo[Hash[k][i]], Hash[k][i]);
		}
	}
}

int main(void)
{
	int T; sfi(T);
	
	while(T--)
	{
		sfs(foo);
		n=strlen(foo);
		compute_lis();
		get(1, 0, -1);
		nl;
		
		rep(i, 100+3)
		Hash[i].clear();
		mx=0;
	}
	return (0);
}