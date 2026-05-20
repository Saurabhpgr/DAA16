#include <iostream>
#include <string>
using namespace std;

class StringPermutation
{
    private:
        string str;

        bool isValid(string s)
        {
            for (char c : s)
            {
                if (!isalpha(c))
                    return false;
            }
            return true;
        }

        void swapChar(char &a, char &b)
        {
            char temp = a;
            a = b;
            b = temp;
        }

        void permute(string &s, int left, int right)
        {
            if (left == right)
            {
                cout << s << endl;
                return;
            }

            for (int i = left; i <= right; i++)
            {
                swapChar(s[left], s[i]);          
                permute(s, left + 1, right);      
                swapChar(s[left], s[i]);          
            }
        }

    public:
        void input()
        {
            while (true)
            {
                cout << "Enter a string (only alphabets): ";
                cin >> str;

                if (str.empty())
                {
                    cout << "String cannot be empty! Try again.\n";
                    continue;
                }

                if (!isValid(str))
                {
                    cout << "Invalid input! Only alphabets allowed.\n";
                    continue;
                }

                break;
            }
        }

        void generate()
        {
            cout << "\nPermutations are:\n";
            permute(str, 0, str.length() - 1);
        }
};

int main()
{
    StringPermutation sp;
    sp.input();
    sp.generate();
    return 0;
}