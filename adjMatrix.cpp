#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
private:
    vector<vector<int>> adjMatrix;
    int numVertices;
    vector<int> visited;

public:
    Graph(int numVertices)
    {
        this->numVertices = numVertices;
        adjMatrix.resize(numVertices, vector<int>(numVertices, 0));
        visited.resize(numVertices, 0);
    }

    void addEdge(int src, int dest)
    {
        if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices)
        {
            adjMatrix[src][dest] = 1;
            adjMatrix[dest][src] = 1;
        }
        else
        {
            cout << "Invalid vertices. Please try again." << endl;
        }
    }

    void dfs(int startVertex, vector<string> &nodes)
    {
        visited[startVertex] = 1;
        cout << nodes[startVertex] << " ";

        for (int i = 0; i < numVertices; i++)
        {
            if (adjMatrix[startVertex][i] && !visited[i])
            {
                dfs(i, nodes);
            }
        }
    }

    void bfs(int startVertex, vector<string> &nodes)
    {
        vector<int> visited(numVertices, 0);
        queue<int> bfsQueue;
        bfsQueue.push(startVertex);
        visited[startVertex] = 1;

        while (!bfsQueue.empty())
        {
            int currentVertex = bfsQueue.front();
            bfsQueue.pop();
            cout << nodes[currentVertex] << " ";

            for (int i = 0; i < numVertices; i++)
            {
                if (adjMatrix[currentVertex][i] && !visited[i])
                {
                    bfsQueue.push(i);
                    visited[i] = 1;
                }
            }
        }
    }
};

int main()
{
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    if (numVertices <= 0 || numVertices > 50)
    {
        cout << "Invalid number of vertices. Please try again." << endl;
        return 0;
    }

    vector<string> nodes(numVertices);
    for (int i = 0; i < numVertices; i++)
    {
        cout << "Enter node " << i + 1 << " (name): ";
        cin >> nodes[i];
    }

    Graph graph(numVertices);

    int choice;
    int src, dest;
    int startVertex;

    do
    {
        cout << "\nGraph Menu\n";
        cout << "1. Add Edge\n";
        cout << "2. Depth First Search (DFS)\n";
        cout << "3. Breadth First Search (BFS)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter source vertex: ";
            cin >> src;
            cout << "Enter destination vertex: ";
            cin >> dest;
            graph.addEdge(src - 1, dest - 1);
            break;
        case 2:
            cout << "Enter the starting vertex: ";
            cin >> startVertex;
            cout << "DFS: ";
            graph.dfs(startVertex - 1, nodes);
            cout << endl;
            break;
        case 3:
            cout << "Enter the starting vertex: ";
            cin >> startVertex;
            cout << "BFS: ";
            graph.bfs(startVertex - 1, nodes);
            cout << endl;
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}