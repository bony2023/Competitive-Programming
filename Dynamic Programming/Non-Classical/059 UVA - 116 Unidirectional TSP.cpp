// Author : Bony Roopchandani
// 116 - Unidirectional TSP
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

bool vis[10+5][100+5];
int A[10+5][100+5], R, C, s;
ll dp[10+5][100+5], mn;
int P[10+5][100+5];

bool valid(int a, int b)
{
	return ((a>=0 && a<R) && (b>=0 && b<C));
}

ll F(int a, int b)
{
	if(b>=C)
	return 0;
	else if(valid(a, b) && vis[a][b])
	return dp[a][b];
	else
	{
		int x=(a-1+R)%R;
		int y=a;
		int z=(a+1)%R;
		vis[a][b]=1;
		
		int p=F(x, b+1);
		int q=F(y, b+1);
		int r=F(z, b+1);
		
		int w=x;
		
		if(q<p || (q==p && w>y))
		w=y, p=q;
		
		if(r<p || (r==p && w>z))
		w=z, p=r;
		
		P[a][b]=w;
		dp[a][b]=A[a][b]+p;
		
		return dp[a][b];
	}
}

void PrintPath(int a, int b)
{
	if(b==C-1)
	{
		printf(" %d", a+1);
		return;
	}
	
	if(!b)
	printf("%d", a+1);
	else printf(" %d", a+1);
	
	PrintPath(P[a][b], b+1);
}

int main(void)
{
//	freopen("input.txt", "r", stdin);
	
	ll p;
	
	while(cin>>R>>C)
	{
		memset(vis, 0, sizeof vis);
		
		rep(i, R)
		rep(j, C)
		sfi(A[i][j]);
		
		mn=INF<<2;
		
		rep(i, R)
		{
			p=F(i, 0);
			
			if(mn>p)
			mn=p, s=i;
		}
		
		if(C==1)
		pfi(s+1);
		else
		PrintPath(s, 0), nl;
		pfl(mn);
	}
	return (0);
}