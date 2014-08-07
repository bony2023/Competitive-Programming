// Author : Bony Roopchandani
// 567 - Risk
// BFS

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
#define pb push_back
#define sz size()
#define mp make_pair
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
typedef vector<long long> VL;
typedef pair<int, int> PI;

VI AL[21];

int BFS(int a, int b)
{
	int visited[21], dist[22];
	
	rep(i, 22) dist[i]=INF;
	
	memset(visited, 0, sizeof(visited));
	
	dist[a]=0;
	queue<int>Q;
	Q.push(a);
	visited[a]=1;
	
	VI::iterator t;
	
	while(!Q.empty())
	{
		int z=Q.front();
		Q.pop();
		
		for(t=AL[z].begin(); t!=AL[z].end(); t++)
		{
			int x=*t;
			
			if(!visited[x])
			{
				visited[x]=1;
				Q.push(x);
				
				if(dist[x]>dist[z]+1)
				dist[x]=dist[z]+1;
			}
			
			if(x==b)
			return dist[b];
		}
	}
}
	

int main(void)
{
	int c=1;
	
	int N;
	
	while(sfi(N)!=EOF)
	{
		int k=1, temp;
		
		rep(i, N)
		{
			sfi(temp);
			AL[k].pb(temp);
			AL[temp].pb(k);
		}
		
		rept(i, 2, 19)
		{
			k=i;
			sfi(N);
			rep(j, N)
			{
				sfi(temp);
				AL[k].pb(temp);
				AL[temp].pb(k);
			}
		}
		
		sfi(N);
		int a, b, P;
		
		printf("Test Set #%d\n",c);
		c++;
		
		rep(i, N)
		{
			sfi(a);
			sfi(b);
			
			P=BFS(a,b);
			
			printf("%2d to %2d: %d\n",a, b, P);
		}
		
		rept(i, 0, 20)
		AL[i].clear();
		
		nl;
	}
	
	return 0;
}