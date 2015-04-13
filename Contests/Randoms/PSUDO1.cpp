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

int main(void) {
	int T; sfi(T);
	cin.ignore();
	while(T--) {
		string S;
		getline(cin, S);
		int x1, y1, x2, y2, res=0;
		rep(i, S.sz) {
			if(S[i]==' ' and S[i-1] != ' ') {
				x1=S[i-5]-'0';
				y1=S[i-4]-'0';
				x2=S[i-2]-'0';
				y2=S[i-1]-'0';
				if(x1==y2 and x2==y1)
					res+=1;
				else if(x1==x2 and y1==y2)
					res+=1;
				else if(x1==y1 and x2==y2)
					res+=1;
			}
			else if(i==(S.sz-1) and S[i] != ' ') {
				x1=S[i-4]-'0';
				y1=S[i-3]-'0';
				x2=S[i-1]-'0';
				y2=S[i]-'0';
				if(x1==y2 and x2==y1)
					res+=1;
				else if(x1==x2 and y1==y2)
					res+=1;
				else if(x1==y1 and x2==y2)
					res+=1;
			}
		}
		pfi(res);
	}
	return (0);
}