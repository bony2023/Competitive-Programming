// Author : Bony Roopchandani
// 10946 - You want what filled?
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

bool myComp(pair<char, int> a, pair<char, int> b)
{
	return ((a.ss==b.ss && a.ff<b.ff) || a.ss>b.ss);
}

int R, C;
char foo[52][52]={{0}};
bool vis[52][52]={{0}};
char curr;
int tot=0;

short dx[]={0, -1, 0, 1};
short dy[]={-1,  0, 1, 0};

bool valid(int i, int j)
{
	return ((i>=0 && j>=0) && (i<R && j<C));
}

void dfs(int i, int j)
{
	vis[i][j]=1;
	tot++;
	
	rep(x, 4)
	{
		int a=i+dx[x];
		int b=j+dy[x];
		
		if(!vis[a][b] && foo[a][b]==curr && valid(a, b))
		dfs(a, b);
	}
}

int main(void)
{
//	freopen("input.txt", "r", stdin);
	int cs=1;
	
	while(1)
	{
		sfi(R); sfi(C);
		
		if(!R && !C)
		break;
		
		rep(i, R)
		{
			sfs(foo[i]);
		}
		
		vector<pair<char, int> >V;
		
		rep(i, R)
		{
			rep(j, C)
			{
				if(!vis[i][j] && foo[i][j]!='.')
				{
				curr=foo[i][j], dfs(i, j);
				V.pb(mp(curr, tot));
				tot=0;
				}
			}
		}
		
		sort(V.bg, V.en, myComp);
		vector<pair<char, int> >::iterator t;
		
		printf("Problem %d:\n",cs++);
		
		for(t=V.bg; t!=V.en; t++)
		{
			printf("%c ",((*t).ff)); pfi((*t).ss);
		}
		
		memset(vis, 0, sizeof vis);
		memset(foo, '\0', sizeof foo);
	}
	return 0;
}