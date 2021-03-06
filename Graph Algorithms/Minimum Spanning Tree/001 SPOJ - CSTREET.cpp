// Author : Bony Roopchandani
// CSTREET
// Kruskal's Algorithm

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
typedef vector<int> VI;
typedef vector<ll> VLL;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<int, ll> PIL;
typedef pair<ll, int> PLI;
typedef pair<int, PII> PIII;
typedef pair<int, PIII> PIIII;
typedef map<int, int> MII;
typedef map<ll, int> MLI;
typedef map<int, ll> MIL;
typedef list<int> LI;
typedef list<ll> LLL;
typedef set<int> SI;
typedef set<ll> SLL;

class UnionFind
{
	VI Parent;
	
	public:
	
	UnionFind(int V)
	{
		Parent.assign(V+1, 0);
		rep(i, V)
		Parent[i]=i;
	}
	
	int FindSet(int i)
	{
		return (Parent[i]==i)?i:Parent[i]=FindSet(Parent[i]);
	}
	
	bool isSameSet(int i, int j)
	{
		return (FindSet(i)==FindSet(j));
	}
	
	void UnionSet(int i, int j)
	{
		Parent[FindSet(i)]=FindSet(j);
	}
};

int main(void)
{
//	freopen("input.txt", "r", stdin);
	int T; sfi(T);
	
	while(T--)
	{
		ll P;
		sfl(P);
		
		int N, M;
		sfi(N), sfi(M);
		
		vector<pair<ll, PII> >A;
		UnionFind U(N+5);
		
		int a, b, c;
		
		rep(i, M)
		{
			sfi(a), sfi(b), sfi(c);
			A.pb(mp(c, mp(a, b)));
		}
		
		sort(A.bg, A.en);
		ll minCost=0;
		
		rep(i, M)
		{
			if(!U.isSameSet(A[i].ss.ff, A[i].ss.ss))
			{
				minCost+=A[i].ff;
				U.UnionSet(A[i].ss.ff, A[i].ss.ss);
			}
		}
		
		pfl(minCost*P);
	}
	return 0;
}