#include <iostream>
#include <vector>

using namespace std;


class Graph {
int V;
vector<int> *adj;

public:
Graph(int V);
void addEdge(int v, int w);
bool IDDFS(int s, int d, int depth);
};

Graph::Graph(int V) {
this->V = V;
adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w) {
adj[v].push_back(w);
}

bool Graph::IDDFS(int s, int d, int depth) {
if (s == d)
return true;

if (depth <= 0)
return false;

for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
if (IDDFS(*i, d, depth - 1) == true)
return true;

return false;
}

int main() {
Graph g(7);
g.addEdge(0, 1);
g.addEdge(0, 2);
g.addEdge(1, 3);
g.addEdge(1, 4);
g.addEdge(2, 5);
g.addEdge(2, 6);

int target = 6;
int maxDepth = 3;
for (int i = 0; i <= maxDepth; i++) {
if (g.IDDFS(0, target, i)) {
cout << "Target found at depth " << i << endl;
return 0;
}
}

cout << "Target not found" << endl;
return 0;
}
