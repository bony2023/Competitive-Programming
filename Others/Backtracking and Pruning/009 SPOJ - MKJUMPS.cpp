// Author : Bony Roopchandani
// MKJUMPS
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

bool board[10+5][10+5];
int N, res;

short dx[]={-2, -2, -1, -1, 1, 1, 2, 2};
short dy[]={-1, 1, -2, 2, -2, 2, -1, 1};
	
bool valid(int x, int y)
{
	return (x>=0 && y>=0 && x<10 && y<10);
}

void solve(int x, int y, int c)
{
	res=max(res, c);
	
	rep(i, 8)
	{
		int a=x+dx[i], b=y+dy[i];
		
		if(valid(a, b) && board[a][b])
		{
			board[a][b]=0;
			solve(a, b, c+1);
			board[a][b]=1;
		}
	}
}

int main(void)
{
//	in("input.txt");
	
	int x, y, startx, starty, tot, cs=1;
	
	while(sfi(N) && N)
	{
		startx=starty=-1;
		memset(board, 0, sizeof board);
		tot=res=0;
		
		rep(i, N)
		{
			sfi(x), sfi(y);
			
			if(startx==-1)
			startx=i, starty=x;
			
			tot+=y;
			
			rep(j, y)
			board[i][j+x]=1;
		}
		
		board[startx][starty]=0;
		solve(startx, starty, 1);
		
		printf("Case %d, %d ", cs++, tot-res);
		
		printf("%s ",(tot-res==1)?"square":"squares");
		puts(" can not be reached.");
	}
	
	return (0);
}