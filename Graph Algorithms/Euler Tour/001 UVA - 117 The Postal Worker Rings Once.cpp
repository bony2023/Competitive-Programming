// Author : Bony Roopchandani
// 117 - The Postal Worker Rings Once
// Euler Path

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

class Euler
{
	VI A[30];
	int B[30][30];
	
	public:
	
	Euler()
	{
		rep(i, 26)
		rep(j, 26)
		B[i][j]=INF;
	}
	
	~Euler()
	{
		rep(i, 26)
		A[i].clear();
	}
	
	void process(char S[])
	{
		int x, y, w;
		int totWeight=0;
		
		while(strcmp(S, "deadend"))
		{
			x=S[0]-'a';
			y=S[strlen(S)-1]-'a';
			w=strlen(S);
			totWeight+=w;
			B[x][y]=B[y][x]=w;
			
			A[x].pb(y);
			A[y].pb(x);
			
			gets(S);
		}
		
		int u, v;
		bool cond=false;
		int t=0;
		
		rep(i, 26)
		{
			if(A[i].sz&1)
			{
				cond=true;
				if(t==0) {u=i, t=1; }
				else
				if(t==1) {v=i, t=INF; }
			}
		}
		
		if(!cond)
		{
			pfi(totWeight);
		}
		else
		{
			int ShortPath=Floyd(u, v);
			int tot;
			tot=ShortPath+totWeight;
			
			pfi(tot);
		}
	}
	
	int Floyd(int u, int v)
	{
		rep(k, 26)
		rep(i, 26)
		rep(j, 26)
		B[i][j]=min(B[i][j], B[i][k]+B[k][j]);
		
		return B[u][v];
	}
};

int main()
{
//	freopen("input.txt", "r", stdin);
	
	char S[100];
	
	while(gets(S))
	{
		Euler E;
    	E.process(S);
	}
	
	return 0;
}