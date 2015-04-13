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

int n, mx=0;
int tmp[5000+5], a[5000+5];
bool vis[5000+5]={0};

void construct(int prev, int k) {
	tmp[k]=prev;
	rept(i, 2, n) {
		if(!vis[i] and abs(i-prev) != 1) {
			vis[i]=true;
			construct(i, k+1);
		}
	}
	if(mx<k) {
		memcpy(a, tmp, sizeof tmp);
		mx=k;
	}
}

void expand() {
	bool cnt[5000+5]={0};
	int f=-1, index=-1;
	rept(i, 1, mx)
		cnt[a[i]]=true;
	rept(i, 1, n)
		if(!cnt[i]) {
			f=i;
			break;
		}
	if(f != -1) {
		rept(i, 2, mx) {
			if(abs(a[i-1]-f) != 1 and abs(a[i]-f) != 1) {
				index=i;
				break;
			}
		}
		if(index==-1 and abs(a[1]-f) != 1) {
			index=1;
		}
	}
	if(index != -1) {
		repd(i, mx, index) {
			a[i+1]=a[i];
		}
		a[index]=f;
		mx+=1;
	}	
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin>>n;
	vis[1]=true;
	construct(1, 1);
	expand();
	cout<<mx<<endl;
	rept(i, 1, mx)
		cout<<a[i]<<" ";
	return (0);
}