// Author : Bony Roopchandani
// 532 - Dungeon Master
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

int A[28000], L, R, C, dist[28000];

int BFS(int u, int v)
{
	int vis[28000];
	int t;
	
	rep(i, L*R*C)
	vis[i]=0, dist[i]=INF;
	
	vis[u]=1;
	dist[u]=0;
	
	queue<int>Q;
	Q.push(u);
	
	while(!Q.empty())
	{
		int z=Q.front();
		
		if(z==v)
		return dist[v];
	
		Q.pop();
		
		t=(z/C)%R;
		
		if((z+C)<L*R*C && A[z+C] && !vis[z+C] && t != R-1)
		{
			vis[z+C]=1;
			if(dist[z+C]>dist[z]+1)
			dist[z+C]=dist[z]+1;
			Q.push(z+C);
		}
		
		if((z-C)>=0 && A[z-C] && !vis[z-C] && t != 0)
		{
			vis[z-C]=1;
			if(dist[z-C]>dist[z]+1)
			dist[z-C]=dist[z]+1;
			Q.push(z-C);
		}
		
		if((z+1)<L*R*C && A[z+1] && !vis[z+1] && (z+1)%C!=0)
		{
			vis[z+1]=1;
			if(dist[z+1]>dist[z]+1)
			dist[z+1]=dist[z]+1;
			Q.push(z+1);
		}
		
		if((z-1)>=0 && A[z-1] && !vis[z-1] && z%C!=0)
		{
			vis[z-1]=1;
			if(dist[z-1]>dist[z]+1)
			dist[z-1]=dist[z]+1;
			Q.push(z-1);
		}
		
		if((z+R*C)<L*R*C && A[z+R*C] && !vis[z+R*C])
		{
			vis[z+R*C]=1;
			if(dist[z+R*C]>dist[z]+1)
			dist[z+R*C]=dist[z]+1;
			Q.push(z+R*C);
		}
		
		if((z-R*C)>=0 && A[z-R*C] && !vis[z-R*C])
		{
			vis[z-R*C]=1;
			if(dist[z-R*C]>dist[z]+1)
			dist[z-R*C]=dist[z]+1;
			Q.push(z-R*C);
		}
	}
	
	return dist[v];
}

int main(void)
{
//	freopen("input.txt", "r", stdin);
	while(1)
	{
		sfi(L); sfi(R); sfi(C);
		getchar();
		
		if(!L && !R && !C)
		break;
		
		int z=0;
		int s, e;
		char foo[35];
		
		rep(i, L)
		{
			rep(j, R)
			{
				sfs(foo);
					rep(k, C)
					{
						if(foo[k]=='S' || foo[k]=='E' || foo[k]=='.')
						A[z]=1;
						else A[z]=0;
						
						if(foo[k]=='S')
						s=z;
						if(foo[k]=='E')
						e=z;
						
						z++;
					}
			}
			getchar();
		}
	
		
		z=BFS(e, s);
		
		if(z>=INF)
		pfs("Trapped!");
		else
		printf("Escaped in %d minute(s).\n",z);
	}
	return 0;
}