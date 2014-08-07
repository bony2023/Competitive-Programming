// Author : Bony Roopchandani
// TOPOSORT
// Topological Sort

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<list>
#include<set>
#include<fstream>
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
#define MOD 1000000007
#define MAX_CHUNK_SIZE 65536
typedef vector < int >VI;
typedef vector < ll > VL;
typedef pair < int, int >PII;
typedef pair < int, ll > PIL;
typedef pair < ll, int >PLI;
typedef pair < int, PII > PIII;
typedef pair < int, PIII > PIIII;
typedef map < int, int >MII;
typedef map < ll, int >MLI;
typedef map < int, ll > MIL;
typedef list < int >LI;
typedef list < ll > LL;

class myComp
{
  public:
	bool operator() (const int a, const int b)const
	{
		return (a < b);
	}
};

VI A[10002];
int indeg[10002] = { 0 };
LI foo;

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

void TopoSort(int V)
{
	set < int, myComp > S;
	rept(i, 1, V)
	{
		if (!indeg[i])
			S.insert(i);
	}

	set < int, myComp >::iterator t;

	while (!S.empty())
	{
		t = S.begin();
		int z = *t;
		foo.pb(z);
		S.erase(S.begin());

		int s = A[z].sz;

		rep(i, s)
		{
			int u = A[z][i];

			indeg[u]--;

			if (indeg[u] == 0)
				S.insert(u);
		}
	}
}

int main(void)
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
		indeg[y]++;
	}

	TopoSort(N);

	if (foo.sz != N)
		pfs("Sandro fails.");
	else
	{
		LI::iterator t=foo.bg;
		printf("%d",*t);
		for (t++; t != foo.en; t++)
			printf(" %d",*t);
		nl;
	}

	return 0;
}