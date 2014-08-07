// Author : Bony Roopchandani
// 352 - The Seasonal War
// Connected Components/Flood Fill

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

bool vis[26][26]={{0}};
int N;
char foo[26][26];
short dx[]={1, 0, -1, -1, -1, 0, 1, 1};
short dy[]={-1, -1, -1, 0, 1, 1, 1, 0};

bool valid(int i, int j)
{
	return ((i>=0 && i<N) && (j>=0 && j<N));
}

void dfs(int i, int j)
{
	vis[i][j]=1;
	
	rep(x, 8)
	{
		int a=i+dx[x];
		int b=j+dy[x];
		
		if(!vis[a][b] && foo[a][b]=='1' && valid(a,b))
		dfs(a, b);
	}
}

int main(void)
{
	int cs=1;
	
//	freopen("Bumble.in", "r", stdin);
//	freopen("Bumble.out", "w", stdout);
	
	while(sfi(N)!=EOF)
	{
		rep(i, N)
		 sfs(foo[i]);
		
		int P=0;
		
		rep(i, N)
		{
			rep(j, N)
			 if(!vis[i][j] && foo[i][j]=='1')
			  P++, dfs(i, j);
		}
		
		printf("Image number %d contains %d war eagles.\n",cs++, P);
		
		memset(vis, false, sizeof vis);
		memset(foo, '\0', sizeof foo);
	}
	return 0;
}