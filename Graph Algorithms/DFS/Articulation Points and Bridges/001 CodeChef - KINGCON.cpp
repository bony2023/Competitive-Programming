// Author : Bony Roopchandani
// KINGCON
// Articulation Points on Graph

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

bool vis[3002]={0};
VI A[3002];
int dfsNum[3002], dfsLow[3002];
int dfsParent[3002], D[3002]={0};
int tot, dfsCounter;
int dfsRoot, dfsRootChild;

void AP(int u)
{
	dfsLow[u]=dfsNum[u]=dfsCounter++;
	vis[u]=1;
	int s=A[u].sz;
	
	rep(i, s)
	{
		int z=A[u][i];
		
		if(!vis[z])
		{
			dfsParent[z]=u;
			
			if(u==dfsRoot)
			dfsRootChild++;
			
			AP(z);
			
			if(dfsLow[z]>=dfsNum[u])
			D[u]=1;
			
			dfsLow[u]=min(dfsLow[u], dfsLow[z]);
		}
		else
		if(z!=dfsParent[u])
		dfsLow[u]=min(dfsLow[u], dfsNum[z]);
	}
}

void clearAll(int V)
{
	memset(vis, 0, sizeof vis);
	memset(D, 0, sizeof D);
	memset(dfsNum, 0, sizeof dfsNum);
	memset(dfsLow, 0, sizeof dfsLow);
	memset(dfsParent, 0, sizeof dfsParent);
	
	rep(i, V)
	A[i].clear();
}

void scanint(int &x)
{
	register int c = getchar_unlocked();
	x = 0;
	int neg = 0;
	for (; ((c < 48 || c > 57) && c != '-'); c = getchar_unlocked());
	if (c == '-')
	{
		neg = 1;
		c = getchar_unlocked();
	}
	for (; c > 47 && c < 58; c = getchar_unlocked())
	{
		x = (x << 1) + (x << 3) + c - 48;
	}
	if (neg)
		x = -x;
}

int main(void)
{
//	freopen("input.txt", "r", stdin);
	int T; scanint(T);
	
	while(T--)
	{
		int N, M, C;
		
		scanint(N);
		scanint(M);
		scanint(C);
		int x, y;
		
		rep(i, M)
		{
			scanint(x);
			scanint(y);
			A[x].pb(y);
			A[y].pb(x);
		}
		
		dfsCounter=tot=0;
		
		rep(i, N)
		{
			if(!vis[i])
			{
				dfsRoot=i;
				dfsRootChild=0;
				
				AP(i);
					      			D[dfsRoot]=(dfsRootChild>1);
			}
		}
		
		rep(i, N)
		if(D[i])
		tot++;
		
		pfi(tot*C);
		
		clearAll(N);
	}
	return 0;
}