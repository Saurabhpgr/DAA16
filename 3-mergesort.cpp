#include <iostream>
#include <thread>
#include <random>
using namespace std;

class MergeSort
{
    int *arr;
    int n;

    public:
        MergeSort(int size)
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

        void merge(int left, int mid, int right)
        {
            int n1 = mid - left + 1;
            int n2 = right - mid;

            int *L = new int[n1];
            int *R = new int[n2];

            for(int i = 0; i < n1; i++)
                L[i] = arr[left + i];

            for(int j = 0; j < n2; j++)
                R[j] = arr[mid + 1 + j];

            int i = 0, j = 0, k = left;

            while(i < n1 && j < n2)
            {
                if(L[i] < R[j])
                    arr[k++] = L[i++];
                else
                    arr[k++] = R[j++];
            }

            while(i < n1)
                arr[k++] = L[i++];

            while(j < n2)
                arr[k++] = R[j++];

            delete[] L;
            delete[] R;
        }

        void mergeSort(int left, int right)
        {
            if(left >= right)
                return;

            int mid = (left + right) / 2;

            thread t1(mergeSort, this, left, mid);
            thread t2(mergeSort, this, mid + 1, right); 

            t1.join();
            t2.join();

            merge(left, mid, right);
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

    MergeSort obj(n);

    obj.generateRandom();

    cout << "\nGenerated elements:\n";
    obj.display();

    obj.mergeSort(0, n-1);

    cout << "\nElements after Merge Sort:\n";
    obj.display();

    return 0;
}