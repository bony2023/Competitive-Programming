// Author : Bony Roopchandani
// 10199 - Tourist Guide
// Articulation Points on Graph

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

string S[101];
map < string, bool > vis;
map < string, bool > B;
map < string, vector < string > >A;
string dfsRoot;
int dfsCounter, dfsRootChild;
map < string, int >dfsLow;
map < string, int >dfsNum;
map < string, string > dfsParent;
vector<string>foo;

void AP(string u)
{
	vis[u] = 1;
	dfsLow[u] = dfsNum[u] = dfsCounter++;
	int s = A[u].sz;

	rep(i, s)
	{
		string z = A[u][i];

		if (!vis[z])
		{
			dfsParent[z] = u;

			if (u == dfsRoot)
				dfsRootChild++;

			AP(z);

			if (dfsLow[z] >= dfsNum[u])
			B[u]=1;

			dfsLow[u] = min(dfsLow[u], dfsLow[z]);
		}
		else if (z != dfsParent[u])
			dfsLow[u] = min(dfsLow[u], dfsNum[z]);
	}
}

void clearAll()
{
	vis.clear();
	A.clear();
	B.clear();
	dfsLow.clear();
	dfsNum.clear();
	dfsParent.clear();
	foo.clear();
}

int main(void)
{
//	freopen("input.txt", "r", stdin);
	int N, cs = 1;

	while (sfi(N) && N)
	{
		rep(i, N)
		{
			cin >> S[i];
		}

		int M;
		sfi(M);

		string x, y;

		rep(i, M)
		{
			cin >> x >> y;
			A[x].pb(y);
			A[y].pb(x);
		}

		dfsCounter = 0;

		rep(i, N)
		{
			if (!vis[S[i]])
			{
				dfsRoot = S[i];
				dfsRootChild = 0;

				AP(S[i]);

				bool t = B[dfsRoot];
				B[dfsRoot] = (dfsRootChild > 1);
			}
		}

		rep(i, N)
		{
			if (B[S[i]])
				foo.pb(S[i]);
		}
		
		sort(foo.bg, foo.en);
		
		if (cs == 1)
			printf("City map #%d: %d camera(s) found\n", cs++, foo.sz);
		else
			printf("\nCity map #%d: %d camera(s) found\n", cs++, foo.sz);
			
			rep(i, foo.sz)
			cout<<foo[i]<<"\n";

		clearAll();
	}
	return 0;
}