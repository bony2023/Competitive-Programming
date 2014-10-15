// Author : Bony Roopchandani
// 291 - The House Of Santa Clause
// Backtracking

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

VI A[6];
char P[50];
bool vis[6][6];

void solve(int u, int c)
{
	P[c]=u+'0';
	
	if(c==8)
	{
		P[c+1]='\0';
		puts(P);
		return;
	}
	
	rep(i, A[u].sz)
	{
		int v=A[u][i];
		
		if(!vis[u][v] && !vis[v][u])
		{
			vis[u][v]=vis[v][u]=1;
			solve(v, c+1);
			vis[u][v]=vis[v][u]=0;
		}
	}
}

int main(void)
{
	A[1].pb(2), A[1].pb(3), A[1].pb(5);
	A[2].pb(1), A[2].pb(3), A[2].pb(5);
	A[3].pb(1), A[3].pb(2);
	A[3].pb(4), A[3].pb(5);
	A[4].pb(3), A[4].pb(5);
	A[5].pb(1), A[5].pb(2);
	A[5].pb(3), A[5].pb(4);
	
	memset(vis, 0, sizeof vis);
	
	solve(1, 0);
	
	return (0);
}