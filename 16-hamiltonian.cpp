#include <iostream>
using namespace std;

class Hamiltonian
{
private:
    int graph[10][10];
    int path[10];
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

                    if (cin.fail() ||
                        (graph[i][j] != 0 &&
                         graph[i][j] != 1))
                    {
                        cout << "Invalid input! Enter only 0 or 1: ";
                        cin.clear();
                        cin.ignore(1000, '\n');
                    }
                    else
                        break;
                }
            }
        }

        for (int i = 0; i < n; i++)
            path[i] = -1;
    }

    bool isSafe(int v, int pos)
    {
        // Check adjacency
        if (graph[path[pos - 1]][v] == 0)
            return false;

        // Check already visited
        for (int i = 0; i < pos; i++)
        {
            if (path[i] == v)
                return false;
        }

        return true;
    }

    bool hamiltonian(int pos)
    {
        // All vertices included
        if (pos == n)
        {
            // Check edge to starting vertex
            if (graph[path[pos - 1]][path[0]] == 1)
                return true;
            else
                return false;
        }

        // Try different vertices
        for (int v = 1; v < n; v++)
        {
            if (isSafe(v, pos))
            {
                path[pos] = v;

                if (hamiltonian(pos + 1))
                    return true;

                // Backtracking
                path[pos] = -1;
            }
        }

        return false;
    }

    void solve()
    {
        path[0] = 0;

        if (hamiltonian(1))
        {
            cout << "\nHamiltonian Cycle Exists:\n";

            for (int i = 0; i < n; i++)
            {
                cout << path[i] << " ";
            }

            cout << path[0] << endl;
        }
        else
        {
            cout << "\nNo Hamiltonian Cycle Exists.\n";
        }
    }
};

int main()
{
    Hamiltonian obj;

    obj.input();

    obj.solve();

    return 0;
}