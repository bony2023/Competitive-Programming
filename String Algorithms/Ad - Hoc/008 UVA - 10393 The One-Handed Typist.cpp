// Author : Bony Roopchandani
// 10393 - The One-Handed Typist
// String - Ad - Hoc

// INCLUDES
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <map>
#include <list>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

// MACROS
#define pb push_back
#define sz size()
#define mp make_pair
#define ff first
#define ss second
#define bg begin()
#define en end()
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i=0; i<n; i++)
#define rept(i, a, b) for(int i=a; i<=b; i++)
#define repd(i, a, b) for(int i=a; i>=b; i--)
#define ll long long
#define repl(i, n) for(ll i=0; i<n; i++)
#define replt(i, a, b) for(ll i=a; i<=b; i++)
#define repld(i, a, b) for(ll i=a; i>=b; i--)
#define pfi(a) printf("%d\n",a)
#define sfi(a) scanf("%d",&a)
#define pfl(a) printf("%lld\n",(ll)a)
#define sfl(a) scanf("%lld",&a)
#define sfs(a) scanf("%s",a)
#define pfs(a) printf("%s\n",a)
#define pf(a) printf("%d ",a)
#define nl printf("\n")
#define INF 9999999
#define MOD (1e9 + 7)

// TYPEDEFS
typedef vector < int > VI;
typedef vector < ll > VLL;
typedef vector < string > VS;
typedef pair < int, int > PII;
typedef pair < int, PII > PIII;
typedef pair < int, PIII > PIIII;
typedef pair < int, ll > PIL;
typedef pair < ll, int > PLI;
typedef map < int, int > MII;
typedef map < ll, int > MLI;
typedef map < int, ll > MIL;
typedef map < int, bool > MIB;
typedef list < int > LI;
typedef list < ll > LLL;
typedef set < int > SI;
typedef set < ll > SLL;

int Finger[200];

void preFinger()
{
	Finger['q']=1;
	Finger['a']=1;
	Finger['z']=1;
	Finger['w']=2;
	Finger['s']=2;
	Finger['x']=2;
	Finger['e']=3;
	Finger['d']=3;
	Finger['c']=3;
	Finger['r']=4;
	Finger['f']=4;
	Finger['v']=4;
	Finger['t']=4;
	Finger['g']=4;
	Finger['b']=4;
	Finger['y']=7;
	Finger['h']=7;
	Finger['n']=7;
	Finger['u']=7;
	Finger['j']=7;
	Finger['m']=7;
	Finger['i']=8;
	Finger['k']=8;
	Finger['o']=9;
	Finger['l']=9;
	Finger['p']=10;
}

class myComp
{
	public:
	bool operator() (string a, string b)
	const
	{
		return (a<b);
	}
};

class Words
{
	set<string, myComp> S;
	bool* Forb;
	int n, m;
	
	public:
	
	Words(int N, int s)
	{
		n=N; m=s;
		Forb = new bool[10+5]();
	}
	
	~Words()
	{
		delete []Forb;
		S.clear();
	}
	
	void process()
	{
		int x;
		string X[m+5];
		
		rep(i, n)
		{
			sfi(x), Forb[x]=1;
		}
		
		rep(i, m)
		{
			cin>>X[i];
			S.insert(X[i]);
		}
		
		bool cond=true;
		char temp[50+5];
		int maxx=0;
		string y;
		
		rep(i, m)
		{
			cond=true;
			strcpy(temp, X[i].c_str());

			rep(j, strlen(temp))
			{
				if(Forb[Finger[temp[j]]])
				{
					cond=false;
					break;
				}
			}
			
			if(!cond)
			S.erase(X[i]);
			else
			 if(maxx<X[i].sz)
			 maxx=X[i].sz;
		}
		
		rep(i, m)
		{
			if(X[i].sz != maxx)
			S.erase(X[i]);
		}
		
		set<string>::iterator t=S.bg;
		
		pfi(S.sz);
		
		for(; t!=S.en; t++)
		cout<<*t, nl;
	}
};

int main()
{
//	freopen("input.txt", "r", stdin);
	
	int N, M;
	preFinger();
	
	while(scanf("%d %d", &N,&M)==2)
	{
		Words W(N, M);
		W.process();
	}
	
	return 0;
}