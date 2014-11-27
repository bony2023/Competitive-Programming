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

ll ansL1, ansB1, ansL2, ansB2;

struct node
{
	ll a, b, c, d;
	int cnt;
	
	node() {}
	
	node(ll A, ll B, ll C, ll D, int count)
	{
		a=A, b=B, c=C, d=D, cnt=count;
	}
};

map<pair<ll, pair<ll, pair<ll, ll> > >, bool> vis;

int BFS(ll& u1, ll& u2, ll& u3, ll& u4)
{
	queue<node> Q;
	Q.push(node(u1, u2, u3, u4, 0));
	vis[mp(u1, mp(u2, mp(u3, u4)))]=1;
	
	while(!Q.empty())
	{
		node z=Q.front(); Q.pop();
		
		if((z.a*z.b)==(z.c*z.d))
		{
			ansL1=z.a, ansB1=z.b, ansL2=z.c, ansB2=z.d;
			return z.cnt;
		}
		
		if((z.a*z.b)>(z.c*z.d))
		{
			if(z.a%2==0)
			{
				if(!vis[mp(z.a/2, mp(z.b, mp(z.c, z.d)))])
				{
					Q.push(node(z.a/2, z.b, z.c, z.d, z.cnt+1));
					vis[mp(z.a/2, mp(z.b, mp(z.c, z.d)))]=1;
				}
			}
			else if(z.b%2==0)
			{
				if(!vis[mp(z.a, mp(z.b/2, mp(z.c, z.d)))])
				{
					Q.push(node(z.a, z.b/2, z.c, z.d, z.cnt+1));
					vis[mp(z.a, mp(z.b/2, mp(z.c, z.d)))]=1;
				}
			}
				
			if(z.a%3==0)
			{
				if(!vis[(mp((z.a/3)*2, mp(z.b, mp(z.c, z.d))))])
				{
					Q.push(node((z.a/3)*2, z.b, z.c, z.d, z.cnt+1));
					vis[mp((z.a/3)*2, mp(z.b, mp(z.c, z.d)))]=1;
				}
			}
			else if(z.b%3==0)
			{
				if(!vis[mp(z.a, mp((z.b/3)*2, mp(z.c, z.d)))])
				{
					Q.push(node(z.a, (z.b/3)*2, z.c, z.d, z.cnt+1));
					vis[mp(z.a, mp((z.b/3)*2, mp(z.c, z.d)))]=1;
				}
			}
		}
		else
		{
			if(z.c%2==0)
			{
				if(!vis[mp(z.a, mp(z.b, mp(z.c/2, z.d)))])
				{
					Q.push(node(z.a, z.b, z.c/2, z.d, z.cnt+1));
					vis[mp(z.a, mp(z.b, mp(z.c/2, z.d)))]=1;
				}
			}
			else if(z.d%2==0)
			{
				if(!vis[mp(z.a, mp(z.b, mp(z.c, z.d/2)))])
				{
					Q.push(node(z.a, z.b, z.c, z.d/2, z.cnt+1));
					vis[mp(z.a, mp(z.b, mp(z.c, z.d/2)))]=1;
				}
			}
				
			if(z.c%3==0)
			{
				if(!vis[mp(z.a, mp(z.b, mp((z.c/3)*2, z.d)))])
				{
					Q.push(node(z.a, z.b, (z.c/3)*2, z.d, z.cnt+1));
					vis[mp(z.a, mp(z.b, mp((z.c/3)*2, z.d)))]=1;
				}
			}
			else if(z.d%3==0)
			{
				if(!vis[mp(z.a, mp(z.b, mp(z.c, (z.d/3)*2)))])
				{
					Q.push(node(z.a, z.b, z.c, (z.d/3)*2, z.cnt+1));
					vis[mp(z.a, mp(z.b, mp(z.c, (z.d/3)*2)))]=1;
				}
			}
		}
	}
}

typedef unsigned ll uLL;

bool notPossible(uLL a, uLL b, uLL c, uLL d)
{
	a*=b, c*=d;
	
	while(a%2==0)
		a/=2;
	
	while(c%2==0)
		c/=2;
		
	while(a%3==0)
		a/=3;
		
	while(c%3==0)
		c/=3;
		
	if(a==c) return false;
	
	return true;
}

int main(void)
{
	ll a, b, c, d;
	sfl(a), sfl(b), sfl(c), sfl(d);
	
	if(notPossible(a, b, c, d))
	{
		pfi(-1);
		return 0;
	}
	
	pfi(BFS(a, b, c, d));
	printf("%lld %lld\n%lld %lld\n", ansL1, ansB1, ansL2, ansB2);
	
	return (0);
}