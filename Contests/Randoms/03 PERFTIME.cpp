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

int parse(int l, int r, string& s) {
	int ret=0;
	rept(i, l, r) {
		ret*=10;
		ret+=(s[i]-'0');
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) {
		string s;
		cin>>s;
		int pos=0;
		while(s[pos]>='0' and s[pos]<='9')
			pos+=1;
		int H=parse(0, pos-1, s);
		int M=parse(pos+1, s.sz-1, s);
		H%=12, M%=60;
		double A=abs(((60*H+M)*0.5)-(6.0*M));
		A=min(A, 360-A);
		cout<<((fmod(A, 5.0))?"NO":"YES")<<endl;
	}
	return (0);
}