// Author : Bony Roopchandani
// STAR3CAS
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

int N;
int foo[25];
int dist[25];

//dist, steps, N;

int BFS()
{
	int vis[25]={0};
	
	queue<pair<int, PII> >Q;
	Q.push(mp(0, mp(foo[0], 0)));
	vis[0]=1;
	dist[0]=0;
	
	while(!Q.empty())
	{
		pair<int, PII>z=Q.front();
		Q.pop();
		int D=z.ff;
		int S=z.ss.ff;
		int n=z.ss.ss;
		
		int a=n+1;
		
		if(a<=N && a>=0 && !vis[a])
		{
			vis[a]=1;
			dist[a]=D+1;
			if(a==N)
			return dist[a];
			Q.push(mp(D+1, mp(foo[a], a)));
		}
		
		a=n+foo[n];
		if(a<=N && a>=0 && !vis[a])
		{
			vis[a]=1;
			dist[a]=D+1;
			if(a==N)
			return dist[a];
			Q.push(mp(D+1, mp(foo[a], a)));
		}
	}
	return -1;
}

int main(void)
{
//	freopen("input.txt", "r", stdin);
	int T; sfi(T);
	
	while(T--)
	{
		sfi(N);
		
		rep(i, N)
		sfi(foo[i]);
		
		pfi(BFS());
	}
	
	return 0;
}