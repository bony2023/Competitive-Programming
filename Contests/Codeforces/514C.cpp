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


struct Trie {
	Trie* next[3];
	bool end;
	Trie() {
		rep(i, 3)
			next[i]=NULL;
		end=false;
	}
};

bool found, foundString;

void insert(const string& S, Trie* tail) {
	rep(i, S.length())
	{
		int p=S[i]-'a';
		if(tail->next[p]==NULL)
			tail->next[p]=new Trie();
		tail=tail->next[p];
	}
	tail->end=true;
}

void search(const string& S, Trie *tail, int pos, int count) {
	if(foundString)
		return;
	if(count>1) {
		return;
	}
	if(count==1 and pos==S.length()) {
		foundString=true;
		return;
	}
	int p=S[pos]-'a';
	rep(i, 3) {
		if(tail->next[i]) {
			if(i != p) {
				search(S, tail->next[i], pos+1, count+1);
			}
			else {
				search(S, tail->next[i], pos+1, count);
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	Trie *head, *tail;
	head=new Trie();
	int n, m;
	cin>>n>>m;
	string S;
	rep(i, n) {
		cin>>S;
		insert(S, tail=head);
	}
	while(m--) {
		cin>>S;
		found=true;
		foundString=false;
		search(S, tail=head, 0, 0);
		if(foundString) 
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return (0);
}