// Author : Bony Roopchandani
// 

// INCLUDES
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
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

int pos[10][1000+5];
VI a[1000+5];
int maxx;
bool vis[1000+5]={0};
int cost[1000+5]={0};

void dfs(int u)
{
	vis[u]=1;
	
	rep(i, a[u].sz)
	{
		if(!vis[a[u][i]])
		dfs(a[u][i]);
		cost[u]=max(cost[u], cost[a[u][i]]+1);
	}
	cost[u]=max(1, cost[u]);
	maxx=max(cost[u], maxx);
}

int main(void)
{
	int n, k, x;
	sfi(n), sfi(k);
	
	rep(i, k) rep(j, n) sfi(x), pos[i][x]=j;
	
	rept(i, 1, n) rept(j, 1, n) {
		if(i != j)
		{
			int cnt=0;
			
			rep(p, k)
			{
				if(pos[p][i]<pos[p][j])
				cnt++;
				else
				break;
			}
			
			if(cnt==k)
			a[i].pb(j);
		}
	}
	
	maxx=0;
	
	rept(i, 1, n) {
		if(!vis[i]) dfs(i);
	}
	
	pfl(maxx);
	
	return (0);
}