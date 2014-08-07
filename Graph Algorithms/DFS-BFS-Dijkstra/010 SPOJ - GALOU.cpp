// Author : Bony Roopchandani
// GALOU
// Constrained BFS

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

int R, C;
char foo[110][110];

int dx[]={1, 0, -1, -1, 0, 1};
int dy[]={-1, -1, 0, 1, 1, 0};
vector<PII>S;

bool valid(int a, int b)
{
	return ((a>=0 && b>=0) && (a<R && b<C));
}

void BFS()
{
	PII u;
	bool state[3][105][105]={{{0}}};
	queue<PIII>Q;
	
	rep(i, S.sz)
	{
		u=S[i];
		Q.push(mp(0, mp(u.ff, u.ss)));
    	state[0][u.ff][u.ss]=1;
	}
	
	while(!Q.empty())
	{
		PIII z=Q.front();
		Q.pop();
		
		int a=z.ss.ff;
		int b=z.ss.ss;
		int currState=z.ff;
		
		int nextState=(currState+1)%2;
		
		rep(i, 6)
		{
			int p=a+dx[i];
			int q=b+dy[i];
			
			if(foo[p][q]=='*' && !state[nextState][p][q] && valid(p, q))
			{
				state[nextState][p][q]=1;
				Q.push(mp(nextState, mp(p, q)));
			}
		}
	}
	
	rep(i, R)
	{
		rep(j, C)
		{
			if(foo[i][j]=='*')
			{
				if(state[0][i][j]==state[1][i][j])
				{
					if(state[0][i][j]==1)
					foo[i][j]='B';
					else
					foo[i][j]='F';
				}
				else
				if(state[0][i][j]==1)
				foo[i][j]='(';
				else
				foo[i][j]=')';
			}
		}
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
	while(1)
	{
		sfi(R), sfi(C);
		
		if(!R && !C)
		break;
		
		rep(i, R)
		{
			sfs(foo[i]);
			
			rep(j, C)
			{
				if(foo[i][j]=='I')
		    	S.pb(mp(i, j)), foo[i][j]='*';
			}
		}
		
		nl;
		
		BFS();
		
		rep(i, R)
		pfs(foo[i]);
		
		S.clear();
	}
	
	return 0;
}