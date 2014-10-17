// Author : Bony Roopchandani
// 11085 - Back to the 8-Queens
// 8 Queens Problem

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

bool board[10][10];
int P[10], ans;

bool isValid(int R, int C)
{
	rept(j, 0, C)
	if(board[R][j])
	return false;
	
	for(int i=R, j=C; i>=0 && j>=0; i--, j--)
	if(board[i][j])
	return false;
	
	for(int i=R, j=C; i<8 && j>=0; i++, j--)
	if(board[i][j])
	return false;
	
	return true;
}

void solve(int Col, int Move)
{
	if(Col>=8)
	{
		ans=min(ans, Move);
		return;
	}
	
	if(isValid(P[Col], Col))
	{
		board[P[Col]][Col]=1;
		solve(Col+1, Move);
		board[P[Col]][Col]=0;
	}
	
	rep(i, 8)
	{
		if(i != P[Col])
		{
			if(isValid(i, Col))
			{
				board[i][Col]=1;
				solve(Col+1, Move+1);
				board[i][Col]=0;
			}
		}
	}
}

int main(void)
{
//	in("input.txt");
	
	int x, cs=1;
	
	while(cin>>x)
	{
		P[0]=x-1;
		
		rept(i, 1, 7)
		sfi(x), P[i]=x-1;
		
		ans=INF;
		memset(board, 0, sizeof board);
		
		solve(0, 0);
		
		printf("Case %d: %d\n", cs++, ans);
	}
	return (0);
}