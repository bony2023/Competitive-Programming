// Author : Bony Roopchandani
// 383 Shipping Routes
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

map<string, vector<string> >A;

int BFS(string S, string E)
{
	map<string, bool>vis;
	map<string, int>dist;
	queue<string>Q;
	
	Q.push(S);
	dist[S]=0;
	vis[S]=1;
	
	while(!Q.empty())
	{
		string z=Q.front();
		if(z==E)
		return dist[E];
		Q.pop();
		
		int s=A[z].sz;
		
		rep(i, s)
		{
			if(!vis[A[z][i]])
			{
				dist[A[z][i]]=INF;
				vis[A[z][i]]=1;
				if(dist[A[z][i]]>dist[z]+1)
				dist[A[z][i]]=dist[z]+1;
				Q.push(A[z][i]);
			}
		}
	}
	return INF;
}

int main(void)
{
//	freopen("input.txt", "r", stdin);
	int T, o=0;
	sfi(T);
	
	while(T--)
	{
		if(o==0)
		pfs("SHIPPING ROUTES OUTPUT"), o=1;
		
		int N, L, Q;
		sfi(N); sfi(L); sfi(Q);
		
		string a, b;
		
		rep(i, N)
		cin>>a;
		
		rep(i, L)
		{
			cin>>a>>b;
			A[a].pb(b);
			A[b].pb(a);
		}
		
		printf("\nDATA SET  %d\n\n",o++);
		int s;
		
		rep(i, Q)
		{
			cin>>s>>a>>b;
			int P=BFS(a, b);
			
			if(P>=INF)
			pfs("NO SHIPMENT POSSIBLE");
			else
			printf("$%d\n",P*s*100);
		}
		
		A.clear();
		
		if(T==0)
		pfs("\nEND OF OUTPUT");
	}
	
	return 0;
}