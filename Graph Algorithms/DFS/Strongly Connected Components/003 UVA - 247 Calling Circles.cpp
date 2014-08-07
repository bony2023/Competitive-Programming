// Author : Bony Roopchandani
// 247 - Calling Circles
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
typedef vector<int> VI;
typedef vector<ll> VLL;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<int, ll> PIL;
typedef pair<ll, int> PLI;
typedef pair<int, PII> PIII;
typedef pair<int, PIII> PIIII;
typedef map<int, int> MII;
typedef map<ll, int> MLI;
typedef map<int, ll> MIL;
typedef list<int> LI;
typedef list<ll> LLL;
typedef set<int> SI;
typedef set<ll> SLL;

string S[30];
map<string, bool>done;
map<string, VS>A;
map<string, int>dfsLow;
map<string, int>dfsNum;
int dfsCounter;
VS Q;
int s=0, t=0;

void Tarjan(string u)
{
	done[u]=1;
	dfsLow[u]=dfsNum[u]=dfsCounter++;
	Q.pb(u);
	
	int s=A[u].sz;
	
	rep(i, s)
	{
		string z=A[u][i];
		
		if(!dfsNum[z])
		Tarjan(z);
		
		if(done[z])
		dfsLow[u]=min(dfsLow[u], dfsLow[z]);
	}
	
	if(dfsLow[u]==dfsNum[u])
	{
		while(1)
		{
			string z=Q.back();
			Q.pop_back();
			if(t)
			printf(", ");
			done[z]=0;
			cout<<z;
			t=1;
			if(u==z)
			break;
		}
		t=0, nl;
	}
}

void clearAll()
{
	done.clear();
	A.clear();
	dfsLow.clear();
	dfsNum.clear();
	Q.clear();
	s=t=0;
}

int main(void)
{
//	freopen("input.txt", "r", stdin);
	int cs=1;
	while(1)
	{
		int N, M;
		
		sfi(N); sfi(M);
		
		if(!N && !M)
		break;
		
		string x, y;
		
		rep(i, M)
		{
			cin>>x>>y;
			if(!done[x])
			S[s++]=x, done[x]=1;
			if(!done[y])
			S[s++]=y, done[y]=1;
			A[x].pb(y);
		}
		
		done.clear();
		dfsCounter=1;
		
		if(cs==1)
		printf("Calling circles for data set %d:\n",cs++);
		else
		printf("\nCalling circles for data set %d:\n",cs++);
		
		rep(i, N)
		{
			if(!dfsNum[S[i]])
			Tarjan(S[i]);
		}
		
		clearAll();
	}
	
	return 0;
}