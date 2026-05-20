#include <iostream>
#include <climits>
using namespace std;

class Dijkstra
{
private:
    int graph[10][10];
    int dist[10];
    bool visited[10];
    int n, source;

public:
    void input()
    {
        while (true)
        {
            cout << "Enter number of vertices: ";
            cin >> n;

            if (cin.fail() || n <= 0 || n > 10)
            {
                cout << "Invalid input! Enter value between 1 and 10.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else
                break;
        }

        cout << "\nEnter adjacency matrix:\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                while (true)
                {
                    cin >> graph[i][j];

                    if (cin.fail() || graph[i][j] < 0)
                    {
                        cout << "Invalid input! Enter non-negative value.\n";
                        cin.clear();
                        cin.ignore(1000, '\n');
                    }
                    else
                        break;
                }
            }
        }

        while (true)
        {
            cout << "\nEnter source vertex: ";
            cin >> source;

            if (cin.fail() || source < 0 || source >= n)
            {
                cout << "Invalid source vertex!\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else
                break;
        }
    }

    void dijkstra()
    {
        // Initialize arrays
        for (int i = 0; i < n; i++)
        {
            dist[i] = INT_MAX;
            visited[i] = false;
        }

        dist[source] = 0;

        for (int count = 0; count < n - 1; count++)
        {
            int min = INT_MAX;
            int u = -1;

            // Find minimum distance vertex
            for (int i = 0; i < n; i++)
            {
                if (!visited[i] && dist[i] < min)
                {
                    min = dist[i];
                    u = i;
                }
            }

            visited[u] = true;

            // Update adjacent vertices
            for (int v = 0; v < n; v++)
            {
                if (!visited[v] &&
                    graph[u][v] != 0 &&
                    dist[u] != INT_MAX &&
                    dist[u] + graph[u][v] < dist[v])
                {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }

        display();
    }

    void display()
    {
        cout << "\nShortest distances from source vertex "
             << source << ":\n";

        for (int i = 0; i < n; i++)
        {
            cout << "Vertex "
                 << i
                 << " -> "
                 << dist[i]
                 << endl;
        }
    }
};

int main()
{
    Dijkstra obj;

    obj.input();

    obj.dijkstra();

    return 0;
}