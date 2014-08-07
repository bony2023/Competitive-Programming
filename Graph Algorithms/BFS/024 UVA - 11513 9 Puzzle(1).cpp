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
		char foo[15];

		rep(i, 3)
		{
			sprintf(foo, "%lld", z);
			string S = vis[z];
			int index = i * 3 + 2;
			int tmp = foo[index - 2];
			foo[index - 2] = foo[index - 1];
			foo[index - 1] = foo[index];
			foo[index] = tmp;
			int t=atoi(foo);
			if (vis[t].sz>0)
				continue;
			
			string p;
			if(i==0)
			p="1H";
			else if(i==1)
			p="2H";
			else p="3H";
			S.append(p);
			Q.push(t);
			vis[t] = S;
		}

		rep(i, 3)
		{
			sprintf(foo, "%lld", z);
			string S = vis[z];
			int tmp = foo[i + 6];
			foo[i + 6] = foo[i + 3];
			foo[i + 3] = foo[i];
			foo[i] = tmp;
			int t=atoi(foo);
			if (vis[t].sz>0)
				continue;
				
			string p;
			if(i==0)
			p="1V";
			else if(i==1)
			p="2V";
			else p="3V";
			S.append(p);
			Q.push(t);
			vis[t] = S;
		}
	}
}

int main(void)
{
	pre();
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