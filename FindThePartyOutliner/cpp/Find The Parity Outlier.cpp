#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
int find(std::vector<int> arr)
{
    int result;
    int k = 0;
    bool flag = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (!(arr[i] % 2 != 0))
        {
            k++;
        }
        if (arr[i] % 2 != 0)
        {
            result = arr[i];
            flag = !flag;
        }
        if (k > 1 && flag)
        {
            return result;
        }
        if (i > 0 && k < 1)
        {
            break;
        }
    }
    k = 0;
    flag = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] % 2 != 0)
        {
            k++;
        }
        if (!(arr[i] % 2 != 0))
        {
            result = arr[i];
            flag = !flag;
        }
        if (k > 1 && flag)
        {
            return result;
        }
        if (i > 0 && k < 1)
        {
            break;
        }
    }
}

int main()
{
    vector<int> arr = {16458, 9075, 10397, 827, 4741, -8431, -2161, 4843, -7351, -7369};
    cout << find(arr) << endl;
}