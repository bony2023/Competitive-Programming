// Author : Bony Roopchandani
// 167 - The Sultan's Successors
// Eight Queen Problem

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

int A[10][10], mx;
bool board[10][10];

void read()
{
	rep(i, 8)
	{
		rep(j, 8)
		sfi(A[i][j]);
	}
}

void findMax()
{
	int tempMx=0;
	
	rep(i, 8)
	{
		rep(j, 8)
		{
			if(board[i][j])
			tempMx+=A[i][j];
		}
	}
	
	mx=max(mx, tempMx);
}

bool isValid(int R, int C)
{
	rept(i, 0, C)
	if(board[R][i])
	return false;
	
	for(int i=R, j=C; i<8 && j>=0; i++, j--)
	if(board[i][j])
	return false;
	
	for(int i=R, j=C; i>=0 && j>=0; i--, j--)
	if(board[i][j])
	return false;
	
	return true;
}

void constructBoard(int C)
{
	if(C>=8)
	{
		findMax();
		return;
	}
	
	rep(i, 8)
	{
		if(isValid(i, C))
		{
			board[i][C]=1;
      		constructBoard(C+1);
      		board[i][C]=0;
		}
	}
}

int main(void)
{
	int T; sfi(T);
	
	while(T--)
	{
		mx=0;
		memset(board, 0, sizeof board);
		
		read();
		constructBoard(0);
		printf("%5d\n", mx);
	}
	
	return (0);
}