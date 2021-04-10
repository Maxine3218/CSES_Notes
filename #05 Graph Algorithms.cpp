#include <bits/stdc++.h>
using namespace std;

/*
----------------Graph Algorithms----------------
*/

// 7.1 Terminology & Data Structures ----------------
[Terms]
GRAPH:	collection of /*vertices*/ interconnected by /*edges*/ 
ORDER:	num of vertices
SIZE:	num of edges
for a graph of n nodes and m edges:
/*degree*/ 	-- number of neighbors //δΔ 
			-- sum always 2*m
			-- [directed] /*indegree*/ /*outdegree*/
/*regular*/	-- degree of every node is a constant d
/*complete*/-- degree of every node is n
/*bipartile*/	-- no adjacent nodes with same color
				-- deg(A) = deg(B) = E
				-> no cycle with odd-number edges
[Reps]
/*Adjacency Lists*/
	vector<int> adj[N];
	adj[1].push_back(2);
	adj[2].push_back(3);
	adj[3].push_back(1);
	//weighted
	vector<pair<int,int>> adj[N];
	adj[1].push_back({2,5});
	adj[2].push_back({3,7});
	adj[3].push_back({1,2});
	//all node from s
	for (auto u:adj[s]){
		//process node u
	}
/*Adjacent Matrix*/				//con: mostly zero thus space wasting
	int adj[N][N];				//适用稠密图 
	adj[a][b] = 1;
	adj[a][b] = 0;
	//weighted
	adj[a][b] = 5;
	adj[a][b] = 0; 
/*Edge List*/
	vector<pair<int,int>> edges;
	edges.push_back({1,2});
	edges.push_back({2,3});
	edges.push_back({3,1});
	//weighted
	vector<tuple<int,int,int>> edges;
	edges.push_back({1,2,5});
	edges.push_back({2,3,7});
	edges.push_back({3,1,2});
	
// 7.2 Traversal DFS/BFS --------------------------------
[Applications]
Connectivity Check
Cycle Detection
Bipartiteness Check (k=2)
--------------------------------
[DFS]
	vector<int> adj[N];
	bool visited[N];
	/*Implementation*/
	void dfs(int s){
		if(visited[s]) return;
		visited[s] = true;
		//process node s
		for (auto u: adj[s]){
			dfs(u);
		}
	}
	/*Analysis*/
	Time Complexity -- O(n+m)
--------------------------------
[BFS]
	// O(|E|) if unweighted or 0-1; O(|V|^2+|E|)orO(|E|log|V|) if weighted
	queue<int> q;		//nodes to be processed in increasing order of dis
	bool visited[N];
	vector<int> distance(n);	//length of SP
	vector<int> parent(n);		//restore SP
	/*Implementation*/
	visited[x] = true;
	distance[x] = 0;
	parent[x] = -1; 
	q.push(x);
	while (!q.empty()){
		int s = q.front(); q.pop();
		//processnode s
		for (auto u: adj[s]){
			if(visited[u]) continue;
			visited[u] = true;
			distance[u] = distance[s]+1;
			parent(u) = s;
			q.push(u);
		}
	} 
	//restore and display SP to u
	if (!visited[u]) {
	    cout << "No path!";
	} else {
    	vector<int> path;
    	for (int v = u; v != -1; v = p[v])
    	    path.push_back(v);
    	reverse(path.begin(), path.end());
    	cout << "Path: ";
    	for (int v : path)
        	cout << v << " ";
	}
	// Connected Components: Perform BFS on each vertices without zeroing visited[]
	// Solution to a problem/game with least number of moves
	// SP in graph with weight 0/1 => 0-1 BFS
	//		1. get rid of visited[]
	//		2. compare distance, if current weight is 0, then push_front, 1-push_back
	//		3. Shortest Cycle in graph:  For v:vertex, cumpute cycle containing v
	//		4. All vertices on any shortest path between a and b:
	//		   Run 2 BFSs from a and b, get disa[] and disb[],
	//		   then if disa[v] + disb[v] = disa[b], vertex found
	//		5. Parity length: Construct auxiliary graph of states (v,c)
// 7.3 Shortest Path --------------------------------
[weighted]
/*Bellman-Ford Algorithm*/ [no negative cycles, final after (n-1)rounds]
Graph Storage: Edge List containing tuples (a,b,w)
//边集数组和链式前向星 
	/*Implementation*/
	for (int i = 1; i <= n; i++) {
		distance[i] = INF;
	}
	distance[x] = 0;
	for (int i =1; i<= n-1; i++) {	// n-1 rounds
		for (auto e : edges) {
			int a, b, w;
			tie(a, b, w) = e;
			distance[b] = min(distance[b], distance[a]+w);
		}
	}					//check negative cycle: n rounds
						//any distance reduction indicates negative cycle
	/*Analysis*/
	//[单源最短路径] 可负权边 无负圈 
	//迭代意义：每次迭代k，找到经历k条边的最短路
	//仅上次迭代被松弛的点才有可能参与下一次迭代的松弛 
	Time Complexity: O(nm)
	Pro: neg cycle detection
	Con: tc bit higher than dijkstra
	/*SPFA Algorithm*/
	//链式前向星 
//-------------------------------------------------------
/*Dijkstra's Algorithm*/ [more efficient, large graphs, no negative edges]
Graph storage: adjacency lists adj[a] containg a pair (b,w) indicates a->(w)->b
priority queue contains pairs (-d,x) indicates current->(d)->x

priority_queue<pair<int,int>> q;
	//Implementation
	for (int i = 1; i <= n; i++) {		//d.assign(n, INF);
		distance[i] = INF;
	}
	distance[x] = 0;
	q.push({0,x});
	while (!q.empty()){
		int a = q.top().second; q.pop();
		if (processed[a]) continue;
		processed[a] = true;
		for (auto u : adj[a]){
			int b = u.first, w = u.second;
			if (distance[a]+w < distance[b]) {
				distance[b] = distance[a]+w;
				q.push({-distance[b],b});
			}
		}
	}
	//Analysis
	//无负权边 
	Time Complexity: O(n + mlogm)
	Greedy Method: no negative edges
//----------------------------------------------------------
/*Floyd-Warshall Algorithm*/ [SLOW]
Graph Storage: adjacency matrix dist[a][b]
	/*Implementation*/
	for (int i = 1; i <= n; i++) {			//constructs the distance matrix
		for (int j = 1; j<= n; j++) {
			if (i == j) dist[i][j] = 0;
			else if (adj[i][j]) dist[i][j] = adj[i][j];
			else dist[i][j] = INF;
		}
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
	/*Analysis*/
	Time Complexity: O(n^3)

// 7.4 DAGs -- Directed Acyclic Graphs
/*Topological sort*/ -- DFS
In DP, we can use DAGs to reprensent problems,
with nodes as states, and edges indicate dependencies

// 7.5 Successor Graphs (or functional graphs)
	all outdegree = 1;	//unique successor
	//succ(x)
	succ(1) = 2;
	succ(2) = 3;
	succ(3) = 1;
	//succ(x,k)
	Precalculation:
		base case: 
			if(k=1) succ(x,k) = succ(x);
		else:
			if(k>1) succ(x,k) = succ(succ(x,k/2),k/2);
	Usage:
		succ(x,11) = succ(succ(succ(x,8),2),1);
/*Cycle Detection*/
	(1) visited[N] 
		Time: O(n)
		Space: O(n)
	(2) Floyd Algo
		Time: O(n)
		Space: O(1)
		//Implementation
		a = succ(x);
		b = succ(succ(x));
		while (a != b){
			a = succ(a);
			b = succ(succ(b));
		}
		
		a = x;
		while (a != b){
			a = succ(a);
			b = succ(b);
		}
		first = a;	//first node in cycle
		
		b = succ(a);
		length = 1;
		while (a!=b){
			b = succ(b);
			length++;		//get cycle length
		}
		
// 7.6 Kruskal's & Prim's

/*Kruskal's algo*/
1. sort all edges in increasing order of weights
2. add edge to graph if it does not create a cycle
	Gprah Representation: Edge List
	Time Complexity: [sorting] O(mlogm) + [same+unite] O(mlogn)
	/*Union-find Structure*/
	always connect the rep of smaller set to the rep of larger set
	/*Implementation*/
	//1. sort edge list in O(mlogm) time//
	//2. build minimum spanning tree
	for (...) {
		if (!same(a,b)) unite(a,b)
	}
	
	for (int i=1; i<=n; i++) link[i] = i;	//next ele in path
	for (int i=1; i<=n; i++) size[i] = 1;	//size of corresponding set
	
	int find (int x){						//get rep for x
		while (x != link[x]) x = link[x];
		return x;
	}
	int find_with_path_compression(int x){		//union-find in O(α(n)) time 
		if (x == link[x]) return x;			//non-applicable in dynamic connectivity algo
		return link[x] = find(link[x]);
	}
	bool same (int a, int b){				//same set or not
		return find(a) == find(b);
	}
	void unite (int a, int b){
		a = find(a);
		b = find(b);
		if (size[a] < size[b]) swap(a,b);
		size[a] += size[b];
		link[b] = a;
	}
/*Prim's algo*/
1. add an arbitrary node to the tree
2. choose a minimum weight edge that adds a new node to the tree
   till all nodes are added
Data Structure: /*priority queue*/ consisting of nodes with one edge distance in increasing order
Time Complexity: O(n+mlogm)

