#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define ROW 5
#define COL 5

struct Node
{
int x, y;
int distance;
bool operator<( Node& a)
{
return distance > a.distance;
}
};

int row[] = {-1, 0, 0, 1};
int col[] = {0, -1, 1, 0};

bool isValid(int x, int y)
{
return (x >= 0 && x < ROW && y >= 0 && y < COL);
}

int bestFirstSearch(int grid[][COL], Node src, Node dest)
{
if (!grid[src.x][src.y] || !grid[dest.x][dest.y])
return -1;

bool visited[ROW][COL];
memset(visited, false, sizeof visited);

priority_queue<int> pq;

pq.push(src.distance);

while (!pq.empty())
{
Node curr = pq.top();
pq.pop();

if (curr.x == dest.x && curr.y == dest.y)
return curr.distance;

for (int i = 0; i < 4; i++)
{
int x = curr.x + row[i];
int y = curr.y + col[i];

if (isValid(x, y) && !visited[x][y] && grid[x][y])
{
visited[x][y] = true;
Node next = {x, y, curr.distance + 1};
pq.push(next);
}
}
}

return -1;
}

int main()
{
int grid[ROW][COL] =
{
{1, 0, 1, 1, 1},
{1, 0, 1, 0, 1},
{1, 1, 1, 0, 1},
{0, 0, 0, 0, 1},
{1, 1, 1, 0, 1}
};

Node src = {0, 0, 0};
Node dest = {4, 4};

int distance = bestFirstSearch(grid, src, dest);

if (distance != -1)
cout << "The shortest path is " << distance << endl;
else
cout << "The destination cannot be reached." << endl;

return 0;
}
