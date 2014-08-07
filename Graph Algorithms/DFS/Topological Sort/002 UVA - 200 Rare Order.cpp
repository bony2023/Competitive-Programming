// Author : Bony Roopchandani
// 200 - Rare Order
// Topological Sort

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<list>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
#define pb push_back
#define sz size()
#define mp make_pair
#define ff first
#define ss second
#define bg begin()
#define en end()
#define rep(i, n) for(int i=0; i<n; i++)
#define repi(i, n) for(int i=0; i<=n; i++)
#define rept(i, a, b) for(int i=a; i<=b; i++)
#define repd(i, a, b) for(int i=a; i>=b; i--)
#define ll long long
#define repl(i, n) for(ll i=0; i<n; i++)
#define repli(i, n) for(ll i=0; i<=n; i++)
#define pfi(a) printf("%d\n",a)
#define sfi(a) scanf("%d",&a)
#define pfl(a) printf("%lld\n",(ll)a)
#define sfl(a) scanf("%lld",&a)
#define sfs(a) scanf("%s",a)
#define pfs(a) printf("%s\n",a)
#define pf(a) printf("%d ",a)
#define nl printf("\n")
#define INF 9999999
#define MOD 1000000007
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PII;
typedef pair<int, ll> PIL;
typedef pair<ll, int> PLI;
typedef pair<int, PII>PIII;
typedef pair<int, PIII> PIIII;
typedef map<int, int> MII;
typedef map<ll, int> MLI;
typedef map<int, ll> MIL;
typedef list<int> LI;
typedef list<ll> LL;

int main(void)
{
	char foo[10000][30];
	int i=0, maxLen=0;
	
	while(1)
	{
		sfs(foo[i]);
		if(foo[i][0]=='#')
		break;
		
		if(maxLen<strlen(foo[i]))
		maxLen=strlen(foo[i]);
		
		i++;
	}
	
	bool vis[100]={0};
	
	rep(x, maxLen)
	{
		rep(y, i)
		{
			if(!vis[foo[y][x]-'A'] && foo[y][x]>='A' && foo[y][x]<='Z')
			vis[foo[y][x]-'A']=1, cout<<foo[y][x];
		}
	}
	nl;
	return 0;
}