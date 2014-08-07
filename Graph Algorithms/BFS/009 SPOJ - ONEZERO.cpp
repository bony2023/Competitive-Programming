// Author : Bony Roopchandani
// ONEZERO
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

int N;
struct node
{
	int r;
	int c;
}pred[20000];

int rem(int a, int b)
{
	return (a<b)?a:a%b;
}

void BFS(int a)
{
	int vis[20000]={0};
	vis[a]=1;
	pred[a].r=-1;
	pred[a].c=1;
	
	queue<int>Q;
	Q.push(a);
	
	while(!Q.empty())
	{
		int z=Q.front();
//		pf(z);
		Q.pop();
		
		int x=rem(z*rem(10,N), N);
		int y=rem(x+1, N);
		
		if(!vis[x])
		{
			vis[x]=1;
			pred[x].r=z;
			pred[x].c=0;
			Q.push(x);
		}
		
		if(!vis[y])
		{
			vis[y]=1;
			pred[y].r=z;
			pred[y].c=1;
			Q.push(y);
		}
	}
}

void print(int a)
{
	if(a==-1)
	return;
	
	print(pred[a].r);
	printf("%d",pred[a].c);
}
			

int main(void)
{
	int T; sfi(T);
	
	while(T--)
	{
		bool cond=true;
		sfi(N);
		
		int t=N;
		
		while(t)
		{
			if(t%10>1)
			{
				cond=false;
				break;
			}
			t/=10;
		}
		
		if(cond)
		pfi(N);
		else
		{
			BFS(1);
			print(0);
			nl;
		}
	}
	
	return 0;
}