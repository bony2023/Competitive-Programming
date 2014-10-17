// Author : Bony Roopchandani
// 11283 - Playing Boggle
// Backtracking

// INCLUDES
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
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

short Point[10];
char grid[5][5], foo[20];
bool ans, vis[5][5];

short dx[]={0, -1, -1, -1, 0, 1, 1, 1};
short dy[]={-1, -1, 0, 1, 1, 1, 0, -1};

bool valid(int x, int y)
{
	return (x>=0 && y>=0 && x<4 && y<4);
}

void solve(int x, int y, int id)
{
	if(id==strlen(foo)-1 && foo[id]==grid[x][y])
	{
		ans=1;
		return;
	}
	
	if(grid[x][y] != foo[id])
	return;
	
	rep(i, 8)
	{
		if(valid(x+dx[i], y+dy[i]) && !vis[x+dx[i]][y+dy[i]])
		{
			vis[x+dx[i]][y+dy[i]]=1;
			solve(x+dx[i], y+dy[i], id+1);
			
			if(ans)
			return;
			
			vis[x+dx[i]][y+dy[i]]=0;
		}
	}
}

void init()
{
	Point[3]=Point[4]=1;
	Point[5]=2;
	Point[6]=3;
	Point[7]=5;
}

short getPoint(int len)
{
	if(len>=8)
	return 11;
	
	return Point[len];
}

int main(void)
{
//	in("input.txt");
	
	int T, cs=1; sfi(T);
	vector<PII> Map[30];
	init();
	
	while(T--)
	{
		rep(i, 4)
		{
			rep(j, 4)
			{
				cin>>grid[i][j];
				Map[grid[i][j]-'A'].pb(mp(i, j));
			}
		}
		
		int N, x, y; sfi(N);
		int res=0;
		
		while(N--)
		{
			sfs(foo);
			
			rep(i, Map[foo[0]-'A'].sz)
			{
				x=Map[foo[0]-'A'][i].ff;
				y=Map[foo[0]-'A'][i].ss;
				
				ans=0;
				memset(vis, 0, sizeof vis);
				vis[x][y]=1;
				
				solve(x, y, 0);
				
				if(ans)
				{
					res+=getPoint(strlen(foo));
					break;
				}
			}
		}
		
		printf("Score for Boggle game #%d: %d\n", cs++, res);
		
		rep(i, 30)
		Map[i].clear();
	}
	return (0);
}