#include <iostream>
#include <thread>
#include <random>
using namespace std;

class QuickSort
{
    int *arr;
    int n;

    public:
        QuickSort(int size)
        {
            n = size;
            arr = new int[n];
        }

        void generateRandom()
        {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<int> dist(1, 100000);

            for(int i = 0; i < n; i++)
            {
                arr[i] = dist(gen);
            }
        }

        void display()
        {
            for(int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        int partition(int low, int high)
        {
            int pivot = arr[high];
            int i = low - 1;

            for(int j = low; j < high; j++)
            {
                if(arr[j] < pivot)
                {
                    i++;
                    swap(arr[i], arr[j]);
                }
            }

            swap(arr[i+1], arr[high]);
            return i+1;
        }

        void quickSort(int low, int high)
        {
            if(low >= high)
                return;

            int pi = partition(low, high);

            thread t1(quickSort, this, low, pi-1);
            thread t2(quickSort, this, pi+1, high);

            t1.join();
            t2.join();
        }
};

int main()
{
    int n;

    cout << "How many random numbers do you want to generate? ";

    while(!(cin >> n) || n <= 0)
    {
        cout << "Invalid input! Please enter a positive number: ";
        cin.clear();            
        cin.ignore(10000,'\n'); 
    }

    QuickSort obj(n);

    obj.generateRandom();

    cout << "\nGenerated elements:\n";
    obj.display();

    obj.quickSort(0, n-1);

    cout << "\nElements after Quick Sort:\n";
    obj.display();

    return 0;
}