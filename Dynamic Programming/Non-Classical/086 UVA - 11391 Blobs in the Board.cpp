// Author : Bony Roopchandani
// 11391 - Blobs in the Board
// DP+Bitmask

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

int R, C, N;
short dx[]={-1, -1, -1, 0, 1, 1, 1, 0};
short dy[]={-1, 0, 1, 1, 1, 0, -1, -1};
int dp[4][4][1<<16];

bool valid(int a, int b)
{
	return (a>=0 && b>=0 && a<R && b<C);
}

int F(int n, int bitmask)
{
	if(n == N-1)
	return 1;
	
	if(dp[R-1][C-1][bitmask] != -1)
	return dp[R-1][C-1][bitmask];
	
	int ans=0;
	
	rep(i, R)
	{
		rep(j, C)
		{
			int source=(R*i)+j;
			
			if(bitmask & (1<<source))
			{
				rep(k, 8)
				{
					int mx, my, mid;
					mx=i+dx[k];
					my=j+dy[k];
					
					int Dx, Dy, dest;
					Dx=mx+dx[k];
					Dy=my+dy[k];
					
					mid=(R*mx)+my;
					dest=(R*Dx)+Dy;
					
					if(valid(mx, my) && valid(Dx, Dy) && (bitmask & (1<<mid)) && !(bitmask & (1<<dest)))
					{
						int tmp=bitmask;
						tmp |= (1<<dest);
						tmp &= ~(1<<mid);
						tmp &= ~(1<<source);
						ans+=F(n+1, tmp);
					}
				}
			}
		}
	}
	
	return dp[R-1][C-1][bitmask]=ans;
}

int main(void)
{
//	in("input.txt");
	
	int T; sfi(T);
	int cs=1;
	
	memset(dp, -1, sizeof dp);
	
	while(T--)
	{
		sfi(R), sfi(C), sfi(N);
		
		int bit=0;
		int x, y;
		
		rep(i, N)
		{
			sfi(x), sfi(y);
			x--, y--;
			x=R*x+y;
			bit |= (1<<x);
		}
		
		printf("Case %d: %d\n", cs++, F(0, bit));
	}
	
	return (0);
}