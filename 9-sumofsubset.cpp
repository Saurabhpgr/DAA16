#include <iostream>
#include <vector>
using namespace std;

class SubsetSum
{
    private:
        vector<int> arr;
        int n, target;

    public:
        void input()
        {
            while (true)
            {
                cout << "Enter number of elements: ";
                cin >> n;

                if (cin.fail() || n <= 0)
                {
                    cout << "Invalid input! Enter a positive integer.\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                else
                    break;
            }

            arr.resize(n);

            cout << "Enter elements:\n";
            for (int i = 0; i < n; i++)
            {
                while (true)
                {
                    cin >> arr[i];
                    if (cin.fail())
                    {
                        cout << "Invalid input! Enter integer again: ";
                        cin.clear();
                        cin.ignore(1000, '\n');
                    }
                    else
                        break;
                }
            }

            while (true)
            {
                cout << "Enter target sum: ";
                cin >> target;

                if (cin.fail())
                {
                    cout << "Invalid input! Enter integer.\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                else
                    break;
            }
        }

        void findSubsets(int index, vector<int> &current, int currentSum)
        {
            if (currentSum == target)
            {
                cout << "{ ";
                for (int x : current)
                    cout << x << " ";
                cout << "}\n";
                return;
            }

            if (index >= n || currentSum > target)
                return;
                
            //findSubsets(index + 1, current, currentSum);

            current.push_back(arr[index]);
            findSubsets(index + 1, current, currentSum + arr[index]);

            current.pop_back();

            findSubsets(index + 1, current, currentSum);
        }

        void solve()
        {
            vector<int> current;
            cout << "\nSubsets with sum " << target << " are:\n";
            findSubsets(0, current, 0);
        }
};

int main()
{
    SubsetSum obj;
    obj.input();
    obj.solve();
    return 0;
}