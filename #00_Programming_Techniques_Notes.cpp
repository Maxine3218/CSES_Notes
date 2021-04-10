#include <bits/stdc++.h>
using namespace std;
//Chapter 02 Programming Techniques

class T{
	public:
		int x,y,z;
		T(int a, int b, int c): x(a),y(b),z(c){}
};
bool operator<(const tmp1& a) const
{
    return x < a.x; //max heap 
}

bool operator() (tmp1 a, tmp1 b) 
{
    return a.x < b.x; //max heap
}

int main(){
	// Iterative is always faster than recursive ones!
	//---------2.1---------//
	//---------Input and Output---------//
	ios::sync_with_stdio(0);
	cin.tie(0);
	//*output style*//
	printf("%04d/%02d/%02d\n",i,a,date);
	
	int a=123, b=456;
	string x="monkey";
	cout<<a<<" "<<b<<" "<<x<<"\n";
	//"\n" is more efficient than "endl" !!!!
	//"endl" cause a flush operation
	
	scanf("%d %d", &a, &b);	//slightly faster, more difficult to use
	printf("%d %d\n", a, b);
	
	//neglect \n in string ops
	getchar();
	cin.ignore();	//work with IOS
	scanf("%d%*c",&n);	//%*c=>match any character
	
	//read a whole input line with spaces
	string s;
	getline(cin,s);
	
	//amount of input data in unknown
	while (cin >> x) {
		//code
	}
	
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//------------------------------------------------------//
	
	//---------Int---------//
	//int        32bit -2^31 ~ 2^31-1   2*10^9
	//long long  64bit -2^63 ~ 2^63-1   9*10^18   (long long)a*a
	//__int128_t 128bit
	#include <limits.h>
	cout<<INT_MAX<<" "<<LONG_MAX<<" "<<LLONG_MAX<<"\n";
	
	//---------Modular---------//
	//(a + b) mod m = (a mod m + b mod m) mod m
	//(a - b) mod m = (a mod m - b mod m) mod m
	//(a * b) mod m = (a mod m * b mod m) mod m
	// notice that modulo op do not apply to divide op "/"
	x%=m;
	if(x<0) x+=m; //remainder of a negative num is 0/neg
	
	//---------FLoat---------//
	//double 64-bit  //long double 80-bit
	double x=0.3*0.3+0.1;
	printf("%.9f\n",x);
	//do not compare floating numbers with == operator!!!!!!!!!!!!!
	if(abs(a-b)<1e-9){
		//code
	}
	//------------------------------------------------------//
	
	//---------Shortening Code---------//
	typedef long long ll;     //ll(long long)
	#define F first           //F(first)
	#defin REP(i,a,b) for(int i=a;i<=b;i++)
	//-----------------------------------------------------------//
	
	//---------2.2---------//
	//------------------Recursion------------------//
	
	
	/*---------*/Subset/*---------*/
	vector<int> subset;
	//---------------------------
	void search(int k) {
		if (k == n+1) {
			// process subset
		} else {
			// include k in the subset
			subset.push_back(k);
			search(k+1);
			subset.pop_back();
			// don¡¯t include k in the subset
			search(k+1);
		}
	}
	/*---------------------------*/
	Appendix: Subset Coefficient 
	//-------------
	int i,j,n=4;
	for(i=0;i<(1<<n);i++){		//subset 0000..1111
		for(j=n-1;j>=0;j--){	//for every bit from high to low
			if(i&(1<<j)) cout<<"1 ";
			else cout<<"0 "; 
		}
		cout<<"\n";
	}
	/*---------------------------*/
	 
	/*---------*/Permutation/*---------*/
	vector<int> permutation;
	bool chosen[n+1]; //has been included?
	//---------------------------
	void search() {
		if (permutation.size() == n) {
			// process permutation
		} else {
			for (int i = 1; i <= n; i++) {
				if (chosen[i]) continue;
				chosen[i] = true;
				permutation.push_back(i);
				search();
				chosen[i] = false;
				permutation.pop_back();
			}
		}
	}//---------------------------
	//OR: C++ lib function--next_permutation:
	for (int i = 1; i <= n; i++) {
		permutation.push_back(i);
	}
	do {
		// process permutation
	} while (next_permutation(permutation.begin(),
							permutation.end()));
	/*---------------------------*/
	
	
	/*---------*/Backtracking/*---------*/
	// n-queen problem
	void search(int y) {
		if (y == n) {
			count++;
			return;
		}
		for (int x = 0; x < n; x++) {
			if (col[x] || diag1[x+y] || diag2[x-y+n-1]) continue;
			col[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
			search(y+1);
			col[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
		}
	}
	/*---------------------------*/
	
	//------------------------------------------------------------//
	//---------2.3---------//
	//(1 sign) + (n-1 bit)
	//0+ 1-
	//signed:	-2^(n-1) ~ 2^(n-1)-1
	//unsigned:		   0 ~ 2^n-1
	
	/*
	bit operation: 	
	AND &
	OR  |
	XOR ^
	NOR ~     ~x=-x-1
	SHIFT << >>
	BIT Masks  
		e.g.	x&(1<<k) print bit representation
		x|(1<<k)  set kth to 1
		x&~(1<<k) set kth to 0
		x^(1<<k) invert kth
		x&(x-1)	last to 0
		x&-x	all to 0 except last
		x|(x-1) invert all after the last 1
		x&(x-1)==0 => x is a power of 2
	Built-Ins	
		int x = 5328; // 00000000000000000001010011010000
		cout << __builtin_clz(x) << "\n"; 	//begin zeros 19
		cout << __builtin_ctz(x) << "\n"; 	//end zeros 4
		cout << __builtin_popcount(x) << "\n"; 	//ones 5
		cout << __builtin_parity(x) << "\n"; 	// 1
*/
	
	bitset<10> s;  //like a sequence bool
	cout<<s.count()<<"\n"; //num of 1s
	//bit operations works
	
}
