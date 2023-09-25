#include <string>
using namespace std;

bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    if (x / 10 == 0)
        return true;
    uint8_t size = 0;
    int n = x;
    while (n > 0)
    {
        size++;
        n /= 10;
    }
    uint8_t *arr = new uint8_t[size];
    for (uint8_t i = 0; i < size; i++)
    {
        arr[i] = x % 10;
        x /= 10;
    }
    for (uint8_t i = 0; i < size; i++)
    {
        if (arr[i] != arr[size - 1 - i])
        {
            delete[] arr;
            return false;
        }
    }
    delete[] arr;
    return true;
}

int main()
{
    auto num = 1234554321;
    auto result = isPalindrome(num);
    return 0;
}