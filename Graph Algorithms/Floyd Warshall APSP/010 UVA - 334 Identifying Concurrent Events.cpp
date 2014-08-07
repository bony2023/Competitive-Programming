// Author : Bony Roopchandani
// 334 - Identifying Concurrent Events
// Floyd Warshall Transitive Closure

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
	
	int N, M, cs=1;
	string x, y;
	map<string, int> MAP;
	map<int, string> PAM;
	int C;
	bool dist[200][200];
	
	while(sfi(N) && N)
	{
		C=0;
		
		memset(dist, 0, sizeof dist);
		
		rep(i, N)
		{
			sfi(M);
			
			rep(j, M)
			{
				cin>>y;
				
				if(!MAP.count(y))
				MAP[y]=C, PAM[C++]=y;
				
				if(j!=0)
				dist[MAP[x]][MAP[y]]=1;
				
				x=y;
			}
		}
			
		sfi(M);
		
		rep(i, M)
		{
			cin>>x>>y;
			dist[MAP[x]][MAP[y]]=1;
		}
		
		rep(k, C)
		rep(i, C)
		rep(j, C)
		dist[i][j]|=(dist[i][k]&dist[k][j]);
		
		vector<PII> A;
		
		rep(i, C)
		{
			rept(j, i+1, C-1)
			{
				if(!dist[i][j] && !dist[j][i])
				A.pb(mp(i, j));
			}
		}
		
		printf("Case %d, ", cs++);
		
		if(!A.sz)
		pfs("no concurrent events.");
		else
		{
			printf("%d concurrent events:\n", A.sz);
			
			int S;
			
			if(A.sz>2)
			S=2;
			else
			S=A.sz;
			
			rep(i, S)
			{
				string a=PAM[A[i].ff];
				string b=PAM[A[i].ss];
	      	cout<<"("<<a<<","<<b<<") ";
			}
			
			nl;
		}
		
		MAP.clear();
		PAM.clear();
	}
	
	return 0;
}