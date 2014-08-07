// Author : Bony Roopchandani
// 11624 - Fire!
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

bool A[1000001];
int R, C, Fdist[1000001], Jdist[1000001], d[4];

int valid(int a, int i)
{
	if(i==0 && a>=0 && (a+1)%C!=0)
		return 1;
	else 
	if(i==1&& a>=0)
	return 1;
	else 
	if(i==2 && a<R*C && a%C!=0)
	return 1;
	else 
	if(i==3 && a<R*C)
	return 1;
	else return 0;
}

void FBFS(int u[], int z)
{
	bool vis[1000001];
	
	rep(i, R*C)
	vis[i]=0, Fdist[i]=INF;
	
	queue<int>Q;
	
	rep(i, z)
	Q.push(u[i]), Fdist[u[i]]=1, vis[u[i]]=1;
	
	while(!Q.empty())
	{
		int z=Q.front();
		Q.pop();
		
		rep(i, 4)
		{
			int x=z+d[i];
			
			if(!vis[x] && valid(x, i) && A[x])
			{
				vis[x]=1;
				if(Fdist[x]>Fdist[z]+1)
				Fdist[x]=Fdist[z]+1;
				Q.push(x);
			}
		}
	}
}

void JBFS(int u)
{
	bool vis[1000001];
	
	rep(i, R*C)
	vis[i]=0, Jdist[i]=INF;
	
	Jdist[u]=1;
	vis[u]=1;
	queue<int>Q;
	Q.push(u);
	
	while(!Q.empty())
	{
		int z=Q.front();
		Q.pop();
		
		rep(i, 4)
		{
			int x=z+d[i];
			
			if(!vis[x] && valid(x, i) && A[x])
			{
				vis[x]=1;
				if(Jdist[x]>Jdist[z]+1)
				Jdist[x]=Jdist[z]+1;
				Q.push(x);
			}
		}
	}
}

int main(void)
{
//	freopen("input.txt", "r", stdin);
	int T;
	sfi(T);
	
	while(T--)
	{
		bool cond=false;
		int min=INF;
		
		sfi(R); sfi(C);
		
		d[0]=-1;
		d[1]=-C;
		d[2]=1;
		d[3]=C;
		
		int q, z, F[100001], S;
		char foo[1001];
		
		q=z=0;
		
		rep(i, R)
		{
			sfs(foo);
			rep(j, C)
			{
				if(foo[j]=='J' || foo[j]=='F' || foo[j]=='.')
				A[q]=1;
				else A[q]=0;
				
				if(foo[j]=='J')
				S=q;
				else if(foo[j]=='F')
				F[z++]=q;
				
				q++;
			}
		}
		
		JBFS(S);
		
		FBFS(F, z);

		for(int i=0, j=C-1; j<R*C; i+=C, j+=C)
		{
			if(Jdist[i]<Fdist[i] && A[i])
			{
				cond=true;
				if(min>Jdist[i])
				min=Jdist[i];
			}
			 if(Jdist[j]<Fdist[j] && A[j])
			{
				cond=true;
				if(min>Jdist[j])
				min=Jdist[j];
			}
		}
		
		for(int i=1, j=R*C-C+1; j<R*C; i++, j++)
		{
			if(Jdist[i]<Fdist[i] && A[i])
			{
				cond=true;
				if(min>Jdist[i])
				min=Jdist[i];
			}
			else if(Jdist[j]<Fdist[j] && A[j])
			{
				cond=true;
				if(min>Jdist[j])
				min=Jdist[j];
			}
		}
		
		if(!cond)
		pfs("IMPOSSIBLE");
		else
		pfi(min);
	}
	
	return 0;
}