#include <iostream>
#include <climits>
using namespace std;

#define MAX 100

class Prims 
{
private:
    int graph[MAX][MAX];
    int n;

public:
    void input() 
    {
        while (true)
        {
            cout << "Enter number of vertices: ";
            cin >> n;

            if (!cin.fail() && n > 0 && n <= MAX)
                break;

            cout << "Invalid number of vertices! Try again.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cout << "Enter adjacency matrix (0 for no edge):\n";

        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                while (true)
                {
                    cout << "Enter value for [" << i << "][" << j << "]: ";
                    cin >> graph[i][j];

                    if (!cin.fail() && graph[i][j] >= 0)
                        break;

                    cout << "Invalid input! Enter non-negative value.\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
            }
        }
    }

    void primMST() 
    {
        int parent[MAX];
        int key[MAX];
        bool mstSet[MAX];

        for (int i = 0; i < n; i++) 
        {
            key[i] = INT_MAX;
            mstSet[i] = false;
        }

        key[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < n - 1; count++) 
        {
            int min = INT_MAX, u = -1;

            for (int v = 0; v < n; v++) 
            {
                if (!mstSet[v] && key[v] < min) 
                {
                    min = key[v];
                    u = v;
                }
            }

            if (u == -1) 
            {
                cout << "Graph is disconnected. MST cannot be formed.\n";
                return;
            }

            mstSet[u] = true;

            for (int v = 0; v < n; v++) 
            {
                if (graph[u][v] != 0 && !mstSet[v] && graph[u][v] < key[v]) 
                {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
            }
        }

        printMST(parent);
    }

    void printMST(int parent[]) 
    {
        int totalCost = 0;

        cout << "\nEdge \tWeight\n";
        for (int i = 1; i < n; i++) 
        {
            cout << parent[i] << " - " << i 
                 << " \t" << graph[parent[i]][i] << endl;
            totalCost += graph[parent[i]][i];
        }

        cout << "Total cost of MST: " << totalCost << endl;
    }
};

int main() 
{
    Prims p;
    p.input();
    p.primMST();
    return 0;
}