#include <iostream>
#include <algorithm>
using namespace std;

class FractionalKnapsack
{
private:
    struct Item
    {
        int profit;
        int weight;
        float ratio;
    };

    Item item[20];

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
                cin >> item[i].profit;

                if (cin.fail() || item[i].profit <= 0)
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
                cin >> item[i].weight;

                if (cin.fail() || item[i].weight <= 0)
                {
                    cout << "Invalid input! Enter positive integer: ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                else
                    break;
            }

            item[i].ratio =
                (float)item[i].profit / item[i].weight;
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

    static bool compare(Item a, Item b)
    {
        return a.ratio > b.ratio;
    }

    void fractionalKnapsack()
    {
        sort(item, item + n, compare);

        float totalProfit = 0;

        for (int i = 0; i < n; i++)
        {
            if (item[i].weight <= capacity)
            {
                capacity -= item[i].weight;

                totalProfit += item[i].profit;
            }
            else
            {
                totalProfit +=
                    item[i].ratio * capacity;

                break;
            }
        }

        cout << "\nMaximum Profit = "
             << totalProfit << endl;
    }
};

int main()
{
    FractionalKnapsack obj;

    obj.input();

    obj.fractionalKnapsack();

    return 0;
}