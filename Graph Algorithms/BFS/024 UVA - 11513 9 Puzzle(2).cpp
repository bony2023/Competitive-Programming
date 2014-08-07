// Author : Bony Roopchandani
// 11513 - 9 Puzzle
// BFS

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<unordered_map>
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

unordered_map < ll, string > vis;

void pre()
{
	queue < ll > Q;
	ll a = 123456789;
	Q.push(a);
	vis[a] = "";

	while (!Q.empty())
	{
		ll z = Q.front();
		Q.pop();
		int t;
		char p, q, r;
		char foo[15];

		sprintf(foo, "%d", z);

		p = foo[0];
		q = foo[1];
		r = foo[2];
		foo[0] = q;
		foo[1] = r;
		foo[2] = p;

		t = atoi(foo);

		if (vis[t].sz == 0)
		{
			Q.push(t);
			string S = vis[z];
			S.append("1H");
			vis[t] = S;
		}

		sprintf(foo, "%d", z);

		p = foo[3];
		q = foo[4];
		r = foo[5];
		foo[3] = q;
		foo[4] = r;
		foo[5] = p;

		t = atoi(foo);

		if (vis[t].sz == 0)
		{
			Q.push(t);
			string S = vis[z];
			S.append("2H");
			vis[t] = S;
		}

		sprintf(foo, "%d", z);

		p = foo[6];
		q = foo[7];
		r = foo[8];
		foo[6] = q;
		foo[7] = r;
		foo[8] = p;

		t = atoi(foo);

		if (vis[t].sz == 0)
		{
			Q.push(t);
			string S = vis[z];
			S.append("3H");
			vis[t] = S;
		}

		sprintf(foo, "%d", z);

		p = foo[0];
		q = foo[3];
		r = foo[6];
		foo[0] = r;
		foo[3] = p;
		foo[6] = q;

		t = atoi(foo);

		if (vis[t].sz == 0)
		{
			Q.push(t);
			string S = vis[z];
			S.append("1V");
			vis[t] = S;
		}

		sprintf(foo, "%d", z);

		p = foo[1];
		q = foo[4];
		r = foo[7];
		foo[1] = r;
		foo[4] = p;
		foo[7] = q;

		t = atoi(foo);

		if (vis[t].sz == 0)
		{
			Q.push(t);
			string S = vis[z];
			S.append("2V");
			vis[t] = S;
		}

		sprintf(foo, "%d", z);

		p = foo[2];
		q = foo[5];
		r = foo[8];
		foo[2] = r;
		foo[5] = p;
		foo[8] = q;

		t = atoi(foo);

		if (vis[t].sz == 0)
		{
			Q.push(t);
			string S = vis[z];
			S.append("3V");
			vis[t] = S;
		}
	}
}

int main(void)
{
	pre();
//	freopen("input.txt", "r", stdin);
	int x;
	while (sfi(x) && x)
	{
		ll foo = x;
		rep(i, 8)
		{
			sfi(x);
			foo *= 10;
			foo += x;
		}
		if (foo == 123456789)
			pfi(0);
		else if (vis[foo].sz > 0)
		{
			int L = vis[foo].sz / 2;
			pf(L);
			repd(i, vis[foo].sz - 1, 0) cout << vis[foo][i];
			nl;
		}
		else
			pfs("Not solvable");
	}
	return 0;
}