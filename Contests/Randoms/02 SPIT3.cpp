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
#define out(a) freopen(a, "w", stdout)
#define pb push_back
#define rep(i, n) for(int i=0; i<n; i++)
#define repd(i, a, b) for(int i=a; i>=b; i--)
#define rept(i, a, b) for(int i=a; i<=b; i++)
#define ss second
#define sz size()

// CONSTS
const double EPS = (1e-11);
const double PI = acos(-1.0);
const int INF = 9999999;
const int MOD = (1e9 + 7);

int main(void) {
	ios_base::sync_with_stdio(false);
	string S;
	cin>>S;
	bool ok=true, small=false, large=false, digit=false;
	if(S.length()<5) {
		ok=false;
	}
	rep(i, S.length()) {
		if(S[i]>='a' and S[i]<='z')
			small=true;
		else if(S[i]>='A' and S[i]<='Z')
			large=true;
		else if(S[i]>='0' and S[i]<='9')
			digit=true;
	}
	ok=(ok && small && large && digit);
	cout<<(ok?"YES":"NO")<<endl;
	return (0);
}