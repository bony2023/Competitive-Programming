// Author : Bony Roopchandani
// PFDEP
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

VI A[101];
int indeg[101]={0};
LI foo;

void TopoSort(int V)
{
	SI S;
	SI::iterator t;
	
	rept(i, 1, V)
	if(!indeg[i])
	S.insert(i);
	
	while(!S.empty())
	{
		t=S.begin();
		int z=*t;
		S.erase(S.begin());
		foo.pb(z);
		int s=A[z].sz;
		
		rep(i, s)
		{
			int u=A[z][i];
			
			indeg[u]--;
			
			if(!indeg[u])
			S.insert(u);
		}
	}
}

int main(void)
{
	int N, M;
	
	sfi(N); sfi(M);
	
	rep(i, M)
	{
		int y; sfi(y);
		int Q; sfi(Q);
		int x;
		
		rep(j, Q)
		{
			sfi(x);
			A[x].pb(y);
			indeg[y]++;
		}
	}
	
	getchar();
	TopoSort(N);
	
	LI::iterator t;
	t=foo.bg;
	
	printf("%d",*t);
	
	for(t++; t!=foo.en; t++)
	printf(" %d",*t);
	nl;
	return 0;
}