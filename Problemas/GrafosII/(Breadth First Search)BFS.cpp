vector<int> bfs(vector<vector<int > >& graph, int curr){
	vector<int> dist(graph.size(), -1);
	queue<int> queue;
	dist[curr] = 0;
	queue.push(curr);

	while(!queue.empty()){
		int x = queue.front();
		queue.pop();

		for(int y: graph[x]){
			if(dist[y] == -1){
				dist[y] = dist[x] + 1;
				queue.push(y);
			}
		}
	}
	return dist;
}
