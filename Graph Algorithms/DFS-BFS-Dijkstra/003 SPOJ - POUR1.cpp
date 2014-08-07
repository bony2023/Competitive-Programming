// Author : Bony Roopchandani
// POUR1
// BFS

// INCLUDES
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<list>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

// MACROS
#define pb push_back
#define sz size()
#define mp make_pair
#define ff first
#define ss second
#define bg begin()
#define en end()
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i=0; i<n; i++)
#define rept(i, a, b) for(int i=a; i<=b; i++)
#define repd(i, a, b) for(int i=a; i>=b; i--)
#define ll long long
#define repl(i, n) for(ll i=0; i<n; i++)
#define replt(i, a, b) for(ll i=a; i<=b; i++)
#define repld(i, a, b) for(ll i=a; i>=b; i--)
#define pfi(a) printf("%d\n",a)
#define sfi(a) scanf("%d",&a)
#define pfl(a) printf("%lld\n",(ll)a)
#define sfl(a) scanf("%lld",&a)
#define sfs(a) scanf("%s",a)
#define pfs(a) printf("%s\n",a)
#define pf(a) printf("%d ",a)
#define nl printf("\n")
#define INF 9999999
#define MOD (1e9 + 7)

// TYPEDEFS
typedef vector < int >VI;
typedef vector < ll > VLL;
typedef vector < string > VS;
typedef pair < int, int >PII;
typedef pair < int, PII > PIII;
typedef pair < int, PIII > PIIII;
typedef pair < int, ll > PIL;
typedef pair < ll, int >PLI;
typedef map < int, int >MII;
typedef map < ll, int >MLI;
typedef map < int, ll > MIL;
typedef map < int, bool > MIB;
typedef list < int >LI;
typedef list < ll > LLL;
typedef set < int >SI;
typedef set < ll > SLL;

int a, b, c;

int BFS()
{
	queue < PIII > Q;
	Q.push(mp(0, mp(0, 0)));
	bool BFull[40005]={0}; 
	bool BEmpty[40005]={0}; 
	bool AFull[40005]={0}; 
	bool AEmpty[40005]={0};

	while (!Q.empty())
	{
		PIII z = Q.front();
		if (z.ss.ff == c || z.ss.ss == c)
			return z.ff;
		Q.pop();

		int A = z.ss.ff;
		int B = z.ss.ss;
		int S = z.ff;

		// filling a;
		if (!BFull[B])
		{
			BFull[B] = 1;
			if (B == 0)
				AEmpty[a] = 1;
			Q.push(mp(S+1, mp(a, B)));
		}
		// filling b;
		if (!AFull[A])
		{
			AFull[A]= 1;
			if (A == 0)
				BEmpty[b] = 1;
			Q.push(mp(S+1, mp(A, b)));
		}
		// emptying a
		if (!BEmpty[B])
		{
			BEmpty[B] = 1;
			if (B == b)
				AFull[0] = 1;
			Q.push(mp(S+1, mp(0, B)));
		}
		// emptying b
		if (!AEmpty[A])
		{
			AEmpty[A] = 1;
			if (A == a)
				BFull[0] = 1;
			Q.push(mp(S+1, mp(A, 0)));
		}
		// pouring from a to b
		if (B != b && A != 0)
		{
			if (A < (b - B))
			{
				if (!BEmpty[A + B])
				{
					BEmpty[A + B] = 1;
					Q.push(mp(S+1, mp(0, A+B)));
				}
			}
			else if (A == (b - B))
			{
				if (!BEmpty[b])
				{
					BEmpty[b] = AFull[0] = 1;
					Q.push(mp(S+1, mp(0, b)));
				}
			}
			else
			{
				int x = A + B - b;
				if (!AFull[x])
				{
					AFull[x] = 1;
					Q.push(mp(S+1, mp(x, b)));
				}
			}
		}
		// pouring from b to a
		if (A != a && B != 0)
		{
			if (B < (a - A))
			{
				if (!AEmpty[A + B])
				{
					AEmpty[A + B] = 1;
					Q.push(mp(S+1, mp(A + B,  0)));
				}
			}
			else if (B == (a - A))
			{
				if (!AEmpty[b])
				{
					AEmpty[b] = BFull[0] = 1;
					Q.push(mp(S+1, mp(a, 0)));
				}
			}
			else
			{
				int x = A + B - a;
				if (!BFull[x])
				{
					BFull[x] = 1;
					Q.push(mp(S+1, mp(a, x)));
				}
			}
		}
	}
	return INF;
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main(void)
{
	int T;
	sfi(T);

	while (T--)
	{
		sfi(a), sfi(b), sfi(c);

		if (a < c && b < c)
			pfi(-1);
		else if (c == 0)
			pfi(0);
		else if (a == c || b == c)
			pfi(1);
		else if (c % gcd(a, b))
			pfi(-1);
		else
		{
			int P = BFS();
			if (P >= INF)
				pfi(-1);
			else
				pfi(P);
		}
	}

	return 0;
}