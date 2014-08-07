// Author : Bony Roopchandani
// SOCIALNE
// Floyd Warshall Transitive Closure

// INCLUDES
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
typedef vector < int >VI;
typedef vector < ll > VLL;
typedef vector < string > VS;
typedef pair < int, int >PII;
typedef pair < int, PII > PIII;
typedef pair < int, PIII > PIIII;
typedef pair < int, ll > PIL;
typedef pair < ll, int >PLI;
typedef map < int, int >MII;
typedef map < ll, int >MLI;
typedef map < int, ll > MIL;
typedef map < int, bool > MIB;
typedef list < int >LI;
typedef list < ll > LLL;
typedef set < int >SI;
typedef set < ll > SLL;

int dist[50+5][50+5];

int input()
{
	char foo[50+5][50+5];
	sfs(foo[0]);
	int N=strlen(foo[0]);
	
	rep(i, strlen(foo[0]))
	{
		if(foo[0][i]=='Y')
		dist[0][i]=1;
		else dist[0][i]=INF;
	}
	
	rept(i, 1, N-1)
	{
		sfs(foo[i]);
		
		rep(j, N)
		if(foo[i][j]=='Y')
		dist[i][j]=1;
		else dist[i][j]=INF;
	}
	return N;
}

int main()
{
//	freopen("input.txt", "r", stdin);
	
	int T; sfi(T);
	
	while(T--)
	{
		int N=input();
		
		rep(k, N)
		rep(i, N)
		rep(j, N)
		dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);

		int id=0, mx=0;
		int pos=0, maxx=0;
		
		rep(i, N)
		{
			rep(j, N)
			{
				if(dist[i][j]==2 && i!=j)
				{
					id=i;
					mx++;
				}
			}
			
			if(mx>maxx)
			pos=id, maxx=mx;
			
			mx=0;
		}
		
		pf(pos), pfi(maxx);
	}
	
	return 0;
}