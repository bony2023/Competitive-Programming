// Author : Bony Roopchandani
// ANARC05H
// DP

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
#define ll long long
#define mp make_pair
#define nl printf("\n")
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

int dp[30][500];
char dig[30];

class DP
{
	int len;
	
	public:
	
	DP()
	{
		rep(i, 30)
		fill(dp[i], dp[i]+500, -1);
		len=strlen(dig);
	}
	
	int init(int pos, int prev)
	{
		if(pos==len) return 1;
		
		if(dp[pos][prev] != -1)
		{
			return dp[pos][prev];
		}
		
		int a=0, sum=0;
		
		rept(i, pos, len-1)
		{
			sum+=dig[i]-'0';
			
			if(sum>=prev)
			a+=init(i+1, sum);
		}
		
		return dp[pos][prev]=a;
	}
};

bool noNum()
{
	rep(i, strlen(dig))
	if(dig[i]>'9' || dig[i]<'0')
	return true;
	
	return false;
}

int main()
{
	int cs=1;
	
	while(sfs(dig))
	{
		if(noNum())
		break;
		
		DP D;
		printf("%d. ", cs++);
		pfi(D.init(0, 0));
	}
	return (0);
}