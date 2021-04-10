#include <iostream>
#include <stdio>
#include <string.h>
using namespace std;
//Chapter 03 Efficiency

int main(){
	//---------3.1---------//
	//Time Complexity
	/*e.g.This is O(2^n)
	void g(int n) {
		if (n == 1) return;
		g(n-1);
		g(n-1);
	}
	*/
	//Input Size => Time Complexity => design
	//O -upper bound
	//ж╕-lower bound 
	//жи-exact bound
	
	//---------3.2---------//
	//Maximum Subarray Sum
	//Brute Force => (max sum at k-1) + k
	//------------------
	//Two Queens Problem
	//Brute Force -- try every one -- O(n^4) n^2*(n^2-1)
	//Observation -- minus attacks -- O(n^2)
	//Recursive   -- q(n)=>q(n+1)  -- O(n)
	//Calculation -- get formula   -- O(1)
	
} 
