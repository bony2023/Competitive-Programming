// Author : Bony Roopchandani
// KQUERY
// Offline Processing BIT

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

struct node
{
	int lo, hi, K, indi;
};

node a[230000+5];
int Tree[30000+5]={0}, N;

bool cmp(node a, node b)
{
	if(a.K==b.K)
	return a.hi>b.hi;
	
	return a.K>b.K;
}

void update(int pos, int val)
{
	while(pos<=N)
	{
		Tree[pos]+=val;
		pos+=(pos&-pos);
	}
}

int query(int pos)
{
	int ret=0;
	
	while(pos>0)
	{
		ret+=Tree[pos];
		pos-=(pos&-pos);
	}
	return ret;
}

int main(void)
{
	sfi(N);
	
	rep(i, N)
	{
		sfi(a[i].K);
		a[i].lo=a[i].hi=-1;
		a[i].indi=i+1;
	}
	
	int Q; sfi(Q);
	int res[Q+5];
	
	rept(i, N, N+Q-1)
	{
		sfi(a[i].lo), sfi(a[i].hi), sfi(a[i].K);
		a[i].indi=i-N;
	}
	
	sort(a, a+N+Q, cmp);
	
	rep(i, N+Q)
	{
		if(a[i].lo==-1)
		{
			update(a[i].indi, 1);
		}
		else
		{
			res[a[i].indi]=query(a[i].hi)-query(a[i].lo-1);
		}
	}
	
	rep(i, Q)
	pfi(res[i]);
	
	return (0);
}