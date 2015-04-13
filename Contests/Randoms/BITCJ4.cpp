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

string res;
int mx=0;
bool vis[30]={0};
char tmp[30];
VI a[30];

void dfs(int u, int k) {
	vis[u]=1;
	tmp[k]=u+'a';
	rep(i, a[u].sz) {
		int v=a[u][i];
		if(!vis[v])
			dfs(v, k+1);
		vis[v]=0;
	}
	if(mx<k) {
		tmp[k+1]='\0';
		res=string(tmp);
		mx=k;
	}
	else if(mx==k) {
		tmp[k+1]='\0';
		if(res>string(tmp))
			res=string(tmp);
	}
}

int main(void) {
	int T; sfi(T);
	while(T--) {
		string S; cin>>S;
		int f[30]={0};
		rep(i, S.sz) {
			f[S[i]-'a']+=1;
		}
		rep(i, 26) 
			rept(j, i+1, 25) 
				if(f[i]<=f[j] and f[i] and f[j]) {
					a[i].pb(j);
				}
		int c=0;
		rep(i, 26)
			if(a[i].sz)
				c+=1;
		if(c==0) {
			rep(i, 26) {
				if(f[i]) {
					printf("%c\n", i+'a');
					break;
				}
			}
			continue;
		}
		rep(i, 26) {
			dfs(i, 0);
			memset(vis, 0, sizeof vis);
		}
		cout<<res<<endl;
		res.clear();
		mx=0;
		rep(i, 26)
			a[i].clear();
	}
	return (0);
}