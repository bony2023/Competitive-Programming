// Author : Bony Roopchandani
// 571 - Jugs
// BFS

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<list>
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
typedef vector < int >VI;
typedef vector < ll > VL;
typedef pair < int, int >PII;
typedef pair < int, ll > PIL;
typedef pair < ll, int >PLI;
typedef pair < int, PII > PIII;
typedef map < int, int >MII;
typedef map < ll, int >MLI;
typedef map < int, ll > MIL;
typedef list < int >LI;
typedef list < ll > LL;
typedef pair < string, PII > PSPP;

string foo[] =
	{ "fill A", "fill B", "empty A", "empty B", "pour A B", "pour B A" };

int A, B, N;

map < PSPP, PSPP > pred;

pair < string, int >BFS()
{
	queue < pair < string, PII > >Q;
	map < PII, bool > vis;
	Q.push(mp("NULL", mp(0, 0)));
	vis[mp(0, 0)] = 1;

	while (!Q.empty())
	{
		PSPP z = Q.front();
		Q.pop();

		string S = z.ff;
		int x = z.ss.ff;
		int y = z.ss.ss;

		rep(i, 6)
		{
			int p, q;

			if (i == 0)
			{
				p = A;
				q = y;
			}

			if (i == 1)
			{
				p = x;
				q = B;
			}

			if (i == 2)
			{
				p = 0;
				q = y;
			}

			if (i == 3)
			{
				p = x;
				q = 0;
			}

			if (i == 4)
			{
				p = x;
				q = y;
				q += p;
				if (q > B)
					p = q - B, q = B;
				else
					p = 0;
			}

			if (i == 5)
			{
				p = x;
				q = y;
				p += q;
				if (p > A)
					q = p - A, p = A;
				else
					q = 0;
			}

			if (!vis[mp(p, q)])
			{
				vis[mp(p, q)] = 1;
				Q.push(mp(foo[i], mp(p, q)));
				pred[mp(foo[i], mp(p, q))] = mp(S, mp(x, y));

				if (q == N)
				{
					return mp(foo[i], p);
				}
			}
		}
	}
}

int main(void)
{
//	freopen("input.txt", "r", stdin);
	vector < string > S;
	while (sfi(A) != EOF)
	{
		sfi(B);
		sfi(N);

		pair < string, int >P = BFS();
		string x = P.ff;
		int y = P.ss;
		int z = N;

		while (x != "NULL")
		{
			S.pb(x);
			string m;
			int n;
			int o;

			m = pred[mp(x, mp(y, z))].ff;
			n = pred[mp(x, mp(y, z))].ss.ff;
			o = pred[mp(x, mp(y, z))].ss.ss;

			x = m;
			y = n;
			z = o;
		}
		repd(i, S.sz - 1, 0) cout << S[i] << endl;
		pfs("success");

		S.clear();
	}
	return 0;
}