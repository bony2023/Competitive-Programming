// Author : Bony Roopchandani
// SEAPERM2
// TopoSort

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
typedef list < int >LI;
typedef list < ll > LLL;
typedef map < int, bool > MIB;
typedef map < int, int >MII;
typedef map < int, ll > MIL;
typedef map < ll, int >MLI;
typedef pair < int, int >PII;
typedef pair < int, PII > PIII;
typedef pair < int, PIII > PIIII;
typedef pair < int, ll > PIL;
typedef pair < ll, int >PLI;
typedef set < int >SI;
typedef set < ll > SLL;
typedef vector < int >VI;
typedef vector < ll > VLL;
typedef vector < string > VS;

int N;
VI a[300 + 5], b[300 + 5], res;
int indeg[300 + 5], B[300+5][300+5];

void TopoSort(VI * p)
{
	queue < int >q;

	rept(i, 1, N) if (!indeg[i])
		q.push(i);

	while (!q.empty())
	{
		int z = q.front();
		q.pop();
		res.pb(z);

		rep(i, p[z].sz)
		{
			indeg[p[z][i]]--;

			if (!indeg[p[z][i]])
				q.push(p[z][i]);
		}
	}
}

bool solveforLow(int *t)
{
	memset(indeg, 0, sizeof indeg);

	int A[300 + 5][300 + 5];
	memcpy(A, B, sizeof B);
	VI L[300 + 5];
	bool done[300 + 5][300 + 5] = { 0 };

	rep(i, N)
	{
		int p = t[i];
		rep(j, N - 1)
		{
			if (A[i][j] >= p)
				A[i][j]++;
		}
		rep(j, N - 2)
		{
			if (!done[A[i][j]][A[i][j + 1]])
				L[A[i][j]].pb(A[i][j + 1]), done[A[i][j]][A[i][j + 1]] = 1, indeg[A[i][j + 1]]++;
		}
	}
	TopoSort(L);

	if (res.sz == N)
		return 1;
	else
	{
		res.clear();
		return 0;
	}
}

int main(void)
{
	int T;
	sfi(T);

	while (T--)
	{
		sfi(N);

		if (N <= 6)
		{
			 int tmp[N + 5];
			 
			rept(i, 1, N) tmp[i - 1] = i;
			
			rep(i, N)
			{
				rep(j, N - 1)
				{
					sfi(B[i][j]);
				}
			}
			
			do
			{
				if (solveforLow(tmp))
					break;
			}
			while (next_permutation(tmp, tmp + N));
			
			rep(i, res.sz) pf(res[i]);
			nl;
			
			res.clear();
			continue;
		}

		int x[300 + 5][300 + 5];
		int i, j;
		VI p[N + 5];

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N - 1; j++)
			{
				sfi(x[i][j]);

				if (x[i][j] != 1)
					a[i].pb(x[i][j]);

				if ((x[i][j] + 1) != N)
					b[i].pb(x[i][j] + 1);
			}
		}

		bool cond;

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (a[i][0] == b[j][0])
				{
					cond = true;

					rep(k, a[i].sz)
					{
						if (a[i][k] != b[j][k])
						{
							cond = false;
							break;
						}
					}
				}

				if (cond)
					break;
			}

			if (cond)
				break;
		}

		memset(indeg, 0, sizeof indeg);

		rep(k, N - 2) p[x[i][k]].pb(x[i][k + 1]), indeg[x[i][k + 1]]++;

		rep(k, N - 2) p[x[j][k] + 1].pb(x[j][k + 1] + 1), indeg[x[j][k + 1] + 1]++;

		TopoSort(p);

		rep(i, N) pf(res[i]);
		nl;

		rep(i, 300 + 5) a[i].clear(), b[i].clear(), p[i].clear();
	}

	return (0);
}