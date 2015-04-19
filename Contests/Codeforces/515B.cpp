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
	int B, G, nB, nG, index;
	bool HB[105]={0}, HG[105]={0};
	vector<int> hb, hg;
	cin>>B>>G;
	cin>>nB;
	rep(i, nB) {
		cin>>index;
		HB[index]=true;
		hb.pb(index);
	}
	cin>>nG;
	rep(i, nG) {
		cin>>index;
		HG[index]=true;
		hg.pb(index);
	}
	int currB=hb.size(), currG=hg.size();
	for(int i=0; ;i++) {
		int indB=i%B;
		int indG=i%G;
		if(HB[indB] and !HG[indG]) {
			HG[indG]=true;
			hg.pb(indG);
		}
		else if(!HB[indB] and HG[indG]) {
			HB[indB]=true;
			hb.pb(indB);
		}
		if(i%100==0 and i != 0) {
			if(hb.size()==currB and hg.size()==currG) {
				break;
			}
			else {
				currB=hb.size();
				currG=hg.size();
			}
		}
	}
	cout<<((hb.size()==B and hg.size()==G)?"Yes":"No");
	return (0);
}