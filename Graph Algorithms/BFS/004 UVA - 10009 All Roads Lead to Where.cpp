// Author : Bony Roopchandani
// 10009 - All Roads Lead Where?
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

VI A[27];
int pred[26];

void BFS(int u, int v)
{
	int vis[26];

	rep(i, 26)
	pred[i]=-1, vis[i]=0;
	
	queue<int>Q;
	vis[u]=1;
	Q.push(u);
	
	while(!Q.empty())
	{
		int z=Q.front();
		if(z==v) return;
		Q.pop();
		
		rep(i, A[z].sz)
		{
			if(!vis[A[z][i]])
			{
				vis[A[z][i]]=1;
				pred[A[z][i]]=z;
				Q.push(A[z][i]);
			}
		}
	}
}

void print(int a, int b)
{
	if(pred[b]==a)
	return;
	
	print(a, pred[b]);
	printf("%c",pred[b]+65);
}

int main(void)
{
//freopen("output.txt", "w", stdout);
	
	int T; sfi(T);
	
	while(T--)
	{
		int M, N;
		string a, b;
		
		sfi(M); sfi(N);
		
		rep(i, M)
		{
			cin>>a>>b;
			A[b[0]-65].pb(a[0]-65);
			A[a[0]-65].pb(b[0]-65);
		}
		
		rep(i, N)
		{
			cin>>a>>b;
			BFS(a[0]-65, b[0]-65);
			printf("%c",a[0]);
			print(a[0]-65, b[0]-65);
			printf("%c\n",b[0]);
		} 
		
		if(T>=1)
		nl;
		
		rep(i, 26)
		A[i].clear();
	}
	
	return 0;
}