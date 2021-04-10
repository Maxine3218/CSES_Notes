#include <bits/stdc++.h>
using namespace std;

/*Dynamic Programming*/
int main(){
//6.1 Basics ---------------------------
	//Problem: coins with value of {c1,c2,...,ck} target sum of money n; use as few coins as possible
	//step 1: find subproblem -- top-down? bottom-up?
	/*
	solve(x) = min(	solve(x-c1) + 1,
					solve(x-c2) + 1,
					...
					solve(x-cn) + 1)
				[ INF				x<0
	solve(x) =	[ 0					x=0
				[ min(solve(x-c)+1)	x>0
	*/
	int solve (int x){
		if (x<0) return INF;
		if (x==0) return 0;	//base case
		int best = INF;
		for (auto c : coins)
			best = min(best,solve(x-c)+1);	//not efficient enough
		return best;
	}
	// thus memorize subproblems
	// Time Complexity: O(nk) -n as target sum; -k as num of coins
	bool ready[N];	//calculated?
	int value[N];
	int solve (int x){
		if (x<0) return INF;
		if (x==0) return 0;
		if (ready[x]) return value[x];
		
		int best = INF;
		for (auto c : coins)
			best = min(best,solve(x-c)+1);
		ready[x] = true;
		value[x] = best;
		return best;
	}
	//Inerative implementation			//smaller constant factors
	value[0] = 0;
	for (int x=1; x<=n; x++) {
		value[x] = INF;
		for (auto c : coins)
			if (x-c>=0)
				value[x] = min (value[x], value[x-c]+1); 
	}
	/* ---------- Constructing solution ---------- */
	int first[N];
	value[0] = 0;
	for (int x = 1; x <= n; x++) {
		value[x] = INF;
		for (auto c : coins) {
			if (x-c >= 0 && value[x-c]+1 < value[x]) {
				value[x] = value[x-c]+1;
				first[x] = c;
			}
		}
	}
	while (n>0){
		cout<<first[n]<<'\n';
		n -= first[n];
	}
	/* ---------- Counting Solution ---------- */
	// solve(x) = sigma( solve(x-c))
	count[0] = 1;	//base case: one way to form sum of 0
	for (int x = 1; x <= n; x++){
		for (auto c : coins) {
			if (x-c >=0) {
				//count[x] %= m;	//modulo m if x is too big
				count[x] += count[x-c];
			}
		}
	}
//6.2 Further Examples ---------------------------
	/* Longest Incresing Subsequence*/
	array[i]	6 2 5 1 7 4 8 3
	length[i]	1 1 2 1 3 2 4 2
	// Implementation
	// Time Complexity: O(n^2)
	for (int k = 0; k < n; k++) {
		length[k] = 1;
		for (int i = 0; i < k; i++) {
			if (array[i] < array[k]) {
				length[k] = max(length[k],length[i]+1);
			}
		}
	}
	/* Paths in a Grid */
	//   ¡úx	only move in two directions, R & D
	// y¡ý 		get maximum value possible
	sum(y,x) = max(sum(y,x-1),sum(y-1,x)) + value[y][x];
	
	/* Knapsack Promblems */
	//sum of x		choose k, find x-wk		don't choose k, find x
	possible(x,k) = possible(x-wk,k-1) or possible(x,k-1)
	//base case:
	possible(x,0) = [true	x=0 ]
					[false	x!=0]
	// Implementation
	// Time Complexity: O(nm)
	possible[0][0] = true;
	for (int k = 1; k <= n; k++) {
		for (int x = 0; x <= m; x++){
			if (x-w[k] >= 0) {
				possible[x][k] |= possible[x-w[k]][k-1];
			}
			possible[x][k] |= possible[x][k-1];
		}
	}
	// OR:
	possible[0] = true;
	for (int k = 1; k <= n; k++) {
		for (int x = m-w[k]; x >= 0; x--) {		//update right to left
			possible[x+w[k]] |= possible[x];	//cuz pos[k] is based on pos[k-1]
		}
	}
	/* Permutation n! to Subsets 2^n */
	for each subset S, calculate [minimum num of rides needed]ride(S) and [minimum weight of last ride]last(S)
	// Implementation
	pair<int,int> best[1<<N];	//containing ride(S),last(S)
	best[0] = {0,0};							//best[0..2^n-1]
	for (int s = 1; s < (1<<n); s++) {			// s: [1, 2^n-1]
		// initial value: n+1 rides needed
		best[s] = {n+1,0};
		for (int p = 0; p < n; p++) {
			if (s&(1<<p)) {
				auto option = best[s^(1<<p)];
				if (option.second+weight[p] <= x) {
					// add p to an existing ride
					option.second += weight[p];
				} else {
					// new ride for p
					option.first++;
					option.second = weight[p];
				}
				best[s] = min(best[s], option);
			}
		}
	}
}
