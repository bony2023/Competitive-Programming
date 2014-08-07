// Author : Bony Roopchandani
// 11047 - The Scrooge Co Problem
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

int P[100+5][100+5];
VI B;

void print_path(int i, int j)
{
	B.pb(i);
	for(i=P[i][j]; i!=j; i=P[i][j])
	{
		B.pb(i);
	}
	B.pb(j);
}

int main()
{
//	freopen("input.txt", "r", stdin);
	
	int T; sfi(T);
	int N, y, C;
	string x;
	map<string, int> MAP;
	map<int, string> PAM;
	int dist[100+5][100+5];
	string e, z;
	
	while(T--)
	{
		sfi(N);
		C=0;
		
		rep(i, N)
		{
			cin>>x;
			if(!MAP.count(x))
			MAP[x]=C, PAM[C++]=x;
		}
		
		rep(i, N)
		{
			rep(j, N)
			{
				sfi(y);
				
				if(y==-1)
				y=INF;
				
				dist[i][j]=y;
			}
		}
		
		rep(i, N)
		rep(j, N)
		P[i][j]=j;
		
		rep(k, N)
		rep(i, N)
		rep(j, N)
		if(dist[i][j]>dist[i][k]+dist[k][j])
		{
			dist[i][j]=dist[i][k]+dist[k][j];
			P[i][j]=P[i][k];
		}
		
		sfi(y);
		
		int c;
		
		rep(i, y)
		{
			cin>>e>>x>>z;
			c=dist[MAP[x]][MAP[z]];
			
			if(c==INF)
			{
				printf("Sorry Mr ");
				cout<<e;
				printf(" you can not go from ");
				cout<<x<<" to "<<z<<"\n";
			}
			else
			{
				printf("Mr ");
				cout<<e;
				printf(" to go from ");
				cout<<x<<" to "<<z;
				printf(", you will receive %d euros\n",c);
				
				print_path(MAP[x], MAP[z]);
				
				printf("Path:");
				rep(i, B.sz)
				{
					x=PAM[B[i]];
					
					if(i!=0)
					printf(" ");
					cout<<x;
				}
				
				if(B.sz==1)
				cout<<" "<<x;
				nl;
				
				B.clear();
			}
		}
		
		B.clear();
		MAP.clear();
		PAM.clear();
	}
	
	return 0;
}