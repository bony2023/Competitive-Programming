// Author : Bony Roopchandani
// 11228 - Transportation system.
// Kruskal's MST

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
	int TotalSet;
	
	public:
	
	UnionFind(int V)
	{
		Parent.assign(V+1, 0);
		rep(i, V)
		Parent[i]=i;
		TotalSet=V;
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
		if(!(Parent[i]==Parent[j]))
		TotalSet-=1;
		Parent[FindSet(i)]=FindSet(j);
	}
	
	int GetSet()
	{
		return TotalSet;
	}
};

double compute(int x1, int y1, int x2, int y2)
{
	double a=(x2-x1)*(x2-x1);
	double b=(y2-y1)*(y2-y1);
	
	return ((sqrt(a+b)));
}

int main(void)
{
	int cs=1;
//	freopen("input.txt", "r", stdin);
	int T; sfi(T);
	
	while(T--)
	{
		int N;
		double R;
		
		sfi(N), scanf("%lf", &R);
		
		int x[1000+5];
		int y[1000+5];
		vector<pair<double, PII> >A;
		
		rep(i, N)
		{
			sfi(x[i]), sfi(y[i]);
		}
		
		rep(i, N)
		{
			rept(j, i+1, N-1)
			{
				double T=compute(x[i], y[i], x[j], y[j]);
				
				A.pb(mp(T, mp(i, j)));
			}
		}
		
		sort(A.bg, A.en);
		UnionFind U(N+5);
	    int State=1;
		double StateCost=0, CityCost=0;
		
		rep(i, A.sz)
		{
			int a=A[i].ss.ff;
			int b=A[i].ss.ss;
			if(!U.isSameSet(a, b))
			{
				U.UnionSet(a, b);
				
				if(A[i].ff>R)
				State++, StateCost+=A[i].ff;
				else
				CityCost+=A[i].ff;
			}
		}
		
		printf("Case #%d: ", cs++);
		
		pf(State), pf((int)(CityCost+0.5)),  pfi((int)(StateCost+0.5));
	}
	
	return 0;
}