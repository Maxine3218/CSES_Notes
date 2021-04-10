#include <bits/stdc++.h>
using namespace std;

int main() {
	// ----------------- Chap.8 Algorithm Design Topics -----------------//
	
	// 8.1 Bit-parrallel algorithms -------------------------------------
	// Manipulate individual bits of numbers in parallel using bit ops
	
	/* 8.1.1 Hamming Distances */
	// Straightforward Implementaion: 
	int hamming(string a, string b) {
		int d = 0, k = a.length();
		for (int i = 0; i < k; i++) {
			if(a[i] != b[i]) d++;
		}
		return d;
	}
	// OR: Bit Operations					//about 20 times faster
	int hamming(int a, int b) {
		return __builtin_popcount(a^b);		//count 1s in a^b
	}
	
	/* 8.1.2 Counting Subgrids */
	// Count num of subgrids in n*n grid with all four black corners
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (color[a][i] == 1 && color[b][i] == 1){
			count++;						//count columns with 2+ black
		}									//(a,i) (b,i)
	}
	int ans = count*(count-1)/2;
	// Bit Op
	// Represent each row k as an n-bit bitset row[k]
	int count = (row[a]&row[b]).count();
	
	/* Reachability in Graphs */
	// Graph Representation: adjacency lists adj[x]
	// Step 1. DP: for each node, construct reachable nodes
	// Step 2. Bit Op:
	reach[x][x] = 1;						//an array of bitset structures
	for (auto u : adj[x]) {
		reach[x] |= reach[u];
	}
	
	// 8.2 Amortized Analysis -------------------------------------
	
	// 8.2.1 Two Pointers Method
	// both move to one direction only
	// 2-SUM Problem	(Time Complexity: O(nlogn), sort-O(nlogn)+2-pointer-O(n) )
	// 3-SUM Problem
	
	// 8.2.2 Nearest Smaller Elements
	// i.e. the first smaller element preceding x
	// Data Structure: Stack	(Time Complexity: O(n))
	// Remove elements from stack until top_ele < current_ele
	e.g. Array:	1 3 4 2 5 3 4 2
		Step1:	1 | | | | | | | //push 1
		Step2:	1-3 | | | | | | //push 3
		Step3:	1-3-4 | | | | | //push 4
		Step4:	1----2| | | | |	//push 2	pop 4,3(1<2)	push 2
		Step5:	1----2-5| | | | //push 5
		Step6:	1----2----3 | | //push 3	pop 5(2<3)		push 3
		Step7:	1----2----3-4 | //push 4
		Step8:	1-------------2 //push 2	pop 4,3,2(1<2)	push 2
	
	// 8.2.3 Sliding Window Minimum
	// Constant-size subarray
	// Data Structure: Queue
	// Maintain a queue where each-element > previous-ele
	e.g. Array:	2 1 4 5 3 4 1 2
		Step1: [--1-4-5]
		Step2:   [1-----3]
		Step3:	   [----3-4]
		Step4:	     [------1]
		Step5:		   [----1-2]
	
	// 8.3 Finding Minimum Values -------------------------------------
	
	// 8.3.1 Ternary Search		(bs for discrete, ts for continuous)
	// Split into 3 parts: [XL,a],[a,b],[b,Xr]
	// a = (2*Xl+Xr)/3, b = (Xl+2*Xr)/3
	// if f(a)<f(b), x in [Xr,b]
	// else			 x in [a, Xr]
	
	// 8.3.2 Convex Functions
	// If f(x)&&g(x), then f(x)+g(x) and max(f(x),g(x)) are convexfunctions
	
	// 8.3.3 Minimizing Sums
	// Q1. Given a[1..n], find x that minimizes sigma|ai-x|
	// 		F1. |ai-x| is convex --> sigma|ai-x| is convex --> ternary search
	// 		F2. Optimal is always *median* of a[]
	// Q2. Given a[1..n], find x that minimizes sigma(ai-x)^2
	//		F1.	ternary search
	//		F2. Optimal is always *average* of a[]
}
