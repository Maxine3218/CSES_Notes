#include <bits/stdc++.h>
using namespace std;

int main() {
	/* ----------------- Chap.9 Range Queries -----------------*/
	
	// 9.1 Queries on Static Arrays ----------------------------------
	// Preprocess the array
	
	// 9.1.1 Sum Queries	SUMq(a,b)
	/* 	[Construct a prefix sum array SUMq(0,k)]
		SUMq(0,-1) = 0
		SUMq(a, b) = SUMq(0,b)-SUMq(0,a-1)
		=> Higher Dimensions
	*/
	
	// 9.1 2 Minimum Queries			//????
	/*	The Sparse Table Algorithm
		Step1. MINq(a,b) = min(MINq(a,a+w-1),MINq(a+w,b))
				=> 2^(k+1) > b-a+1 >= 2^k, w = (b-a+1)/2
				=> O(nlogn)	-Preprocessing
		Step2. MINq(a,b) = min(MINq(a,a+k-1),MINq(b-k+1,b))
				=> both of length-k, the greatest power of 2 not exceeding b-a+1
				=> e.g. MINq(1,6) = min(MINq(1,4),MINq(3,6))
				=> O(1)		-Minimum Query
	*/
	
	// 9.2 Tree Structures -------------------------------------------
	/* 9.2.1 Binary Indexed Trees
		# Two O(logn)-time operations:
			1.Processing a range sum query
			2.Updating a value
		# tree[k] = SUMq(k-p(k)+1,k), where k is the largest power of 2 that divides k
			e.g. Index	1  2  3  4  5  6  7  8
				 Array	1  3  4  8  6  1  4  2
				 BIT	1  4  4  16 6  7  4  29
				 		|  |  |  |  |  |  |  |
				 		== |  == |  == |  == |
						====     |  ====	 |
						==========			 |	
						======================
		# Application: Sum of entire range
			SUMq(a,b) = SUMq(1,b) - SUMq(1,a-1)
		# Implementation */
		int sum(int k) {				// get value of SUMq(1,k)
			int s = 0;
			while (k>=1) {
				s += tree[k];
				k -= k&-k;				//p(k)=k&-k; flip the least significant one bit of k
			}
		}			 
		void add(int k, int x) {
			while (k <= n) {
				tree[k] += x;
				k += k& -k;
			}
		}
		
	// 9.2.2 Segment Trees
		/* Two O(logn) operations:
			1. Processing a range query
			2. Updating a value
		*/
		/* 	Original array size: n
		 	Segment Tree: 2n
		 	stored top to bottom, [0]not used, [1]top node
		 	For tree[k], parent is tree[k/2], 
			 			 left child is tree[2k], 
						 right child tree[2k+1] */
		// Implementation
		int sum(int a, int b) {
			a += n; b+= n;
			int s = 0;
			while (a <= b) {
				if (a%2 == 1) s += tree[a++];
				if (b%2 == 0) s += tree[b--];
				a /= 2;
				b /= 2;
			}
			return s;
		}
		void add(int k, int x) {		//node k + value x
			k += n;
			tree[k] += x;
			for (k /= 2; k >= 1; k /= 2) {
				tree[k] = tree[2*k] + tree[2*k+1];		//bubble up updates
			}
		}
		
		// Other queries: Divide into 2 parts, conquer separately, conbine
		// Min, Max, Greatest Common Divisor (gcd), Bit ops (and,or xor)
	// 9.2.3 Additional Techniques
	/* Index Compression	
		Large indices needed in consecutive indices => replace original indices with 0,1,2..
		c(i): if a < b, then c(a) < c(b)
		e.g. Index	0 1 2 3 4 5 6 7
			 Array	0 0 5 0 0 3 0 4
			 c(2) = 0;
			 c(5) = 1;
			 c(7) = 2
			 C_Arr	5 3 4
	*/
	/* Range Updates
		Increase ALL elements in range[a,b] by x
		=> Difference Array
		e.g. Index	0 1 2 3 4 5 6 7
			 Array	3 6 4 4 4 5 2 2
			 D_Arr	3 3-2 0 0 1-3 0
		=> Range update with only 2 elements
		[a,b]+x => D_Arr[a]+=3, D_Arr[b+1]-=3;
	*/	
}
