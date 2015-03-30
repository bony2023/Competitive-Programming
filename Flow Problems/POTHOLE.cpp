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

int res[205][205], f, s, t;
VI a[205], parent;

void augment(int u, int currflow) {
	if(u==s) {
		if(currflow != INF)
			f=currflow;
		else 
			f=0;
		return;
	}
	if(parent[u] != -1) {
		augment(parent[u], min(currflow, res[parent[u]][u]));
		res[parent[u]][u]-=f;
		res[u][parent[u]]+=f;
	}
}

int main(void) {
	int T; sfi(T);
	while(T--) {
		int n, m, x; sfi(n);
		memset(res, 0, sizeof res);
		rep(i, n-1) {
			sfi(m);
			rep(j, m) {
				sfi(x);
				x-=1;
				if(i==0 or x==(n-1))
					res[i][x]=1;
				else
					res[i][x]=INF;
				a[i].pb(x);
			}
		}
		int maxflow=0;
		s=0, t=n-1;
		while(true) {
			f=0;
			bool vis[205]={0};
			parent.assign(n+5, -1);
			queue<int> Q;
			Q.push(s);
			vis[s]=true;
			bool done=false;
			while(!Q.empty()) {
				int u=Q.front(); Q.pop();
				rep(v, n) {
					if(!vis[v] and res[u][v]>0) {
						parent[v]=u;
						vis[v]=true;
						if(v==t) {
							done=true;
							break;
						}
						Q.push(v);
					}
					if(done) break;
				}
				if(done)
					break;
			}
			augment(t, INF);
			if(f==0)
				break;
			maxflow+=f;
		}
		pfi(maxflow);
		parent.clear();
		rep(i, n+5)
			a[i].clear();
	}
	return (0);
}