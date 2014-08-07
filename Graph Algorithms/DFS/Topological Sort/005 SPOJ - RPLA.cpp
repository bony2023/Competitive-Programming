// Author : Bony Roopchandani
// RPLA
// TopSort

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

class myComp
{
	public:
	bool operator()(int x, int y) const
	{
		return (x<y);
	}
};

typedef struct rank
{
	int val;
	int key;
}R;

int comp(const void* a, const void* b) 
{
	const R *item1=(R*)a,  *item2=(R*)b;
	
  return(item1->val - item2 -> val);
}

R RANK[1001];
VI A[1001];
int indeg[1001]={0};

void TopoSort(int V)
{
	set<int, myComp>S;
	set<int, myComp>::iterator t;
	
	rep(i, V)
	{
		if(!indeg[i])
		S.insert(i), RANK[i].val=1;
	}
	
	while(!S.empty())
	{
		t=S.begin();
		int z=*t;
		S.erase(S.begin());
		int s=A[z].sz;
		
		rep(i, s)
		{
			int u=A[z][i];
			
			indeg[u]--;
			
			if(!indeg[u])
			S.insert(u), RANK[u].val=RANK[z].val+1;
		}
	}
}

void clearAll(int V)
{
	rep(i, V)
	A[i].clear(), indeg[i]=0;
}

void FillRank(int V)
{
	rep(i, V+1)
	{
		RANK[i].val=0;
		RANK[i].key=i;
	}
}

int main(void)
{
//	freopen("input.txt", "r", stdin);
	int c=1;
	int T; sfi(T);
	
	while(T--)
	{
		int N, M;
		
		sfi(N); sfi(M);
		FillRank(N);
		
		int x, y;
		
		rep(i, M)
		{
			sfi(x); sfi(y);
			A[y].pb(x);
			indeg[x]++;
		}
		
		TopoSort(N);
		qsort(RANK, N, sizeof(R), comp);
		
		LI::iterator t;
		printf("Scenario #%d:\n",c++);
		
		rep(i, N)
		pf(RANK[i].val), pfi(RANK[i].key);
		
		clearAll(N);
	}
	return 0;
}