// Author : Bony Roopchandani
// ARBITRAG
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

int main()
{
//	freopen("input.txt", "r", stdin);

	double dist[30+5][30+5], T;
	map<string, int> MAP;
	int C, N, M, cs=1;
	string x, y;
	bool cond;
	
	while(1)
	{
		sfi(N);
		
		if(!N)
		break;
		
		C=0;
		cond=false;
		
		rep(i, N)
		rep(j, N)
		dist[i][j]=0.0;
		
		rep(i, N)
		{
			cin>>x;
			if(!MAP.count(x))
			MAP[x]=C++;
		}
		
		sfi(M);
		
		rep(i, M)
		{
			cin>>x>>T>>y;
			dist[MAP[x]][MAP[y]]=T;
		}
		
		rep(i, N)
		rep(j, N)
		rep(k, N)
		dist[i][j]=max(dist[i][j], dist[i][k]*dist[k][j]);
		
		rep(i, N)
		{
			if(dist[i][i]>1.0)
			{
				cond=true;
				break;
			}
		}
		
		if(cond)
		printf("Case %d: Yes\n",cs++);
		else
		printf("Case %d: No\n",cs++);
		
		MAP.clear();
	}
	
	return 0;
}