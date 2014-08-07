// Author : Bony Roopchandani
// MOWS
// SCC

#include<cstdio>
#include<vector>
#define MAX 111111
#define pb push_back
#define sz size()
#define rep(i, a) for(int i=0; i<a; i++)
#define sfi(a) scanf("%d", &a)
#define rept(i, a, b) for(int i=a; i<=b; i++)
using namespace std;

vector<int> A[MAX], S;
int dfsNum[MAX], dfsLow[MAX]={0};
bool vis[MAX]={0};
int dfsCounter;
int maxx[MAX]={0}, comp[MAX];
int C, foo;

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
		comp[u]=++foo;
		while(1)
		{
			int z=S.back();
			S.pop_back();
			vis[z]=0;
			comp[z]=foo;
			maxx[foo]++;
			if(u==z)
			break;
		}
	}
}

void clearAll(int H, int P)
{
	rep(i, MAX)
	{
		A[i].clear();
		vis[i]=0;
		comp[i]=0;
		maxx[i]=0;
	}
	
	S.clear();
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
		int H, P, S;
		scanint(H);
		scanint(P);
		scanint(S);
		
		int x, y;
		
		rep(i, S)
		{
			scanint(x);
			scanint(y);
			A[x].pb(y);
		}
		
		rep(i, MAX)
		dfsNum[i]=-1;
		
		foo=0;
		rept(i, 1, H)
		{
			if(dfsNum[i]==-1)
			Tarjan(i);
		}
		
		int id=-1, tot=-1;
		
		rept(i, 1, H)
		maxx[comp[i]]-=1;
		
		rept(i, 1, H)
		{
			if(tot<maxx[comp[i]])
			id=i, tot=maxx[comp[i]];
		}
		printf("%d %d\n",id, tot);
		
		clearAll(H, P);
	}
	
	return 0;
}