// Author : Bony Roopchandani
// WORDS1
// Euler Path Directed Graph

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
	int* indeg;
	int* outdeg;
	bool* vis;
	VI* A;
	
	public:
	
	Euler()
	{
		indeg = new int[30]();
		outdeg = new int[30]();
		vis = new bool[30]();
		A = new VI[30];
	}
	
	~Euler()
	{
		if(indeg) delete []indeg;
		if(outdeg) delete []outdeg;
		if(vis) delete []vis;
		if(A) delete []A;
	}
	
	void process()
	{
		int N; sfi(N);
		getchar();
		char S[1000+5];
		int u, v;
		
		rep(i, N)
		{
			gets(S);
			u=S[0]-'a';
			v=S[strlen(S)-1]-'a';
			
			indeg[u]++;
			outdeg[v]++;
			A[u].pb(v);
			A[v].pb(u);
		}
		
		bool c1, c2;
		
		c1=isConnected();
		c2=isEuler();
		
		if(c1 && c2)
		puts("Ordering is possible.");
		else
		puts("The door cannot be opened.");
	}
	
	bool isConnected()
	{
		int cmp=0;
		
		rep(i, 26)
		if(!vis[i] && A[i].sz)
		cmp++, dfs(i);
		
		if(cmp==1)
		return true;
		
		return false;
	}
	
	void dfs(int u)
	{
		vis[u]=1;
		
		rep(i, A[u].sz)
		if(!vis[A[u][i]])
		dfs(A[u][i]);
	}
	
	bool isEuler()
	{
		int cnt1=0, cnt2=0;
		
		rep(i, 26)
		{
			if(indeg[i]-outdeg[i] == 1)
			cnt1++;
			else
			if(outdeg[i]-indeg[i] == 1)
			cnt2++;
			else
			if(indeg[i] != outdeg[i])
			return false;
		}
		
		if(cnt1+cnt2==0)
		return true;
		else
		if(cnt1==1 && cnt2==1)
		return true;
		else
		return false;
	}
};

int main()
{
	int T; sfi(T);
	
	while(T--)
	{
		Euler E;
		E.process();
	}
	
	return 0;
}