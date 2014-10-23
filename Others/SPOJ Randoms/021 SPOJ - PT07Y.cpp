// Author : Bony Roopchandani
// PT07Y
// Union Find

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

VI P;
int TotSet;

void initSet(int N)
{
	P.assign(N+1, 0);
	TotSet=N;
	
	rept(i, 1, N)
	P[i]=i;
}

int findParent(int V)
{
	return (P[V]==V)?V:P[V]=findParent(P[V]);
}

bool SameSet(int a, int b)
{
	return findParent(a)==findParent(b);
}

void UnionSet(int a, int b)
{
	P[b]=findParent(a);
	TotSet--;
}

bool vis[10005][10005]={0};

int main(void)
{
	int N, M, x ,y;
	bool isCyclic=false;
	sfi(N), sfi(M);
	
	initSet(N);
	
	rep(i, M)
	{
		sfi(x), sfi(y);
		
		if(vis[x][y]) continue;
		
		if(!SameSet(x, y))
		UnionSet(x, y);
		else
		isCyclic=true;
		
		vis[x][y]=vis[y][x]=true;
	}
	
	if(!isCyclic && TotSet==1)
	puts("YES");
	else
	puts("NO");
	
	return (0);
}