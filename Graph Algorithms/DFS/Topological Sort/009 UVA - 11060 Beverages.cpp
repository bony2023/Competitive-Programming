// Author : Bony Roopchandani
// 11060 - Beverages
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
typedef vector<int> VI;
typedef vector<ll> VLL;
typedef pair<int, int> PII;
typedef pair<int, ll> PIL;
typedef pair<ll, int> PLI;
typedef pair<int, PII>PIII;
typedef pair<int, PIII> PIIII;
typedef map<int, int> MII;
typedef map<ll, int> MLI;
typedef map<int, ll> MIL;
typedef list<int> LI;
typedef list<ll> LLL;
typedef set<int> SI;
typedef set<ll> SLL;

map<string, int>key;
map<string, vector<string> >A;
map<string, int>indeg;
string B[101];
list<string>foo;

class myComp
{
	public:
	bool operator()(string a, string b)
	const
	{
		return (key[a]<key[b]);
	}
};

void TopSort(int V)
{
	set<string, myComp>S;
	set<string, myComp>::iterator t;
	rept(i, 1, V)
	{
		if(!indeg[B[i]])
		S.insert(B[i]);
	}
	
	while(!S.empty())
	{
		t=S.begin();
		string z=*t;
		foo.pb(z);
		S.erase(S.begin());
		int s=A[z].sz;
		
		rep(i, s)
		{
			string u=A[z][i];
			
			indeg[u]--;
			
			if(!indeg[u])
			S.insert(u);
		}
	}
}

void clearAll()
{
	key.clear();
	A.clear();
	foo.clear();
	indeg.clear();
}

int main(void)
{
//	freopen("input.txt", "r", stdin);
	int c=1;
	int N;
	
	while(sfi(N)!=EOF)
	{
		rept(i, 1, N)
		{
			cin>>B[i];
			key[B[i]]=i;
		}
		
		int M; sfi(M);
		string x, y;
		
		rep(i, M)
		{
			cin>>x>>y;
			A[x].pb(y);
			indeg[y]+=1;
		}
		
		TopSort(N);
		
		printf("Case #%d: Dilbert should drink beverages in this order:",c++);
		
		list<string>::iterator t;
		
		for(t=foo.bg; t!=foo.en; t++)
		cout<<" "<<*t;
		pfs(".");
		nl;
		
		clearAll();
	}
	return 0;
}