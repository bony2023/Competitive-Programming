// Author : Bony Roopchandani
// 439 - Knight Moves
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
#define f first
#define s second
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

int BFS(PI u, PI v)
{
	queue<PI>Q;
	int visited[10][10], dist[10][10];
	
	memset(visited, 0, sizeof(visited));
	memset(dist, INF, sizeof(dist));
	
	visited[u.f][u.s]=1;
	dist[u.f][u.s]=0;
	Q.push(u);
	
	while(!Q.empty())
	{
		PI z=Q.front();
		Q.pop();
		
		if(z.f==v.f && z.s==v.s)
		return dist[z.f][z.s];
		
		int i, j;
		
		i=z.f-2;
		j=z.s-1;
		
		if(i>0 && i<=8 && j>0 && j<=8 && !visited[i][j])
		{
			visited[i][j]=1;
			Q.push(mp(i,j));
			
			if(dist[i][j]>dist[z.f][z.s]+1)
			dist[i][j]=dist[z.f][z.s]+1;
		}
		
		i=z.f-2;
		j=z.s+1;
		
		if(i>0 && i<=8 && j>0 && j<=8 && !visited[i][j])
		{
			visited[i][j]=1;
			Q.push(mp(i,j));
			if(dist[i][j]>dist[z.f][z.s]+1)
			dist[i][j]=dist[z.f][z.s]+1;
		}
		
		i=z.f-1;
		j=z.s-2;
		
		if(i>0 && i<=8 && j>0 && j<=8 && !visited[i][j])
		{
			visited[i][j]=1;
			Q.push(mp(i,j));
			if(dist[i][j]>dist[z.f][z.s]+1)
			dist[i][j]=dist[z.f][z.s]+1;
		}
		
		i=z.f-1;
		j=z.s+2;
		
		if(i>0 && i<=8 && j>0 && j<=8 && !visited[i][j])
		{
			visited[i][j]=1;
			Q.push(mp(i,j));
			if(dist[i][j]>dist[z.f][z.s]+1)
			dist[i][j]=dist[z.f][z.s]+1;
		}
		
		i=z.f+1;
		j=z.s-2;
		
		if(i>0 && i<=8 && j>0 && j<=8 && !visited[i][j])
		{
			visited[i][j]=1;
			Q.push(mp(i,j));
			if(dist[i][j]>dist[z.f][z.s]+1)
			dist[i][j]=dist[z.f][z.s]+1;
		}
		
		i=z.f+1;
		j=z.s+2;
		
		if(i>0 && i<=8 && j>0 && j<=8 && !visited[i][j])
		{
			visited[i][j]=1;
			Q.push(mp(i,j));
			if(dist[i][j]>dist[z.f][z.s]+1)
			dist[i][j]=dist[z.f][z.s]+1;
		}
		
		i=z.f+2;
		j=z.s-1;
		
		if(i>0 && i<=8 && j>0 && j<=8 && !visited[i][j])
		{
			visited[i][j]=1;
			Q.push(mp(i,j));
			if(dist[i][j]>dist[z.f][z.s]+1)
			dist[i][j]=dist[z.f][z.s]+1;
		}
		
		i=z.f+2;
		j=z.s+1;
		
		if(i>0 && i<=8 && j>0 && j<=8 && !visited[i][j])
		{
			visited[i][j]=1;
			Q.push(mp(i,j));
			if(dist[i][j]>dist[z.f][z.s]+1)
			dist[i][j]=dist[z.f][z.s]+1;
		}
	}
}

int main(void)
{
	char str[10];
	int s1, s2, e1, e2;

	while(sfs(str)!=EOF)
	{
		s1=str[0]-96;
		s2=str[1]-'0';
		
		sfs(str);
		
		e1=str[0]-96;
		e2=str[1]-'0';
		
		printf("To get from %c%d to %c%d takes %d knight moves.\n",s1+96, s2, e1+96, e2, BFS(mp(s1,s2), mp(e1,e2)));
	}
	
	return 0;
}