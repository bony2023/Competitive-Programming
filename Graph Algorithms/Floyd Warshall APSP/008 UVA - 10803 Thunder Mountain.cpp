// Author : Bony Roopchandani
// 10803 - Thunder Mountain
// Floyd Warshall

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

double compute(int x1, int y1, int x2, int y2)
{
	double a=x1-x2;
	double b=y1-y2;
	
	return hypot(a, b);
}

int main()
{
//	freopen("input.txt", "r", stdin);
	
	int T; sfi(T);
	int x[100+5], y[100+5];
	double dist[100+5][100+5];
	int N, cs=1;
	
	while(T--)
	{
		sfi(N);
		
		rep(i, N)
		{
			sfi(x[i]), sfi(y[i]);
		}
		
		rep(i, N)
		{
			rep(j, N)
			if(i==j) dist[i][j]=0;
			else dist[i][j]=INF;
		}
		
		rep(i, N-1)
		{
			rept(j, i+1, N-1)
			{
				double c=compute(x[i], y[i], x[j], y[j]);
				
				if(c<=10.0)
				dist[i][j]=dist[j][i]=c;
			}
		}
		
		rep(k, N)
		rep(i, N)
		rep(j, N)
		dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
		
		double mx=0.0;
		
		rep(i, N)
		{
			rep(j, N)
			mx=max(mx, dist[i][j]);
		}
		
		printf("Case #%d:\n", cs++);
		
		if(mx==(double)INF)
		printf("Send Kurdy\n\n");
		else
		printf("%.4lf\n\n", mx);
	}
	
	return 0;
}