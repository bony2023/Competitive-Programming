// Author : Bony Roopchandani
// TRIP
// LCS

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

int l1, l2;
char A[80+5], B[80+5], foo[80+5];
int dp[80+5][80+5];
int llen;

int LCS(int i, int j)
{
	if(i==l1+1 || j==l2+1)
	return 0;
	
	if(dp[i][j] != -1)
	return dp[i][j];
	
	if(A[i]==B[j])
	return dp[i][j]=1+LCS(i+1, j+1);
	else
	return dp[i][j]=max(LCS(i+1, j), LCS(i, j+1));
}

void getList(int i, int j, int d)
{
	if(d==llen)
	{
		foo[d]='\0';
		puts(foo);
		return;
	}
	else if(i==l1+1 || j==l2+1)
	return;
	
	for(char p='a'; p<='z'; p++)
	{
		bool t=false;
		rept(a, i, l1)
		{
			if(A[a]==p)
			rept(b, j, l2)
			{
				if(B[b]==p && LCS(a, b)==llen-d)
				{
					foo[d]=p, getList(a+1, b+1, d+1);
					t=true;
					break;
				}
			}
				
		if(t)
		break;
		}
	}
}

int main(void)
{
	int T; sfi(T);
	
	while(T--)
	{
		sfs(A), sfs(B);
		l1=strlen(A)-1, l2=strlen(B)-1;
		
		memset(dp, -1, sizeof dp);
		
		llen=LCS(0, 0);
		getList(0, 0, 0);
	}
	
	return (0);
}