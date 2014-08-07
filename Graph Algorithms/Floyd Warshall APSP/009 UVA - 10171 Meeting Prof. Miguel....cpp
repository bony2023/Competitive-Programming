// Author : Bony Roopchandani
// 10171 - Meeting Prof. Miguel...
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

int distM[30][30];
int distY[30][30];
const int P=26;

void Floyd1(int N)
{
	rep(k, N)
	rep(i, N)
	rep(j, N)
	distY[i][j]=min(distY[i][j], distY[i][k]+distY[k][j]);
}

void Floyd2(int N)
{
	rep(k, N)
	rep(i, N)
	rep(j, N)
	distM[i][j]=min(distM[i][j], distM[i][k]+distM[k][j]);
}

void input(int N)
{
	char a, b, c, d;
	int e;

	while (N--)
	{
		cin>>a>>b>>c>>d;
		sfi(e);

		if (a == 'Y')
		{
			if (b == 'U')
				distY[c - 'A'][d - 'A'] = e;
			else
				distY[c - 'A'][d - 'A'] = distY[d - 'A'][c - 'A'] = e;
		}
		else if (a == 'M')
		{
			if (b == 'U')
				distM[c - 'A'][d - 'A'] = e;
			else
				distM[c - 'A'][d - 'A'] = distM[d - 'A'][c - 'A'] = e;
		}
	}
	
	rep(i, P)
	distY[i][i]=distM[i][i]=0;
}

int main()
{
//	freopen("input.txt", "r", stdin);
	
	int N;

	while (sfi(N) && N)
	{
		rep(i, P)
		rep(j, P)
		if (i == j)
			distY[i][j] = distM[i][j] = 0;
		else
			distY[i][j] = distM[i][j] = INF;

		input(N);
		
		char Y, M;
		
		cin>>Y>>M;
		
		int S=Y-'A';
		int E=M-'A';
		
		Floyd1(P);
		Floyd2(P);
		
		int mx=INF;
		
		rep(i, P)
		{
			if(distY[S][i]==INF ||distM[E][i]==INF)
			continue;
			if(distY[S][i]+distM[E][i]<mx)
			{
				mx=distY[S][i]+distM[E][i];
			}
		}
		
		if(mx==INF)
		pfs("You will never meet.");
		else
		{
			printf("%d",mx);
		    
		    rep(i, P)
		    {
		    	if(distY[S][i]+distM[E][i]==mx)
		    	{
		    		printf(" %c",i+'A');
		    	}
		    }
		    nl;
		}
	}

	return 0;
}