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
	string s; cin>>s;
	int tot=0, l=0, r=0;
	int z=s.sz;
	rep(i, z) {
		if(s[i]=='#') tot+=1;
	}
	VI x;
	rep(i, z) {
		if(s[i]=='(') l+=1;
		else if(s[i]==')') r+=1;
		else
		{
			if(tot==1) {
				rept(j, i+1, z-1) if(s[j]=='(') l+=1;
				else r+=1;
				if(l>r)
				x.pb(l-r), r+=(l-r);
				else {
					pfi(-1);
					return 0;
				}
				break;
			}
			
			if((r+1)>l) {
				pfi(-1);
				return 0;
			}
			else x.pb(1), r+=1;
			
			tot-=1;
		}
	}
	int k=0;
	int templ=0, tempr=0;
	rep(i, z) {
		if(s[i]=='#') {
			if((tempr+x[k])>templ) {
				pfi(-1);
				return 0;
			}
			tempr+=x[k];
			k++;
		}
		
		else if(s[i]=='(') templ+=1;
		else tempr+=1;
		
		if(tempr>templ) {
			pfi(-1); return 0;
		}
	}
	if(l!=r) pfi(-1);
	else
	{
		rep(i, x.sz) pfi(x[i]);
	}
	return (0);
}