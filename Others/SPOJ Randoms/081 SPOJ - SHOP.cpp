// Author : Bony Roopchandani
// SHOP
// Dijkstra

// INCLUDES
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// MACROS
#define all(a) a.begin(), a.end()
#define bg begin()
#define en end()
#define ff first
#define in(a) freopen(a, "r", stdin)
#define ll long long
#define mp make_pair
#define nl printf("\n")
#define out(a) freopen(a, "w", stdout)
#define pb push_back
#define pf(a) printf("%d ",a)
#define pfi(a) printf("%d\n",a)
#define pfl(a) printf("%lld\n",(ll)a)
#define pfs(a) printf("%s\n",a)
#define rep(i, n) for(int i=0; i<n; i++)
#define repd(i, a, b) for(int i=a; i>=b; i--)
#define repl(i, n) for(ll i=0; i<n; i++)
#define repld(i, a, b) for(ll i=a; i>=b; i--)
#define replt(i, a, b) for(ll i=a; i<=b; i++)
#define rept(i, a, b) for(int i=a; i<=b; i++)
#define sfi(a) scanf("%d",&a)
#define sfl(a) scanf("%lld",&a)
#define sfs(a) scanf("%s",a)
#define ss second
#define sz size()

// CONSTS
const double EPS = (1e-11);
const double PI = acos(-1.0);
const int INF = 9999999;
const int MOD = (1e9 + 7);

// TYPEDEFS
typedef list < int > LI;
typedef list < ll > LLL;
typedef map < int, bool > MIB;
typedef map < int, int > MII;
typedef map < int, ll > MIL;
typedef map < ll, int > MLI;
typedef pair < int, int > PII;
typedef pair < int, PII > PIII;
typedef pair < int, PIII > PIIII;
typedef pair < int, ll > PIL;
typedef pair < ll, int > PLI;
typedef set < int > SI;
typedef set < ll > SLL;
typedef vector < int > VI;
typedef vector < ll > VLL;
typedef vector < string > VS;

short dx[]={0, -1, 0, 1};
short dy[]={-1, 0, 1, 0};
int R, C;
int fx, fy;

char foo[30][30];

bool valid(int a, int b)
{
	return ((a>=0 && a<R) && (b>=0 && b<C) && foo[a][b] != 'X');
}

int dijkstra(int sx, int sy)
{
	int dist[R+5][C+5];
	rep(i, R)
	rep(j, C)
	dist[i][j]=INF;
	dist[sx][sy]=0;
	
	priority_queue<PIII, vector<PIII>, greater<PIII> > Q;
	Q.push(mp(0, mp(sx, sy)));
	
	while(!Q.empty())
	{
		int ux=Q.top().ss.ff;
		int uy=Q.top().ss.ss;
		int d=Q.top().ff;
		Q.pop();
		
		if(dist[ux][uy]==d)
		{
			rep(i, 4)
			{
				int vx=ux+dx[i];
				int vy=uy+dy[i];
				int D=foo[vx][vy]-'0';
				
				if(valid(vx, vy) && dist[vx][vy]>dist[ux][uy]+D)
				{
					dist[vx][vy]=dist[ux][uy]+D;
					Q.push(mp(dist[vx][vy], mp(vx, vy)));
				}
			}
		}
	}
	
	return dist[fx][fy];
}

int main(void)
{
	int sx, sy;
	
	while(sfi(C) && sfi(R) && R && C)
	{
		rep(i, R)
		{
			sfs(foo[i]);
			
			rep(j, C)
			{
				if(foo[i][j]=='S')
				{
					sx=i, sy=j;
					foo[i][j]='0';
				}
				
				if(foo[i][j]=='D')
				{
					fx=i, fy=j;
					foo[i][j]='0';
				}
			}
		}
		
		pfi(dijkstra(sx, sy));
	}
	
	return (0);
}