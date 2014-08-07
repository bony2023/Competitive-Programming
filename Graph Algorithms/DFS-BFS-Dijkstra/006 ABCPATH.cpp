// Author : Bony Roopchandani
// ABCPATH
// BFS

// INCLUDES
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

// MACROS
#define pb push_back
#define sz size()
#define mp make_pair
#define ff first
#define ss second
#define bg begin()
#define en end()
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i=0; i<n; i++)
#define rept(i, a, b) for(int i=a; i<=b; i++)
#define repd(i, a, b) for(int i=a; i>=b; i--)
#define ll long long
#define repl(i, n) for(ll i=0; i<n; i++)
#define replt(i, a, b) for(ll i=a; i<=b; i++)
#define repld(i, a, b) for(ll i=a; i>=b; i--)
#define pfi(a) printf("%d\n",a)
#define sfi(a) scanf("%d",&a)
#define pfl(a) printf("%lld\n",(ll)a)
#define sfl(a) scanf("%lld",&a)
#define sfs(a) scanf("%s",a)
#define pfs(a) printf("%s\n",a)
#define pf(a) printf("%d ",a)
#define nl printf("\n")
#define INF 9999999
#define MOD (1e9 + 7)

// TYPEDEFS
typedef vector < int >VI;
typedef vector < ll > VLL;
typedef vector < string > VS;
typedef pair < int, int >PII;
typedef pair < int, PII > PIII;
typedef pair < int, PIII > PIIII;
typedef pair < int, ll > PIL;
typedef pair < ll, int >PLI;
typedef map < int, int >MII;
typedef map < ll, int >MLI;
typedef map < int, ll > MIL;
typedef map < int, bool > MIB;
typedef list < int >LI;
typedef list < ll > LLL;
typedef set < int >SI;
typedef set < ll > SLL;

int R, C;
int dx[]={1, 0, -1, -1, -1, 0, 1, 1};
int dy[]={-1, -1, -1, 0, 1, 1, 1, 0};

bool valid(int a, int b)
{
	return ((a>=0 && b>=0) && (a<R && b<C));
}

int main(void)
{
	int cs=1;
	char foo[55][55];
	while(1)
	{
		sfi(R), sfi(C);
		
		if(!R && !C)
		break;
		
		queue<PIII>Q;
		int vis_count[55][55]={{0}};
		
		rep(i, R)
		{
			sfs(foo[i]);
			rep(j, C)
			{
				if(foo[i][j]=='A')
				{
			   	Q.push(mp(1, mp(i, j)));
			   	vis_count[i][j]=1;
				}
			}
		}
		
		int maxx=0;
		
		while(!Q.empty())
		{
			PIII z=Q.front();
			Q.pop();
			
			if(maxx<z.ff)
			maxx=z.ff;
			
			int a=z.ss.ff;
			int b=z.ss.ss;
			char curr=foo[a][b];
			
			rep(i, 8)
			{
				int p=a+dx[i];
				int q=b+dy[i];
				char next=curr+1;
				
				if(foo[p][q]==next && valid(p, q) && vis_count[p][q]<8)
				Q.push(mp(z.ff+1, mp(p, q))), vis_count[p][q]++;
			}
		}
		
		printf("Case %d: %d\n",cs++, maxx);
		
		while(!Q.empty())
		Q.pop();
	}
	return 0;
}