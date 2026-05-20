#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

class Karatsuba
{
private:
    long long x, y;

public:
    void input()
    {
        while (true)
        {
            cout << "Enter first number: ";
            if (!(cin >> x))
            {
                cout << "Invalid input!\n";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            cout << "Enter second number: ";
            if (!(cin >> y))
            {
                cout << "Invalid input!\n";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            if (x != 0 && abs(y) > LLONG_MAX / abs(x))
            {
                cout << "Overflow! Enter smaller numbers.\n";
                continue;
            }

            break;
        }
    }

    int countDigits(long long num)
    {
        if (num == 0)
            return 1;

        int count = 0;
        while (num != 0)
        {
            count++;
            num /= 10;
        }
        return count;
    }

    long long karatsuba(long long x, long long y)
    {
        if (x < 10 || y < 10)
            return x * y;

        int n = max(countDigits(x), countDigits(y));
        int m = n / 2;

        long long power = pow(10, m);
        
        long long high1 = x / power;
        long long low1  = x - (high1 * power);

        long long high2 = y / power;
        long long low2  = y - (high2 * power);

        long long z0 = karatsuba(low1, low2);
        long long z1 = karatsuba((low1 + high1), (low2 + high2));
        long long z2 = karatsuba(high1, high2);

        return (z2 * pow(10, 2 * m)) + ((z1 - z2 - z0) * power) + z0;
    }

    void display()
    {
        long long result = karatsuba(x, y);
        cout << "Product using Karatsuba: " << result << endl;
    }
};

int main()
{
    Karatsuba obj;
    obj.input();
    obj.display();
    return 0;
}