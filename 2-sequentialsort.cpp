#include <iostream>
using namespace std;

class SequentialSort
{
private:
    int arr[100];
    int n;

public:
    void input()
    {
        while (true)
        {
            cout << "Enter number of elements: ";
            cin >> n;

            if (cin.fail() || n <= 0 || n > 100)
            {
                cout << "Invalid input! Enter value between 1 and 100.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else
                break;
        }

        cout << "\nEnter array elements:\n";

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
    }

    void sequentialSort()
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] > arr[j])
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    void display()
    {
        cout << "\nSorted Array:\n";

        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    SequentialSort obj;

    obj.input();

    obj.sequentialSort();

    obj.display();

    return 0;
}