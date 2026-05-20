#include <iostream>
using namespace std;

class GraphColoring
{
private:
    int graph[10][10];
    int color[10];
    int n, m;

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
                        (graph[i][j] != 0 && graph[i][j] != 1))
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

        while (true)
        {
            cout << "\nEnter number of colors: ";
            cin >> m;

            if (cin.fail() || m <= 0)
            {
                cout << "Invalid input! Enter positive integer.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else
                break;
        }

        for (int i = 0; i < n; i++)
            color[i] = 0;
    }

    bool isSafe(int vertex, int c)
    {
        for (int i = 0; i < n; i++)
        {
            if (graph[vertex][i] == 1 &&
                color[i] == c)
            {
                return false;
            }
        }

        return true;
    }

    bool solve(int vertex)
    {
        // All vertices colored
        if (vertex == n)
            return true;

        // Try all colors
        for (int c = 1; c <= m; c++)
        {
            if (isSafe(vertex, c))
            {
                color[vertex] = c;

                if (solve(vertex + 1))
                    return true;

                // Backtracking
                color[vertex] = 0;
            }
        }

        return false;
    }

    void display()
    {
        if (solve(0))
        {
            cout << "\nSolution Exists:\n";

            for (int i = 0; i < n; i++)
            {
                cout << "Vertex "
                     << i
                     << " ---> Color "
                     << color[i]
                     << endl;
            }
        }
        else
        {
            cout << "\nNo solution exists.\n";
        }
    }
};

int main()
{
    GraphColoring obj;

    obj.input();

    obj.display();

    return 0;
}