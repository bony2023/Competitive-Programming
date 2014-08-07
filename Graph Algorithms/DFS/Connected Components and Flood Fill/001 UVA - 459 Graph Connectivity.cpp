// Author : Bony Roopchandani
// 459 - Graph Connectivity
// DFS - Connected Components/Flood Fill

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
typedef vector < int >VI;
typedef vector < ll > VL;
typedef pair < int, int >PII;
typedef pair < int, ll > PIL;
typedef pair < ll, int >PLI;
typedef pair < int, PII > PIII;
typedef pair < int, PIII > PIIII;
typedef map < int, int >MII;
typedef map < ll, int >MLI;
typedef map < int, ll > MIL;
typedef list < int >LI;
typedef list < ll > LL;

VI A[28];
bool vis[28];

int DFS(int u)
{
	int s = A[u].sz;

	rep(i, s)
	{
		if (!vis[A[u][i]])
		{
			vis[A[u][i]] = 1;
			DFS(A[u][i]);
		}
	}
}

void readGraph(int &node1, int &node2)
{
	string edge;
	getline(cin, edge);
	while (getline(cin, edge))
	{
		if (edge.size() == 0)
			break;
		node1 = edge[0] - 65;
		node2 = edge[1] - 65;
		A[node1].pb(node2);
		A[node2].pb(node1);
	}
}

int main(void)
{
//	freopen("input.txt", "r", stdin);
	int T;
	sfi(T);

	rep(i, T)
	{
		char Q;
		cin>>Q;
		int M=Q-65;

		int a, b;

		readGraph(a, b);

		memset(vis, 0, sizeof vis);
		int c = 0;

		rep(j, M + 1)
		{
			if (!vis[j])
			{
				c++;
				DFS(j);
			}
		}

		if (i == 0)
			printf("%d\n", c);
		else
			printf("\n%d\n", c);
//		getchar();

		rep(j, M + 1) 
		A[j].clear();
	}
	return 0;
}