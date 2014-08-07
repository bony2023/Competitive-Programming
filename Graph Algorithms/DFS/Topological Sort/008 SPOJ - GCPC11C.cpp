// Author : Bony Roopchandani
// GCPC11C
// TopoSort

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<list>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
#define pb push_back
#define sz size()
#define mp make_pair
#define ff first
#define ss second
#define bg begin()
#define en end()
#define rep(i, n) for(int i=0; i<n; i++)
#define repi(i, n) for(int i=0; i<=n; i++)
#define rept(i, a, b) for(int i=a; i<=b; i++)
#define repd(i, a, b) for(int i=a; i>=b; i--)
#define ll long long
#define repl(i, n) for(ll i=0; i<n; i++)
#define repli(i, n) for(ll i=0; i<=n; i++)
#define pfi(a) printf("%d\n",a)
#define sfi(a) scanf("%d",&a)
#define pfl(a) printf("%lld\n",(ll)a)
#define sfl(a) scanf("%lld",&a)
#define sfs(a) scanf("%s",a)
#define pfs(a) printf("%s\n",a)
#define pf(a) printf("%d ",a)
#define nl printf("\n")
#define INF 9999999
#define CHUNK_SIZE 65536
#define MOD 1000000007
typedef vector < int >VI;
typedef vector < ll > VLL;
typedef pair < int, int >PII;
typedef pair < int, ll > PIL;
typedef pair < ll, int >PLI;
typedef pair < int, PII > PIII;
typedef pair < int, PIII > PIIII;
typedef map < int, int >MII;
typedef map < ll, int >MLI;
typedef map < int, ll > MIL;
typedef list < int >LI;
typedef list < ll > LLL;
typedef set < int >SI;
typedef set < ll > SLL;

VI A[10001];
map<PII, bool>B;
int indeg[10001] = { 0 };
LI foo;

void TopSort(int V)
{
	queue < int >Q;
	rept(i, 1, V) if (!indeg[i])
		Q.push(i);

	while (!Q.empty())
	{
		int z = Q.front();
		foo.pb(z);
		Q.pop();
		int s = A[z].sz;

		rep(i, s)
		{
			int u = A[z][i];
			indeg[u]--;
			if (!indeg[u])
				Q.push(u);
		}
	}
}

int checkUnique()
{
	LI::iterator a, b;
	b=foo.bg;
	b++;
	
	for(a=foo.bg; b!=foo.en; b++, a++)
	if(!B[mp(*a, *b)])
	return 0;
	
	return 1;
}

void scanint(int &x)
{
	register int c = getchar_unlocked();
	x = 0;
	int neg = 0;
	for (; ((c < 48 || c > 57) && c != '-'); c = getchar_unlocked());
	if (c == '-')
	{
		neg = 1;
		c = getchar_unlocked();
	}
	for (; c > 47 && c < 58; c = getchar_unlocked())
	{
		x = (x << 1) + (x << 3) + c - 48;
	}
	if (neg)
		x = -x;
}

void clearAll(int V)
{
	memset(indeg, 0, sizeof indeg);
	B.clear();
	foo.clear();
	rept(i, 1, V)
	A[i].clear();
}

int main(void)
{
//	freopen("input.txt", "r", stdin);
	int T;
	scanint(T);

	while (T--)
	{
		int N, M;

		scanint(N);
		scanint(M);
		int x, y;

		rep(i, M)
		{
			scanint(x);
			scanint(y);

			A[x].pb(y);
			B[mp(x, y)]=1;
			indeg[y]++;
		}

		TopSort(N);

		if(foo.sz != N)
		pfs("recheck hints");
		else if(!checkUnique())
		pfs("missing hints");
		else
		{
			LI::iterator t;
			t=foo.bg;
			printf("%d",*t);
			
			for(t++; t!=foo.en; t++)
			printf(" %d",*t);
			nl;
		}
			
		clearAll(N);
	}
	return 0;
}