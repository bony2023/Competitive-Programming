// Author : Bony Roopchandani
// 1837 - Isenbaev's Number
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
typedef map < int, int >MII;
typedef map < ll, int >MLI;
typedef map < int, ll > MIL;
typedef list < int >LI;
typedef list < ll > LL;

map < string, vector < string > >mp;
map < string, int >dist;

void BFS(string u)
{
	map < string, bool > vis;

	queue < string > Q;
	vis[u] = true;
	Q.push(u);
	dist[u] = 0;

	while (!Q.empty())
	{
		string z = Q.front();
		Q.pop();

		for (vector < string >::iterator t = mp[z].bg; t != mp[z].en; t++)
		{
			if (vis[*t] == false)
			{
				dist[*t] = INF;
				vis[*t] = true;
				if (dist[*t] > dist[z] + 1)
					dist[*t] = dist[z] + 1;
				Q.push(*t);
			}
		}
	}
}

int main(void)
{
	int N;
	sfi(N);

	vector < string > name;
	map < string, int >done;

	rep(i, N)
	{
		string a, b, c;
		cin >> a >> b >> c;

		if (done[a] == 0)
		{
			name.pb(a);
			done[a] = 1;
		}
		if (done[b] == 0)
		{
			name.pb(b);
			done[b] = 1;
		}
		if (done[c] == 0)
		{
			name.pb(c);
			done[c] = 1;
		}

		mp[a].pb(b);
		mp[a].pb(c);
		mp[b].pb(a);
		mp[b].pb(c);
		mp[c].pb(a);
		mp[c].pb(b);
	}

	BFS("Isenbaev");

	// unique(name.bg, name.en);

	sort(name.bg, name.en);
	rep(i, name.sz)
	{
		cout << name[i] << " ";
		if (dist[name[i]] == 0 && name[i] != "Isenbaev")
			pfs("undefined");
		else
			cout << dist[name[i]] << "\n";
	}

	return 0;
}