// Author : Bony Roopchandani
// 821 - Page Hopping
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

int main()
{
//	freopen("input.txt", "r", stdin);
	
	int x, y, N, cs=1;
	int dist[100+5][100+5];
	
	while(1)
	{
		N=0;
		sfi(x), sfi(y);
		
		if(!x && !y)
		break;
		
		if(x>N) N=x;
		else if(y>N) N=y;
		
		rept(i, 1, 102)
		rept(j, 1, 102)
		if(i==j) dist[i][j]=0;
		else dist[i][j]=INF;
		
		dist[x][y]=1;
		
		while(1)
		{
			sfi(x), sfi(y);
			
			if(!x && !y)
			break;
			
			if(x>N) N=x;
		else if(y>N) N=y;
			
			dist[x][y]=1;
		}
		
		rept(k, 1, N)
		rept(i, 1, N)
		rept(j, 1, N)
		dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
		
		double tot=0, totNodes=0;
		
		rept(i, 1, N)
		{
			rept(j, 1, N)
			{
				if(i!=j && dist[i][j]!=INF)
				{
					totNodes++;
					tot+=dist[i][j];
				}
			}
		}
		
		printf("Case %d: average length between pages = ",cs++);
		printf("%.3lf clicks\n",tot/totNodes);
	}
	
	return 0;
}