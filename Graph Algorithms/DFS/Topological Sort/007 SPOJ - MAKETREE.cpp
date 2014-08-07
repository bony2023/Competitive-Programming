// Author : Bony Roopchandani
// MAKETREE
// TopoSort

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<list>
#include<set>
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
#define CHUNK_SIZE 65536
#define MOD 1000000007
typedef vector<int> VI;
typedef vector<ll> VLL;
typedef pair<int, int> PII;
typedef pair<int, ll> PIL;
typedef pair<ll, int> PLI;
typedef pair<int, PII>PIII;
typedef pair<int, PIII> PIIII;
typedef map<int, int> MII;
typedef map<ll, int> MLI;
typedef map<int, ll> MIL;
typedef list<int> LI;
typedef list<ll> LLL;
typedef set<int> SI;
typedef set<ll> SLL;

VI A[100001];
int indeg[100001]={0};
int rank[100001]={0};

void TopSort(int V)
{
	queue<int>Q;
	
	rept(i, 1, V)
	if(!indeg[i])
	Q.push(i);
	
	int t=0;
	
	while(!Q.empty())
	{
		int z=Q.front();
		Q.pop();
		int s=A[z].sz;
		
		rank[z]=t;
		
		rep(i, s)
		{
			int u=A[z][i];
			
			indeg[u]--;
			
			if(!indeg[u])
			Q.push(u);
		}
		
		t=z;
	}
}

int main(void)
{
	int N, M;
	
	sfi(N); sfi(M);
	
	int x, Q;
	
	rept(i, 1, M)
	{
		sfi(Q);
		rep(j, Q)
		{
			sfi(x);
			A[i].pb(x);
			indeg[x]++;
		}
	}
	
	TopSort(N);
	
	rept(i, 1, N)
	pfi(rank[i]);
	
	return 0;
}