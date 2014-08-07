// Author : Bony Roopchandani
// 10959 - The Party, Part I
// BFS

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<list>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
#define pb push_back
#define sz size()
#define mp make_pair
#define ff first
#define ss second
#define bg begin()
#define en end()
#define rep(i, n) for(int i=0; i<n; i++)
#define repi(i, n) for(int i=0; i<=n; i++)
#define rept(i, a, b) for(int i=a; i<=b; i++)
#define repd(i, a, b) for(int i=a; i>=b; i--)
#define ll long long
#define repl(i, n) for(ll i=0; i<n; i++)
#define repli(i, n) for(ll i=0; i<=n; i++)
#define pfi(a) printf("%d\n",a)
#define sfi(a) scanf("%d",&a)
#define pfl(a) printf("%lld\n",(ll)a)
#define sfl(a) scanf("%lld",&a)
#define sfs(a) scanf("%s",a)
#define pfs(a) printf("%s\n",a)
#define pf(a) printf("%d ",a)
#define nl printf("\n")
#define INF 9999999
#define MOD 1000000007
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PII;
typedef pair<int, ll> PIL;
typedef pair<ll, int> PLI;
typedef map<int, int> MII;
typedef map<ll, int> MLI;
typedef map<int, ll> MIL;
typedef list<int> LI;
typedef list<ll> LL;

VI A[1001];
int dist[1001], P;

void BFS(int u)
{
	int vis[1001];
	
	rep(i, P)
	dist[i]=INF, vis[i]=0;
	
	dist[u]=0;
	vis[u]=1;
	
	queue<int>Q;
	Q.push(u);
	
	while(!Q.empty())
	{
		int z=Q.front();
		Q.pop();
		
		int s=A[z].sz;
		
		rep(i, s)
		{
			if(!vis[A[z][i]])
			{
				vis[A[z][i]]=1;
				if(dist[A[z][i]]>dist[z]+1)
				dist[A[z][i]]=dist[z]+1;
				Q.push(A[z][i]);
			}
		}
	}
}

int main(void)
{
//	freopen("input.txt", "r", stdin);
	int T; sfi(T);
	int C=0;
	
	while(T--)
	{
		getchar();
		
		int D, x, y;
		
		sfi(P); sfi(D);
		
		rep(i, D)
		{
			sfi(x); sfi(y);
			A[x].pb(y);
			A[y].pb(x);
		}
		
		BFS(0);
		
		if(C>=1)
		nl;
		
		rept(i, 1, P-1)
		{
			pfi(dist[i]);
		}
		
		C++;
		
		rep(i, P)
		A[i].clear();
	}
	return 0;
}