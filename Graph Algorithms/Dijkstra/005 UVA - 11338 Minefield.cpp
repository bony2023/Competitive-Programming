// Author : Bony Roopchandani
// 11338 - Minefield
// Dijkstra

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

vector<pair<double, int> > A[10000+10];
int N;

double Dijkstra(int u, int v)
{
	vector<double>dist(N+5, INF);
	dist[u]=0;
	priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > >Q;
	
	Q.push(mp(0, u));
	
	while(!Q.empty())
	{
		pair<double, int> z=Q.top();
		Q.pop();
		
		int a=z.ss;
		double c=z.ff;
		
		if(dist[a]==c)
		{
			rep(i, A[a].sz)
			{
				int p=A[a][i].ss;
				double w=A[a][i].ff;
				
				if(dist[p]>dist[a]+w)
				{
					dist[p]=dist[a]+w;
					Q.push(mp(dist[p], p));
				}
			}
		}
	}
	
	return dist[v];
}

double compute(double x1, double y1, double x2, double y2)
{
	double a=(x1-x2);
	double b=(y1-y2);
	
	return hypot(a, b);
}

int main()
{
//	freopen("input.txt","r", stdin);
	while(1)
	{
		char inp[50];
		gets(inp);
		
		if(!strcmp(inp, "*"))
		break;
		
		double W, H;
		sscanf(inp, "%lf %lf", &W, &H);
		
		sfi(N);
		double x[10000+10]; 
		double y[10000+10];
		int T=0;
		map<pair<double, double>, int>M;
		int k=0;
		
		rep(i, N)
		{
			scanf("%lf %lf",&x[i], &y[i]);
			
			M[mp(x[i], y[i])]=T++;
		}
		
		if(!M.count(mp(W, H)))
		{
			M[mp(W, H)]=T++;
			x[N]=W;
			y[N]=H;
			N++;
		}
		if(!M.count(mp(0, 0)))
		{
			M[mp(0, 0)]=T++;
			x[N]=0;
			y[N]=0;
			N++;
		}
		
		double limit;
		scanf("%lf",&limit);
		
		rep(i, N)
		{
			rept(j, i+1, N)
			{
				double C=compute(x[i], y[i], x[j], y[j]);
				
				if(C<=(double)1.5)
				{
					int p=M[mp(x[i], y[i])];
					int q=M[mp(x[j], y[j])];
					
					A[p].pb(mp(C, q));
					A[q].pb(mp(C, p));
				}
			}
		}
		
		double P=Dijkstra(M[mp(0, 0)], M[mp(W, H)]);
		
		if(P>limit)
		pfs("Boom!");
		else
		pfs("I am lucky!");
		
		rep(i, N+10)
		A[i].clear();
		
		getchar();
	}
	
	return 0;
}