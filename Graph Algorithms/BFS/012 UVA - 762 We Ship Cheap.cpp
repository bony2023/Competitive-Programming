// Author : Bony Roopchandani
// 762 - We Ship Cheap
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

map<string, vector<string> >A;
map<string, string>pred;
vector<string>path;

int BFS(string u, string v)
{
	map<string, bool>vis;
	map<string, int>dist;
	dist[u]=0;
	vis[u]=1;
	
	queue<string>Q;
	Q.push(u);
	
	while(!Q.empty())
	{
		string z=Q.front();
//		cout<<z<<endl;
		if(z==v)
		return dist[v];
		Q.pop();
		
		int i=A[z].sz;
		rep(k, i)
		{
			if(!vis[A[z][k]])
			{
				dist[A[z][k]]=INF;
				vis[A[z][k]]=1;
				if(dist[A[z][k]]>dist[z]+1)
				dist[A[z][k]]=dist[z]+1;
				Q.push(A[z][k]);
				pred[A[z][k]]=z;
			}
		}
	}
	
	return INF;
}

void print(string a, string b)
{
	if(b==a)
	return;
	
	print(a, pred[b]);
	path.pb(pred[b]);
}

int main(void)
{
//	freopen("input.txt","r",stdin);
	int N, q=1;
	
	while(sfi(N)!=EOF)
	{
		string a, b;
		rep(i, N)
		{
			cin>>a>>b;
			
			A[a].pb(b);
			A[b].pb(a);
		}
		
		cin>>a>>b;
	
		int p=BFS(a, b);
		
		if(q>1)
		nl;
		
		if(p>=INF)
		pfs("No route");
		else
		{
    		print(a, b);
    		int q=path.sz;
    		
    		rep(i, q-1)
    		{
    			cout<<path[i]<<" "<<path[i+1]<<"\n";
    		}
    		cout<<path[q-1]<<" "<<b<<"\n";
		}
		getchar();
		q++;
		
		A.clear();
		path.clear();
		pred.clear(); 
	}
	return 0;
}