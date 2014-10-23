// Author : Bony Roopchandani
// BISHOPS
// BigInteger + Ad-Hoc

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

#include <sstream>
#define MAX 10000

class BigInt
{
	string Number;
	bool sign; // True if Negative Number
	
	public:
	
	// Constructors
	BigInt();
	BigInt(string&);
	BigInt(BigInt&);
	BigInt(long long);
	
	// Operator Overloading
	// I/O
	friend istream& operator >>(istream&, BigInt&);
	friend ostream& operator <<(ostream&, BigInt&);
	
	// Comparision
	bool operator ==(const BigInt&);
	bool operator ==(const string&);
	bool operator != (const BigInt&);
	bool operator != (const string&);
	bool operator <(const BigInt&);
	bool operator >(const BigInt&);
	bool operator <=(const BigInt&);
	bool operator >=(const BigInt&);
	void operator =(int);
	void operator =(long long);
	
	// Arithmetic
	// Binary
	BigInt operator +(const BigInt&);
	BigInt operator -(const BigInt&);
	BigInt operator *(const BigInt&);
	BigInt operator /(const BigInt &);
	BigInt operator %(const BigInt&);
	// Unary
	BigInt operator ++(int);
	BigInt operator --(int);
	BigInt& operator ++();
	BigInt& operator --();
	BigInt operator -();
	void operator +=(const BigInt&);
	void operator -=(const BigInt&);
	void operator *=(const BigInt&);
	void operator /=(const BigInt&);
	void operator %=(const BigInt&);
	
	// Other Useful Functions
	friend BigInt gcd(BigInt, BigInt);
	friend BigInt pow(BigInt, int);
	friend BigInt factorial(long long);
	friend BigInt abs(BigInt);
	friend BigInt min(BigInt, BigInt);
	friend BigInt max(BigInt, BigInt);
	friend void swap(BigInt&, BigInt&);
};

BigInt::BigInt() // Default Constructor
{
	Number="0";
	sign=false;
}

BigInt::BigInt(BigInt& x) // Copy Constructor
{
	Number=x.Number;
	sign=x.sign;
}

BigInt::BigInt(long long x) // long long to BigInt
{
	(*this).sign=false;
	
	if(x<0)
	{
		x*=-1;
		(*this).sign=true;
	}
	
	stringstream S;
	S<<x;
	S>>(*this).Number;
}

istream& operator >>(istream& P, BigInt& x) // Input BigInt
{
	P>>x.Number;
	x.sign=false;
	
	if(x.Number[0]=='-')
	{
		x.sign=true;
		x.Number.erase(0, 1);
	}
	
	return P;
}

ostream& operator <<(ostream& P, BigInt& x) // Output BigInt
{
	if(x.sign) P<<"-";
	P<<x.Number;
	
	return P;
}

bool BigInt::operator ==(const BigInt& x) // IsEqualToBigInt
{
	if((*this).Number==x.Number && (*this).sign==x.sign)
	return true;
	
	return false;
}

bool BigInt::operator ==(const string& x) // isEqualToString
{
	string t=x;
	
	if(x[0]=='-')
	{
		t.erase(0, 1);
		
		if(!((*this).sign))
		return false;
	}
	else if((*this).sign)
	return false;
	else
	return ((*this).Number==t);
}

bool BigInt::operator !=(const BigInt& x) // notEqualBigInt
{
	return !((*this)==x);
}

bool BigInt::operator !=(const string& x) // notEqualString
{
	return !((*this)==x);
}

bool BigInt::operator <(const BigInt& x) // lessThan
{
	if((*this).sign && !x.sign)
	return true;
	else if((*this).sign==x.sign)
	{
		if(x.Number.size() != (*this).Number.size())
		{
			if(x.sign)
			return (*this).Number.size()>x.Number.size();
			else
			return (*this).Number.size()<x.Number.size();
		}
		else
		if(!x.sign)
		return (*this).Number<x.Number;
		else
		return x.Number<(*this).Number;
	}
	else
	return false;
}

bool BigInt::operator >(const BigInt& x) // greaterThan
{
	if(!((*this).sign) && x.sign)
	return true;
	else if((*this).sign==x.sign)
	{
		if(x.Number.size() != (*this).Number.size())
		{
			if(x.sign)
			return (*this).Number.size()<x.Number.size();
			else
			return (*this).Number.size()>x.Number.size();
		}
		else
		if(x.sign)
		return (*this).Number<x.Number;
		else
		return (*this).Number>x.Number;
	}
	else 
	return false;
}

bool BigInt::operator <=(const BigInt& x) // lessOrEqual
{
	if((*this).sign && !x.sign)
	return true;
	else if((*this).sign==x.sign)
	{
		if(x.Number.size() != (*this).Number.size())
		{
			if(x.sign)
			return (*this).Number.size()>x.Number.size();
			else
			return (*this).Number.size()<x.Number.size();
		}
		else
		if(!x.sign)
		return (*this).Number<=x.Number;
		else
		return x.Number<=(*this).Number;
	}
	else
	return false;
}

bool BigInt::operator >=(const BigInt& x) // greaterOrEqual
{
	if(!((*this).sign) && x.sign)
	return true;
	else if((*this).sign==x.sign)
	{
		if(x.Number.size() != (*this).Number.size())
		{
			if(x.sign)
			return (*this).Number.size()<x.Number.size();
			else
			return (*this).Number.size()>x.Number.size();
		}
		else
		if(x.sign)
		return (*this).Number<=x.Number;
		else
		return (*this).Number>=x.Number;
	}
	else 
	return false;
}

BigInt BigInt::operator +(const BigInt& x) //Addition
{
	BigInt ret;
	BigInt A, B;
	A=(*this);
	B=x;
	char *a, *b;
	char C[MAX]={0};
	int carry=0;
	
	if((*this).sign==x.sign)
	{
		if(x.sign)
		{
			ret.sign=true;
		}
		else
		{
			ret.sign=false;
		}

        a=(char*)A.Number.c_str();
        b=(char*)B.Number.c_str();
        reverse(a, a+strlen(a));
        reverse(b, b+strlen(b));
        
    	const int f_len=strlen(a);
    	const int s_len=strlen(b);
    	const int vysledek_len=strlen(C);
    	const int null=0;
	
    	int max_len;
    	if(s_len<(f_len + null))
    	max_len=f_len + null;
    	else
    	max_len=s_len;
	
    	int s_idx = 0, f_idx = 0;
    	int last = 0, idx_null = null;
    	int nula = -1, n;
	
    	while (f_idx < max_len)
    	{
    		n = ((s_len > s_idx) ?     (b[s_idx] - '0') : 0) + ((idx_null > 0) ?     0 : ((f_len > f_idx) ? (a[f_idx] - '0') :     0)) + last;
		
    		if (n > 9)
    		{
    			last = 1;
    			n -= 10;
    		}
    		else
    			last = 0;
			
    		C[s_idx] = n + '0';
		
    		if (!n && s_idx > 0)
    		{
    			if (nula == -1)
    				nula = s_idx;
    		}
    		else
    			nula = -1;
    		++s_idx;
    		if (idx_null-- <= 0)
    			++f_idx;
    	}
    	if (last)
    	{
    		C[s_idx++] = '1';
    		nula = -1;
    	}
    	if (nula > 0)
    		s_idx = nula;
    	C[s_idx] = '\0';
    	
    	reverse(C, C+strlen(C));
		ret.Number=string(C);
		reverse(a, a+strlen(a));
        reverse(b, b+strlen(b));
	}
	
	else if((*this).Number==x.Number)
	{
		ret.sign=false;
		ret.Number="0";
	}
	else
	{
		if(A.sign)
		{
			A.sign=false;
			
			if(A>B)
			{
				ret.sign=true;
				a=(char*)A.Number.c_str();
                b=(char*)B.Number.c_str();
            	reverse(a, a+strlen(a));
            	reverse(b, b+strlen(b));
			}
			else
			{
				ret.sign=false;
         	   a=(char*)B.Number.c_str();
            	b=(char*)A.Number.c_str();
            	reverse(a, a+strlen(a));
                reverse(b, b+strlen(b));
			}
			
			A.sign=true;
		}
		else if(B.sign)
		{
			B.sign=false;
			
			if(B>A)
			{
				ret.sign=true;
	    
	            a=(char*)B.Number.c_str();
	            b=(char*)A.Number.c_str();
                reverse(a, a+strlen(a));
                reverse(b, b+strlen(b));
			}
			else
			{
				ret.sign=false;
         	   a=(char*)A.Number.c_str();
            	b=(char*)B.Number.c_str();
            	reverse(a, a+strlen(a));
                reverse(b, b+strlen(b));
			}
		}
		
		int max_len;
    	int f_len=strlen(a);
    	int s_len=strlen(b);
	
    	if(s_len < f_len)
    	max_len=f_len;
    	else
    	max_len=s_len;
	
    	int idx = -1, last = 0, null_idx = -1;
    	int n;
	
    	while (++idx < max_len)
    	{
    		n = (a[idx] - '0') - ((s_len > idx) ? (b[idx] - '0') : 0) - last;
		
    		if (n < 0)
    		{
    			last = 1;
    			n += 10;
    		}
		
    		else
    			last = 0;
			
    		C[idx] = n + '0';
		
    		if (!n && idx > 0)
    		{
    			if (null_idx == -1)
    				null_idx = idx;
    		}
    		else
    			null_idx = -1;
    	}
    	if (null_idx > 0)
    		idx = null_idx;
		
    	C[idx] = '\0';
    	
    	reverse(C, C+strlen(C));
    	ret.Number=string(C);
		
		reverse(a, a+strlen(a));
        reverse(b, b+strlen(b));
	}
	
	return ret;
}

BigInt BigInt::operator -(const BigInt& x) // Subtraction
{
	BigInt a, b, c;
	a=(*this);
	b=x;
	b.sign=1-b.sign;
	c=a+b;
	
	return c;
}

int main(void)
{
	BigInt N, res;
	
	while(cin>>N)
	{
		if(N>=2)
		res=(N+N-2), cout<<res<<endl;
		else
		cout<<N<<endl;
	}
	return (0);
}