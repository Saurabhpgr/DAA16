#include <iostream>
#include <vector>
using namespace std;

class Fibonacci
{
    private:
        int n;
        vector<long long> dp;

    public:
        void input()
        {
            const int LOWER = 0;
            const int UPPER = 45;

            while (true)
            {
                cout << "Enter n : ";

                if (!(cin >> n))
                {
                    cout << "Invalid Input!" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }

                if (n < LOWER || n > UPPER)
                {
                    cout << "Enter between " << LOWER << " and " << UPPER << endl;
                    continue;
                }

                break;
            }

            dp.resize(n + 1, -1);
        }

        long long fibo(int i)
        {
            if (i <= 1)
                return dp[i] = i;

            if (dp[i] != -1)
                return dp[i];

            return dp[i] = fibo(i - 1) + fibo(i - 2);
        }

        void printResult()
        {
            cout << "\nNth Fibonacci number is: " << fibo(n) << endl;
        }
};

int main()
{
    Fibonacci obj;
    obj.input();
    obj.printResult();
    return 0;
}