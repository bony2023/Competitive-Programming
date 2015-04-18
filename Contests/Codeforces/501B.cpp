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

map<string, bool> Start;
map<string, string> G;
int n;

string dfs(string u) {
	for(string t=u;;) {
		if(G.count(t)==0)
			return t;
		t=G[t];
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin>>n;
	int cnt=0;
	vector<string> old;
	vector<pair<string, string> > res;
	string x, y;
	rep(i, n) {
		cin>>x>>y;
		G[x]=y;
		Start[y]=true;
		old.pb(x);
	}
	for(auto it : old) {
		if(Start[it]==0) {
			cnt+=1;
			res.pb(mp(it, dfs(it)));
		}
	}
	cout<<cnt<<endl;
	for(auto it : res) {
		cout<<it.ff<<" "<<it.ss<<endl;
	}
	return (0);
}