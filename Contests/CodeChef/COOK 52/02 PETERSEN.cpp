// Author : Bony Roopchandani
// 

// INCLUDES
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// MACROS
#define all(a) a.begin(), a.end()
#define bg begin()
#define en end()
#define ff first
#define in(a) freopen(a, "r", stdin)
#define ll long long
#define mp make_pair
#define nl printf("\n")
#define out(a) freopen(a, "w", stdout)
#define pb push_back
#define pf(a) printf("%d ",a)
#define pfi(a) printf("%d\n",a)
#define pfl(a) printf("%lld\n",(ll)a)
#define pfs(a) printf("%s\n",a)
#define rep(i, n) for(int i=0; i<n; i++)
#define repd(i, a, b) for(int i=a; i>=b; i--)
#define repl(i, n) for(ll i=0; i<n; i++)
#define repld(i, a, b) for(ll i=a; i>=b; i--)
#define replt(i, a, b) for(ll i=a; i<=b; i++)
#define rept(i, a, b) for(int i=a; i<=b; i++)
#define sfi(a) scanf("%d",&a)
#define sfl(a) scanf("%lld",&a)
#define sfs(a) scanf("%s",a)
#define ss second
#define sz size()

// CONSTS
const double EPS = (1e-11);
const double PI = acos(-1.0);
const int INF = 9999999;
const int MOD = (1e9 + 7);

// TYPEDEFS
typedef list < int > LI;
typedef list < ll > LLL;
typedef map < int, bool > MIB;
typedef map < int, int > MII;
typedef map < int, ll > MIL;
typedef map < ll, int > MLI;
typedef pair < int, int > PII;
typedef pair < int, PII > PIII;
typedef pair < int, PIII > PIIII;
typedef pair < int, ll > PIL;
typedef pair < ll, int > PLI;
typedef set < int > SI;
typedef set < ll > SLL;
typedef vector < int > VI;
typedef vector < ll > VLL;
typedef vector < string > VS;

bool Q[20][20]={0};
VI a[100000+5];
int len, num[100000+5];
bool done;

void dfs(int ind, int pa)
{
	if(done) return;
	
	if(ind==len)
	{
		rep(i, len)
		cout<<num[i]; nl;
		done=true;
		return;
	}
	
	rep(i, a[ind].sz)
	{
		if(pa==-1)
		{
			num[ind]=a[ind][i];
			dfs(ind+1, a[ind][i]);
		}
		else
		{
			if(Q[pa][a[ind][i]])
			{
				num[ind]=a[ind][i];
				dfs(ind+1, a[ind][i]);
			}
		}
	}
}

int main(void)
{
	int T; sfi(T);
	
	Q[0][1]=Q[1][0]=1;
	Q[1][2]=Q[2][1]=1;
	Q[2][3]=Q[3][2]=1;
	Q[3][4]=Q[4][3]=1;
	Q[4][0]=Q[0][4]=1;
	
	Q[0][5]=Q[5][0]=1;
	Q[1][6]=Q[6][1]=1;
	Q[2][7]=Q[7][2]=1;
	Q[3][8]=Q[8][3]=1;
	Q[4][9]=Q[9][4]=1;
	
	Q[5][7]=Q[7][5]=1;
	Q[5][8]=Q[8][5]=1;
	Q[6][8]=Q[8][6]=1;
	Q[6][9]=Q[9][6]=1;
	Q[7][9]=Q[9][7]=1;
	
	while(T--)
	{
		char S[100000+5];
		sfs(S);
		len=strlen(S);
		
		rep(i, len)
		{
			a[i].pb(S[i]-'A');
			a[i].pb(S[i]-'A'+5);
		}
		
		done=0;
		
		dfs(0, -1);
		
		if(!done)
		pfi(-1);
		
		rep(j, 100000+5)
		a[j].clear();
	}
	return (0);
}