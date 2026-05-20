#include <iostream>
using namespace std;

class Kruskal
{
private:
    int graph[10][10];
    int parent[10];
    int n;

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
                        cout << "Invalid input! Enter non-negative value: ";
                        cin.clear();
                        cin.ignore(1000, '\n');
                    }
                    else
                        break;
                }
            }
        }

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int i)
    {
        while (parent[i] != i)
            i = parent[i];

        return i;
    }

    void unionSet(int u, int v)
    {
        parent[u] = v;
    }

    void kruskalMST()
    {
        int edges = 0;
        int totalCost = 0;

        cout << "\nEdges in Minimum Spanning Tree:\n";

        while (edges < n - 1)
        {
            int min = 9999;
            int u = -1, v = -1;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (graph[i][j] != 0 &&
                        graph[i][j] < min)
                    {
                        min = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }

            int setU = find(u);
            int setV = find(v);

            if (setU != setV)
            {
                cout << u << " - "
                     << v << " : "
                     << min << endl;

                totalCost += min;

                unionSet(setU, setV);

                edges++;
            }

            graph[u][v] = graph[v][u] = 9999;
        }

        cout << "\nTotal Cost = "
             << totalCost << endl;
    }
};

int main()
{
    Kruskal obj;

    obj.input();

    obj.kruskalMST();

    return 0;
}