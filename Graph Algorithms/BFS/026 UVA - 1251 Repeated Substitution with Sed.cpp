// Author : Bony Roopchandani
// 1251 - Repeated Substitution with Sed
// BFS

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
typedef vector < int >VI;
typedef vector < ll > VL;
typedef pair < int, int >PII;
typedef pair < int, ll > PIL;
typedef pair < ll, int >PLI;
typedef pair < int, PII > PIII;
typedef map < int, int >MII;
typedef map < ll, int >MLI;
typedef map < int, ll > MIL;
typedef list < int >LI;
typedef list < ll > LL;

void replaceAll(string &str, const string &from, const string &to)
{
	if (from.empty())
		return;
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != string::npos)
	{
		str.replace(start_pos, from.length(), to);
		start_pos += to.length();	// In case 'to' contains 'from', like replacing 'x' with 'yx'
		}
}

int T;
string from[20], to[20];
string init, target;

int BFS()
{
	map<string, bool>vis;
	map<string, int>dist;
	queue<string>Q;
	
	vis[init]=1;
	dist[init]=0;
	Q.push(init);
	
	while(!Q.empty())
	{
		string z=Q.front();
		Q.pop();
		if(z.sz > target.sz)
		continue;
		
		rep(i, T)
		{
			string a=z;
			replaceAll(a, from[i], to[i]);
			
			if(!vis[a])
			{
				vis[a]=1;
				dist[a]=dist[z]+1;
				if(a==target)
				return dist[a];
				Q.push(a);
			}
		}
	}
	return -1;
}

int main(void)
{
//	freopen("input.txt","r",stdin);
	while(sfi(T) && T)
	{
		rep(i, T)
		{
			cin>>from[i]>>to[i];
		}
		
		cin>>init;
		cin>>target;
		
		pfi(BFS());
	}
	
	return 0;
}