// Author : Bony Roopchandani
// 10731 - Test
// SCC - Tarjan's

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
typedef vector < int >VI;
typedef vector < ll > VLL;
typedef pair < int, int >PII;
typedef pair < int, ll > PIL;
typedef pair < ll, int >PLI;
typedef pair < int, PII > PIII;
typedef pair < int, PIII > PIIII;
typedef map < int, int >MII;
typedef map < ll, int >MLI;
typedef map < int, ll > MIL;
typedef list < int >LI;
typedef list < ll > LLL;
typedef set < int >SI;
typedef set < ll > SLL;

VI A[30];
bool P[30] = { 0 };
VI vis, dfsLow, dfsNum, S;
int dfsCounter, H=0;
VI B[26];
int M[26]={0};

void Tarjan(int u)
{
	vis[u]=1;
	
	S.pb(u);
	dfsLow[u]=dfsNum[u]=dfsCounter++;
	int s=A[u].sz;
	
	rep(i, s)
	{
		int z=A[u][i];
		
		if(dfsNum[z]==-1)
		Tarjan(z);
		
		if(vis[z])
		dfsLow[u]=min(dfsLow[u], dfsLow[z]);
	}
	
	if(dfsLow[u]==dfsNum[u])
	{
		while(1)
		{
			int z=S.back();
			S.pop_back();
			vis[z]=0;
			B[H].pb(z);
			if(z==u)
			break;
		}
		H++;
	}
}

void clearAll()
{
	rep(i, 26)
	A[i].clear(), B[i].clear();
	dfsNum.clear();
	dfsLow.clear();
	vis.clear();
	H=0;
	S.clear();
	memset(P, 0, sizeof P);
}

int main(void)
{
//	freopen("input.txt", "r", stdin);
	int cs=1;
	
	while (1)
	{
		int N; sfi(N);
		getchar();
		if(!N)
		break;
		
		char a[10];

		rep(i, N)
		{
			rep(j, 6)
			{
				scanf("%c",&a[j]);
//				pf(a[j]);
				P[a[j]-65]=1;
				getchar();
			}
			
			rep(j, 5)
			{
				if(a[5]!=a[j])
				A[a[5]-65].pb(a[j]-65);
			}
		}
		
		vis.assign(26,0);
		dfsLow.assign(26, 0);
		dfsNum.assign(26, -1);
		dfsCounter=0;
		
		rep(i, 26)
		{
			if(P[i] && dfsNum[i]==-1)
			Tarjan(i);
		}
		
		memset(M, -1, sizeof M);
		
		rep(i, H)
		sort(B[i].bg, B[i].en);
		
		rep(i, H)
		M[B[i][0]]=i;
		
		if(cs>1)
		nl;
		cs++;
		
		rep(i, 26)
		{
			if(M[i]!=-1)
			{
				rep(j, B[M[i]].sz)
				printf("%c",B[M[i]][j]+65),
				printf("%c",(j==(B[M[i]].sz-1)?'\n': ' '));
			}
		}
		
		clearAll();
	}
	return 0;
}