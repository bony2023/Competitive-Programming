// Author : Bony Roopchandani
// CHEFSQUA
// Geometry

// INCLUDES
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
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

static struct IO
{
	char tmp[1 << 10];

	// fast input routines
	char cur;

	// #define nextChar() (cur = getc_unlocked(stdin))
	// #define peekChar() (cur)
	inline char nextChar()
	{
		return cur = getc_unlocked(stdin);
	}
	inline char peekChar()
	{
		return cur;
	}

	inline operator  bool()
	{
		return peekChar();
	}
	inline static bool isBlank(char c)
	{
		return (c < '-' && c);
	}
	inline bool skipBlanks()
	{
		while (isBlank(nextChar()));
		return peekChar() != 0;
	}

	inline IO & operator >>(char &c)
	{
		c = nextChar();
		return *this;
	}

	inline IO & operator >>(char *buf)
	{
		if (skipBlanks())
		{
			if (peekChar())
			{
				*(buf++) = peekChar();
				while (!isBlank(nextChar()))
					*(buf++) = peekChar();
			}
			*(buf++) = 0;
		}
		return *this;
	}

	inline IO & operator >>(string & s)
	{
		if (skipBlanks())
		{
			s.clear();
			s += peekChar();
			while (!isBlank(nextChar()))
				s += peekChar();
		}
		return *this;
	}

	inline IO & operator >>(double &d)
	{
		if ((*this) >> tmp)
			sscanf(tmp, "%lf", &d);
		return *this;
	}

#define defineInFor(intType) \
	inline IO& operator >>(intType & n) { \
		if (skipBlanks()) { \
			int sign = +1; \
			if (peekChar() == '-') { \
				sign = -1; \
				n = nextChar() - '0'; \
			} else \
				n = peekChar() - '0'; \
			while (!isBlank(nextChar())) { \
				n += n + (n << 3) + peekChar() - 48; \
			} \
			n *= sign; \
		} \
		return *this; \
	}

	defineInFor(int)defineInFor(unsigned int) defineInFor(long long)
		// fast output routines
		// #define putChar(c) putc_unlocked((c), stdout)
	inline void putChar(char c)
	{
		putc_unlocked(c, stdout);
	}
	inline IO & operator <<(char c)
	{
		putChar(c);
		return *this;
	}
	inline IO & operator <<(const char *s)
	{
		while (*s)
			putChar(*s++);
		return *this;
	}

	inline IO & operator <<(const string & s)
	{
		for (int i = 0; i < (int)s.size(); ++i)
			putChar(s[i]);
		return *this;
	}

	char *toString(double d)
	{
		sprintf(tmp, "%lf%c", d, '\0');
		return tmp;
	}
	inline IO & operator <<(double d)
	{
		return (*this) << toString(d);
	}


#define defineOutFor(intType) \
	inline char * toString(intType n) { \
		char * p = (tmp + 30); \
		if (n) { \
			bool isNeg = 0; \
			if (n < 0) isNeg = 1, n = -n; \
			while (n) \
				*--p = (n % 10) + '0', n /= 10; \
			if (isNeg) *--p = '-'; \
		} else *--p = '0'; \
		return p; \
	} \
	inline IO& operator << (intType n) { return (*this) << toString(n); }

	defineOutFor(int)defineOutFor(long long)
#define endl ('\n')
#define cout __io__
#define cin __io__
} __io__;

double get(int x1, int y1, int x2, int y2)
{
	return hypot((y2-y1), (x2-x1));
}

int main(void)
{
	int N; cin>>N;
	int A[2][N+5];
	map<PII, bool> M;
	
	rep(i, N)
	{
		cin>>A[0][i]>>A[1][i];
		M[mp(A[0][i], A[1][i])]=1;
	}
	
	if(N==0)
	{
		puts("4");
		return 0;
	}
	else
	if(N==1)
	{
		puts("3");
		return 0;
	}
	else if(N==2)
	{
		puts("2");
		return 0;
	}
	
	double dist;
	const double root2=sqrt(2);
	int X1, Y1, X2, Y2;
	int tempX1, tempY1, tempX2, tempY2;
	int res=2, cnt, side, diag;
	
	rep(i, N)
	{
		rept(j, i+1, N-1)
		{
			X1=A[0][i];
			Y1=A[1][i];
			X2=A[0][j];
			Y2=A[1][j];
			dist=get(X1, Y1, X2, Y2);
			cnt=0;
			
			if(X1==X2 || Y1==Y2)
			{
				side=dist;
				if(X1==X2)
				{
					tempX1=X1+side;
					tempX2=X2+side;
					if(M.count(mp(tempX1, Y1)))
					cnt++;
					
					if(M.count(mp(tempX2, Y2)))
					cnt++;
					
					if(cnt==2)
					{
						puts("0");
						return 0;
					}
					else
					if(cnt==1)
					res=1;
					
					cnt=0;
					
					tempX1=X1-side;
					tempX2=X2-side;
					
					if(M.count(mp(tempX1, Y1)))
					cnt++;
					
					if(M.count(mp(tempX2, Y2)))
					cnt++;
					
					if(cnt==2)
					{
						puts("0");
						return 0;
					}
					else
					if(cnt==1)
					res=1;
				}
				else
				{
					tempY1=Y1+side;
					tempY2=Y2+side;
					
					if(M.count(mp(X1, tempY1)))
					cnt++;
					
					if(M.count(mp(X2, tempY2)))
					cnt++;
					
					if(cnt==2)
					{
						puts("0");
						return 0;
					}
					else
					if(cnt==1)
					res=1;
					
					cnt=0;
					
					tempY1=Y1-side;
					tempY2=Y2-side;
					
					if(M.count(mp(X1, tempY1)))
					cnt++;
					
					if(M.count(mp(X2, tempY2)))
					cnt++;
					
					if(cnt==2)
					{
						puts("0");
						return 0;
					}
					else
					if(cnt==1)
					res=1;
				}
			}
			else
			{
				diag=dist*root2;
				
				if((X1>X2 && Y2>Y1) || (X2>X1 && Y1>Y2))
				{
					if(X1>X2)
					{
						tempX1=X1-diag;
						tempY2=Y2-diag;
						
						if(M.count(mp(tempX1, Y1)))
						cnt++;
						
						if(M.count(mp(X2, tempY2)))
						cnt++;
						
						if(cnt==2)
						{
							puts("0");
							return 0;
						}
						else 
						if(cnt==1)
						res=1;
						
						cnt=0;
						
						tempY1=Y1+diag;
						tempX2=X2+diag;
						
						if(M.count(mp(X1, tempY1)))
						cnt++;
						
						if(M.count(mp(tempX2, Y2)))
						cnt++;
						
						if(cnt==2)
						{
							puts("0");
							return 0;
						}
						else
						if(cnt==1)
						res=1;
					}
					else
					{
						tempX2=X2-diag;
						tempY1=Y1-diag;
						
						if(M.count(mp(X1, tempY1)))
						cnt++;
						
						if(M.count(mp(tempX2, Y2)))
						cnt++;
						
						if(cnt==2)
						{
							puts("0");
							return 0;
						}
						else
						if(cnt==1)
						res=1;
						
						cnt=0;
						
						tempX1=X1+diag;
						tempY2=Y2+diag;
						
						if(M.count(mp(tempX1, Y1)))
						cnt++;
						
						if(M.count(mp(X2, tempY2)))
						cnt++;
						
						if(cnt==2)
						{
							puts("0");
							return 0;
						}
						else 
						if(cnt==1)
						res=1;
					}
				}
				else
				if((X1>X2 && Y1>Y2) || (X2>X1 && Y2>Y1))
				{
					if(X2>X1)
					{
						tempX1=X1-diag;
						tempY2=Y2+diag;
						
						if(M.count(mp(tempX1, Y1)))
						cnt++;
						
						if(M.count(mp(X2, tempY2)))
						cnt++;
						
						if(cnt==2)
						{
							puts("0");
							return 0;
						}
						else
						if(cnt==1)
						res=1;
						
						cnt=0;
						
						tempY1=Y1-diag;
						tempX2=X2+diag;
						
						if(M.count(mp(X1, tempY1)))
						cnt++;
						
						if(M.count(mp(tempX2, Y2)))
						cnt++;
						
						if(cnt==2)
						{
							puts("0");
							return 0;
						}
						else
						if(cnt==1)
						res=1;
					}
					else
					{
						tempX2=X2-diag;
						tempY1=Y1+diag;
						
						if(M.count(mp(tempX2, Y2)))
						cnt++;
						
						if(M.count(mp(X1, tempY1)))
						cnt++;
						
						if(cnt==2)
						{
							puts("0");
							return 0;
						}
						else
						if(cnt==1)
						res=1;
						
						cnt=0;
						
						tempY2=Y2-diag;
						tempX1=X1+diag;
						
						if(M.count(mp(X2, tempY2)))
						cnt++;
						
						if(M.count(mp(tempX1, Y1)))
						cnt++;
						
						if(cnt==2)
						{
							puts("0");
							return 0;
						}
						else
						if(cnt==1)
						res=1;
					}
				}
			}
		}
	}
	
	pfi(res);
	
	return 0;
}