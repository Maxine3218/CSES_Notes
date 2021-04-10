#include <iostream>
#include <stdio>
#include <string.h>
using namespace std;
//Chapter 04 Sorting and Searching

int main(){
	/*---------*/[4.1 Sorting Algorithms]/*---------*/
	
	/*---------*/Bubble Sort/*---------
	Time: O(n^2)
	In place, Stable
	---------------------------
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1; j++) {
			if (array[j] > array[j+1]) {
				swap(array[j],array[j+1]);
			}
		}
	}*/
	
	/*---------*/Merge Sort/*---------
	Time: O(n*logn) 
	---------------------------
	MergeSort(arr[], l, r): 
		1. If a = b, do not do anything.
		2. Calculate the position of the middle element: k = floor((a + b)/2).
		3. Recursively sort the subarray array[a...k].
			MergeSort(arr, l, m)
		4. Recursively sort the subarray array[k+1...b].
			MergeSort(arr, m+1, r)
		5. Merge the sorted subarrays array[a...k] and array[k+1...b] into a sorted subarray array[a . . . b].
			Merge(arr, l, m, r)
	---------------------------
	O(logn) recursive levels * O(n) each level	*/
	
	/*---------*/QuickSort/*-----------
	Time: 
	------------------------------
	4 ways to pick pivot: 1.first 2.last 3.random 4.median
	(smaller than x) - (pivot x) - (larger than x)
	 
	/*---------*/Lower Bound -- Compare array elements/*---------
	O(nlogn):
	sorting tree with n! leafs(permutation) + height 2^h
	=> 2^h >= n!
	=> h >= log(n!)
	=>   >= (n/2)*log(n/2)	
	------------------*/
	
	/*---------*/Counting Sort [0...c]/*---------
	Time: O(n)
	---------------------------
	O(n): bookkeeping array => total appearance time
	+
	O(n): generate sorted array
	---------------------------
	!!!c has to be small
	------------------*/
	
	
	/*---------*/ Sorting in Practice /*---------*/
	//Use the lib. Don't implement
	------------------
	vector<int> v={4,2,5,3,5,8,3};
	sort(v.begin(),v.end());		//increasing
	sort(v.rbegin(),v.rend());		//decreasing
	------------------
	int n=7;
	int a[]={4,2,5,3,5,8,3};
	sort(a,a+n);					//sort arrays
	------------------
	String s="monkey";
	sort(s.begin(),s.end());		//s="ekmnoy"
	------------------
	//Comparison Operator
	pairs/tuples are sorted primarily according to sequential elements
	
	//define comparison operator in struct: operator<
	[essentially defines comparison primaries]
	--
	struct point {					//pri by x, sec by y
		int x, y;
		bool operator<(const point &p) {
			if (x == p.x) return y < p.y;
			else return x < p.x;
		}
	};
	
	//define comparison funcs
	bool comp(string a, string b) {				//pri by length, sec by alphabet
		if (a.size() == b.size()) return a < b;
		else return a.size() < b.size();
	}
	----Usage
	sort(v.begin(), v.end(), comp);
	//---------------------------------------------------------------------------------------
	
	/*---------*/[4.2 Solving Problems by Sorting]/*---------*/
	 
	/*---------*/Sweep Line Algorithms
	//Customer in/out => +/-
	
	/*---------*/Scheduling Events
	//shortest/earliest beginning/
	//Or: next possible with earliest end time** 
	
	/*---------*/Tasks and Deadlines
	//Given n tasks + durations + deadlines
	//Score (ddl - finish time)
	//Greedy: performance seq sorted by durations
	
	//----------------------------------------------------------------------------------------
	
	/*---------*/[4.3 Binary Search]/*---------*/
	Time: O(logn)
	//on a sorted array
	
	
}
