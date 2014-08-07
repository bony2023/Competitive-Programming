// Author : Bony Roopchandani
// 10596 - Morning Walk
// Euler Tour

// INCLUDES
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <map>
#include <list>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

// MACROS
#define pb push_back
#define sz size()
#define mp make_pair
#define ff first
#define ss second
#define bg begin()
#define en end()
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i=0; i<n; i++)
#define rept(i, a, b) for(int i=a; i<=b; i++)
#define repd(i, a, b) for(int i=a; i>=b; i--)
#define ll long long
#define repl(i, n) for(ll i=0; i<n; i++)
#define replt(i, a, b) for(ll i=a; i<=b; i++)
#define repld(i, a, b) for(ll i=a; i>=b; i--)
#define pfi(a) printf("%d\n",a)
#define sfi(a) scanf("%d",&a)
#define pfl(a) printf("%lld\n",(ll)a)
#define sfl(a) scanf("%lld",&a)
#define sfs(a) scanf("%s",a)
#define pfs(a) printf("%s\n",a)
#define pf(a) printf("%d ",a)
#define nl printf("\n")
#define INF 9999999
#define MOD (1e9 + 7)

// TYPEDEFS
typedef vector < int > VI;
typedef vector < ll > VLL;
typedef vector < string > VS;
typedef pair < int, int > PII;
typedef pair < int, PII > PIII;
typedef pair < int, PIII > PIIII;
typedef pair < int, ll > PIL;
typedef pair < ll, int > PLI;
typedef map < int, int > MII;
typedef map < ll, int > MLI;
typedef map < int, ll > MIL;
typedef map < int, bool > MIB;
typedef list < int > LI;
typedef list < ll > LLL;
typedef set < int > SI;
typedef set < ll > SLL;

class Euler
{
	VI* A;
	bool* vis;
	int V, M;
	
	public:
	
	Euler(int N, int Q)
	{
		A = new VI[N+5];
		vis = new bool[N+5]();
		V=N;
		M=Q;
	}
	
	~Euler()
	{
		delete []A;
		delete []vis;
	}
	
	void process()
	{
		bool  cond=true;
		int x, y;
		
		rep(i, M)
		{
			sfi(x), sfi(y);
			A[x].pb(y);
			A[y].pb(x);
		}
		
		rep(i, V)
		{
			if(A[i].sz & 1)
			{
				cond=false;
				break;
			}
		}
		
		if(cond && Connected())
		puts("Possible");
		else
		puts("Not Possible");
	}
	
	bool Connected()
	{
		int cmp=0;
		
		rep(i, V)
		if(!vis[i] && A[i].sz)
		cmp++, dfs(i);
		
		if(cmp!=1)
		return false;
		
		return true;
	}
	
	void dfs(int u)
	{
		vis[u]=1;
		
		rep(i, A[u].sz)
		if(!vis[A[u][i]])
		dfs(A[u][i]);
	}
};

int main()
{
//	freopen("input.txt", "r", stdin);
	
	int N, M;
	
	while(scanf("%d %d",&N, &M)==2)
	{
		Euler E(N, M);
		E.process();
	}
	
	return 0;
}