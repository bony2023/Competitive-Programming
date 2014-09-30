// Author : Bony Roopchandani
// PT07X
// Minimum Vertex Cover

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

VI A[100000+5], B[100000+5];
bool vis[100000+5]={0};

void build_tree(int parent)
{
	vis[parent]=1;
	
	rep(i, A[parent].sz)
	{
		int child=A[parent][i];
		
		if(!vis[child])
		{
			B[parent].pb(child);
			build_tree(child);
		}
	}
}

void solve(int u)
{
	rep(i, B[u].sz)
	{
		int z=B[u][i];
		
		solve(z);
		
		if(!vis[u] && !vis[z])
		vis[u]=1;
	}
}

int main(void)
{
	int N; sfi(N);
	int x, y;
	
	rep(i, N-1)
	{
		sfi(x), sfi(y);
		A[x].pb(y);
		A[y].pb(x);
	}
	
	if(N==1)
	{
		pfi(1);
		return 0;
	}
	
	build_tree(1);
	memset(vis, 0, sizeof vis);
	solve(1);
	
	int cnt=0;
	
	rept(i, 1, N)
	if(vis[i])
	cnt++;
	
	pfi(cnt);
	
	return (0);
}