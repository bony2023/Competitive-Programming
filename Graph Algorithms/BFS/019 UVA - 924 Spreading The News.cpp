// Author : Bony Roopchandani
// 924 - Spreading The News
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
typedef pair<int, PII>PIII;
typedef map<int, int> MII;
typedef map<ll, int> MLI;
typedef map<int, ll> MIL;
typedef list<int> LI;
typedef list<ll> LL;

VI A[2502];
int dist[2502], T;

void BFS(int u)
{
	int vis[2502]={0};
	
	rep(i, T+1)
	dist[i]=INF;
	
	dist[u]=0;
	
	queue<int>Q;
	Q.push(u);
	vis[u]=1;
	
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
				dist[A[z][i]]=dist[z]+1;
				Q.push(A[z][i]);
			}
		}
	}
}

int main(void)
{
//	freopen("input.txt", "r", stdin);
	int x, E;
	int max_boom, first_boom;
	int count[2502];
	sfi(E);
	
	rep(i, E)
	{
		int N;
		sfi(N);
		
		rep(j, N)
		sfi(x), A[i].pb(x);
	}
	
	T=E;
	int max;
	sfi(E);
	
	rep(j, E)
	{
		max=0;
		sfi(x);
		BFS(x);
		
		rep(i, T)
		count[i]=0;
		
		rep(i, T)
		{
			if(dist[i]!=INF)
	  	count[dist[i]]++;
	  	if(max<dist[i] && dist[i]!=INF)
	  	max=dist[i];
		}
		
		max_boom=0;
		
		rept(i, 1, max)
		{
			if(max_boom<count[i])
			{
			max_boom=count[i]; first_boom=i;
			}
		}
		
		if(!max_boom || !first_boom)
		pfi(0);
		else
		pf(max_boom), pfi(first_boom);
	}
	
	return 0;
}