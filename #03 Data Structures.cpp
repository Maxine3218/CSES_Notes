#include <bits/stdc++.h>
using namespace std;
//Chapter 05 Data Structures

int main(){
	//----------------------------------
	vector<int> vi(100);
	vi.reserve(100);		//preallocation
	//5.1 Dynamic Arrays
	//5.1.0 Arrays
	int n=10;
	int array[n];	//fixed, impossible to change after creation
	//5.1.1 Vectors
	//efficiently add and remove elements at the *end* of the structure
	vector<int> v;
	v.push_back(3);		//insert
	v.emplace_back(n);
	
	cout<<v[0]<<"\n";	//visit
	
	vector<int> vec = {2,4,2,5,1};	//create & initialize
	
	vector<int> a(8);	//size 8, initial value 0
	vector<int> b(8,2);	//size 8, initial value 2
	
	//Iterator
	vector<int>::iterator it;
	for(it=vec.begin();it!=vec.end();it++)
    cout<<*it<<endl;
    //--or:
    for(int i=0;i<v.size();cout<<(++i<v.size()?' ':'\n'))
    	cout<<v[i]<<" ";
    //--or:
    for(auto x:v)
		cout<<x<<" ";
	cout<<"\n";
	
	vector<int> v={2,4,2,5,1};
	cout<<v.back()<<"n";	//return last element of the vector //1
	v.pop_back();			//remove last element
	cout<<v.back();			//5
	
	//push_back and pop_back----O(1)
	//---------------------------------------
	//5.1.2 Iterators and Ranges
	//	[5,2,3,1,2,5,7,1]
	//	 |				 |
	//	v.begin()		v.end()
	//  first ele		one after the last
	vector<int>::iterator it;
	for(it=vec.begin();it!=vec.end();it++)
    cout<<*it<<endl;
	
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	random_shuffle(v.begin(),v.end());
	//visit
	cout<<*v.begin()<<"\n";
	//lower/upper bound [binary search]
	//!!given range must be sorted
	vector<int> v = {2,3,3,5,7,8,8,8};
	auto a = lower_bound(v.begin(),v.end(),5);	//iter to first ele >= x
	auto b = upper_bound(v.begin(),v.end(),5);	//iter to fist ele > x
	cout << *a << " " << *b << "\n"; // 5 7		
	//if not found, return end() [iter to one ele after the last]
	//unique elements of the ori vec in sorted order
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	//-----------------------------------------
	//5.1.3 Other Structures
	//deque---manipulate at both ends
	deque<int> d;
	d.push_back(5); // [5]
	d.push_back(2); // [5,2]
	d.push_front(3); // [3,5,2]
	d.pop_back(); // [3,5]
	d.pop_front(); // [5]
	//stack---based on deque
	//push/pop: insert/remove bottom ele
	//top: get last ele
	stack<int> s;
	s.push(2); // [2]
	s.push(5); // [2,5]
	cout << s.top() << "\n"; // 5
	s.pop(); // [2]
	cout << s.top() << "\n"; // 2
	//queue---insert at end, remove from the front
	queue<int> q;
	q.push(2); // [2]
	q.push(5); // [2,5]
	cout << q.front() << "\n"; // 2
	q.pop(); // [5]
	cout << q.back() << "\n"; // 5
	//---------------------------------------
	
	//5.2 Set Structures
	//5.2.1 Set
	//op: insert/search/remove
	//(1) Set:				balanced binary tree 	-- O(logn)
	//(2) unordered_set:	hash table				-- O(1)
	set<int> s;
	s.insert(3);
	s.insert(2);
	s.insert(5);
	cout << s.count(3) << "\n"; // 1	//num of occurence
	cout << s.count(4) << "\n"; // 0
	s.erase(3);							//remove
	s.insert(4);
	cout << s.count(3) << "\n"; // 0	//all eles are distinct	!!!
	cout << s.count(4) << "\n"; // 1	//either 0/1
	
	//size & iteration
	//can not use [] notation
	cout << s.size() << "\n";
	for (auto x : s) {
		cout << x << "\n";
	}
	//find ele
	auto it = s.find(x);
	if(it==s.end()){
		//x is not found
	}
	//Ordered set :find smallest/largest value
	auto first = s.begin();
	auto last = s.end(); last--;	//end points to one ele after the last
	cout << *first << " " << *last << "\n";
	//lower/upper_bound
	cout << *s.lower_bound(x) << "\n";
	cout << *s.upper_bound(x) << "\n";
	//------------------------
	//Multisets -- not distinct
	multiset<int> s;
	s.insert(5);
	s.insert(5);
	s.insert(5);
	cout << s.count(5) << "\n"; // 3			//not efficient
	s.erase(5);					//remove all
	cout << s.count(5) << "\n"; // 0
	s.erase(s.find(5));			//remove only one
	cout << s.count(5) << "\n"; // 2
	
	multiset<int,greater<int>> h;	//decreasing order
	multiset<int,less<int>> h;		//increasing order	//default
	
	multiset<int,greater<int>> h = {2,3,3,5,7,8,8,8};
	multiset<int,greater<int>>::iterator it;							//!!!!!!!
	for(it=h.begin();it!=h.end();cout<<(++it!=h.end()?' ':'\n'))
    	cout<<*it;					//8 8 8 7 5 3 3 2
	auto tmp=h.lower_bound(6);					//*h=5;
	auto tmp=lower_bound(h.begin(),h.end(),6);	//*h=7
	if(tmp!=h.end()) h.erase(tmp);
	else cout<<"w\n";
	//-----------------------------------------------------------
	//5.2.2 Maps
	//key-value pairs -> generalized array. inconsecutive
	//(1)map:			balanced binary search tree	O(logn)
	//(2)unordered_map:	hashing						O(1)
	// Ops: begin()	end()	rbegin()	rend()
	//		clear()	
	//		count() erase() find()	insert()	lower_bound()	upper_bound()
	//		empty()	max_size()	size()
	map<string,int> m;
	m["monkey"] = 4;
	m["banana"] = 3;
	m["harpsichord"] = 9;
	cout << m["banana"] << "\n"; // 3
	cout << m["aybabtu"] << "\n"; // 0	//not exist -> add with default value
	//check if exist
	if (m.count("aybabtu")) {
		// key exists
	}
	//OR:
	iter = m.find("monkey");
	if(iter != m.end())	{
		//found
	}else{
		//not found
	}
	for (auto x : m) {
		cout << x.first << " " << x.second << "\n";
	}
	//-----------------------------------------------------------
	//5.2.3 Priority Queues
	//multiset, support insert/removeal[O(logn)] & retrival[O(1)]
	//based on heap -- easy to find min/max
	priority_queue<int> q;
	//priority_queue<int, vector<int>, less<int> > q;
	q.push(3);				//default in decreasing order(op on max)
	q.push(5);
	q.push(7);
	q.push(2);
	cout << q.top() << "\n"; // 7
	q.pop();
	cout << q.top() << "\n"; // 5
	q.pop();
	q.push(6);
	cout << q.top() << "\n"; // 6
	q.pop();
	//create pri_que in increasing(op on min)
	// priority_queue<Type, Container, Funtional>
	priority_queue<int,vector<int>,greater<int> > q;//!!!!!space or shift op
	
	//priority_queue<pair<int,int> > a;
	
	// queue op:
	// q.top()		first in queue
	// q.empty()	if empty, return 1
	// q.size()		
	// q.push()		add element to end
	// q.emplace()	create an element and add to end
	// q.pop()		delete first in queue
	// q.swap()
	queue<int> qq;
	//
	//------------------------------------------------------------
	//5.2.4 Policy-Based Sets [g++][not part of C++ lib]	PBDS
	#include <ext/pb_ds/assoc_container.hpp>
	using namespace __gnu_pbds;
	//define set that can be indexed like an array
	typedef tree<int,null_type,less<int>,rb_tree_tag,
				tree_order_statistics_node_update> indexed_set;
	//create indexed_set
	indexed_set s;
	s.insert(2);
	s.insert(3);
	s.insert(7);
	s.insert(9);
	//return iter to given pos		//O(logn)
	auto x = s.find_by_order(2);
	cout << *x << "\n"; // 7
	//return pos to given element	//O(logn)
	cout << s.order_of_key(7) << "\n"; // 2
	//not exist, return possible pos [without inserting]
	cout << s.order_of_key(6) << "\n"; // 2
	cout << s.order_of_key(8) << "\n"; // 3
	
	// Application:
	ordered_set st;
	vector<int> sol;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
     	int cnt = st.order_of_key(x);	//return num of items strictly<k
     	st.insert(x);
    	sol.emplace_back(cnt);
   }
	//----------------------------------------------------------------------------
	//5.3 Experiments
	//5.3.1 Set/Sorting?
	//even with the same time complexity, excution-wise time is very diffrent
	//sort			-x	mush faster		simple op
	//unordered set	-3~10x
	//set			-6~60x				balanced search tree -- complex
	
	//5.3.2 Map/Array?	*Pay attention to the large constant factors hidden in the data structure
	//array			-x
	//unordered map	-30x
	//map	
			-100x
	//5.3.3 Priority-queue/Multiset?
	//priority queue-x
	//multiset		-5x
	
	//Appendix: List
	list<int> list1;
	//Ops:
	.front()			.back()
	.push_front(val)	.push_back(val)
	.emplace_front()	.emplace_back()
	.pop_front()		.pop_back() 
	.begin()	.end()	//return iterator to first and thoretical last ele
	.rbegin()	.rend()
	.cbegin()	.cend()
	
	.empty()
	.insert(pos_iter, ele_num, ele)
	.assign(count, val)	//or:assign(list2.begin(),list2.end())
	.erase(it)	//remove single ele
	.remove(val)
	.remove_if(pred)
	.clear()
	
	.reverse()
	.size()
	.sort()
	.unique(/*cmp*/)	//remove all *duplicate*consecutive* eles
	
	void showlist(list <int> g)
	{
	    list <int> :: iterator it;
	    for(it = g.begin(); it != g.end(); ++it)	//traverse
	        cout << '\t' << *it;
	    cout << '\n';
	}
	
}
