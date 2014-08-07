// Author : Bony Roopchandani
// 341 - Non-Stop Travel
// Floyd Warshall

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

int dist[10+5][10+5];
int Parent[10+5][10+5];
		
void print_path(int i, int j)
{
	if(i!=j)
	print_path(i, Parent[i][j]);
	printf(" %d",j);
}

int main()
{
//	freopen("input.txt", "r", stdin);
	
	int N, cs=1;
	
	while(1)
	{
		sfi(N);
		
		if(!N)
		break;
		
		memset(dist, 0, sizeof dist);
		memset(Parent, 0, sizeof Parent);
		
		rept(i, 1, N)
		rept(j, 1, N)
		Parent[i][j]=i;
		
		rept(i, 1, N)
		rept(j, 1, N)
		dist[i][j]=INF;
		
		rept(i, 1, N)
		dist[i][i]=0;
		
		int M, x, c;
		
		rept(i, 1, N)
		{
			sfi(M);
			
			rep(j, M)
			{
				sfi(x), sfi(c);
				
				dist[i][x]=c;
			}
		}
		
		rept(k, 1, N)
		rept(i, 1, N)
		rept(j, 1, N)
		if(dist[i][j]>dist[i][k]+dist[k][j])
		{
			dist[i][j]=dist[i][k]+dist[k][j];
			Parent[i][j]=Parent[k][j];
		}
		
		int u, v;
		sfi(u), sfi(v);
		
		printf("Case %d: ",cs++);
		printf("Path =");
		print_path(u, v);
		if(!dist[u][v])
		print_path(u, v);
		printf("; ");
		printf("%d second delay\n",dist[u][v]);
	}
	
	return 0;
}