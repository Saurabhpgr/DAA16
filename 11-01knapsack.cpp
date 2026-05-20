#include <iostream>
using namespace std;

class Knapsack
{
private:
    int profit[20];
    int weight[20];
    int n, capacity;

public:
    void input()
    {
        while (true)
        {
            cout << "Enter number of items: ";
            cin >> n;

            if (cin.fail() || n <= 0 || n > 20)
            {
                cout << "Invalid input! Enter value between 1 and 20.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else
                break;
        }

        cout << "\nEnter profits:\n";

        for (int i = 0; i < n; i++)
        {
            while (true)
            {
                cin >> profit[i];

                if (cin.fail() || profit[i] <= 0)
                {
                    cout << "Invalid input! Enter positive integer: ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                else
                    break;
            }
        }

        cout << "\nEnter weights:\n";

        for (int i = 0; i < n; i++)
        {
            while (true)
            {
                cin >> weight[i];

                if (cin.fail() || weight[i] <= 0)
                {
                    cout << "Invalid input! Enter positive integer: ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                else
                    break;
            }
        }

        while (true)
        {
            cout << "\nEnter knapsack capacity: ";
            cin >> capacity;

            if (cin.fail() || capacity <= 0)
            {
                cout << "Invalid input! Enter positive integer.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else
                break;
        }
    }

    int knapsack(int i, int capacity)
    {
        // Base condition
        if (i == n || capacity == 0)
            return 0;

        // Item cannot be included
        if (weight[i] > capacity)
        {
            return knapsack(i + 1, capacity);
        }

        // Include current item
        int include =
            profit[i] +
            knapsack(i + 1,
                     capacity - weight[i]);

        // Exclude current item
        int exclude =
            knapsack(i + 1, capacity);

        // Return maximum profit
        if (include > exclude)
            return include;
        else
            return exclude;
    }

    void display()
    {
        cout << "\nMaximum Profit = "
             << knapsack(0, capacity)
             << endl;
    }
};

int main()
{
    Knapsack obj;

    obj.input();

    obj.display();

    return 0;
}