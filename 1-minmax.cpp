#include <iostream>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

class MinMax
{
private:
    int *arr;
    int n;
    int minval, maxval;

public:
    void input()
    {
        cout << "Enter number of elements: ";
        cin >> n;

        arr = new int[n];

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dist(1, 1000000);

        for (int i = 0; i < n; i++)
        {
            arr[i] = dist(gen);
        }
    }

    void findMinMax()
    {
        minval = arr[0];
        maxval = arr[0];

        auto start = high_resolution_clock::now();

        for (int i = 1; i < n; i++)
        {
            if (arr[i] < minval)
                minval = arr[i];

            else if (arr[i] > maxval)
                maxval = arr[i];
        }

        auto end = high_resolution_clock::now();

        auto timeTaken =
            duration_cast<microseconds>(end - start);

        cout << "\nMinimum value: " << minval << endl;
        cout << "Maximum value: " << maxval << endl;

        cout << "Execution Time: "
             << timeTaken.count()
             << " microseconds" << endl;
    }

    ~MinMax()
    {
        delete[] arr;
    }
};

int main()
{
    MinMax obj;

    obj.input();

    obj.findMinMax();

    return 0;
}