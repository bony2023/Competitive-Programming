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

int k, R, C;
map<PII, int> Path;
map<int, PII> RevPath;
int ShortestPath[50][50];
char foo[30][30];
int dx[]={0, -1, 0, 1};
int dy[]={-1, 0, 1, 0};
int dp[12][4096];

void BFS(int u) {
	queue<PIII> Q;
	Q.push(mp(0, RevPath[u]));
	map<PII, bool> vis;
	vis[RevPath[u]]=true;
	while(!Q.empty()) {
		int d=Q.front().ff;
		int i=Q.front().ss.ff;
		int j=Q.front().ss.ss;
		if(foo[i][j]=='*' or foo[i][j]=='o') {
			ShortestPath[u][Path[mp(i, j)]]=d;
		}
		Q.pop();
		rep(z, 4) {
			int ni=i+dx[z];
			int nj=j+dy[z];
			if(!vis[mp(ni, nj)] and ni<R and nj<C and ni>=0 and nj>=0 and foo[ni][nj] != 'x') {
				vis[mp(ni, nj)]=true;
				Q.push(mp(d+1, mp(ni, nj)));
			}
		}
	}
}

int F(int pos, int mask) {
	if(mask==((1<<k)-1)) {
		return 0;
	}
	if(dp[pos][mask] != -1) {
		return dp[pos][mask];
	}
	int ret=INF;
	rep(i, k) {
		if(!(mask & (1<<i))) {
			ret=min(ret, ShortestPath[pos][i]+F(i, mask | (1<<i)));
		}
	}
	return dp[pos][mask]=ret;
}

int main(void) {
	while(scanf("%d%d", &C, &R) and R and C) {
		k=0;
		rep(i, R) {
			sfs(foo[i]);
			rep(j, C) {
				if(foo[i][j]=='o') {
					Path[mp(i, j)]=k;
					RevPath[k++]=mp(i, j);
				}
			}
		}
		rep(i, R) {
			rep(j, C) {
				if(foo[i][j]=='*') {
					Path[mp(i, j)]=k;
					RevPath[k++]=mp(i, j);
				}
			}
		}
		rep(i, k)
			rep(j, k)
				ShortestPath[i][j]=INF;
		rep(i, k)
			BFS(i);
		memset(dp, -1, sizeof dp);
		int P=F(0, 0);
		if(P>=INF)
			pfi(-1);
		else 
			pfi(P);
		Path.clear();
		RevPath.clear();
	}
	return (0);
}