// Author : Bony Roopchandani
// 524 - Prime Ring Problem
// Backtracking+Prime Generator

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

bool Prime[50]={0};
bool vis[20];
int foo[20];
int N;

bool isPrime(int a)
{
	if(a%2==0)
	return false;
	
	int S=sqrt(a)*1.0;
	
	rept(i, 3, S)
	if(a%i==0)
	return false;
	
	return true;
}

void solve(int curr, int c)
{
	if(c==N)
	{
		if(Prime[foo[N-1]+foo[0]])
		{
			printf("%d", foo[0]);
      		rept(i, 1, N-1)
      		printf(" %d", foo[i]);
      		nl;
		}
		return;
	}
	
	rept(i, 1, N)
	{
		if(!vis[i] && Prime[curr+i])
		{
			foo[c]=i;
			vis[i]=1;
			solve(i, c+1);
			vis[i]=0;
		}
	}
}

int main(void)
{
//	in("input.txt");
	
	rept(i, 3, 40)
	if(isPrime(i))
	Prime[i]=true;
	foo[0]=1;
	
	int cs=1;
	
	while(cin>>N)
	{
		memset(vis, 0, sizeof vis);
		vis[1]=1;
		if(cs>=2)
		nl;
		printf("Case %d:\n", cs++);
		if(N==1)
		pfi(1);
		else
		solve(1, 1);
	}
	
	return (0);
}