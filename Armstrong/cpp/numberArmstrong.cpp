#include <iostream>
using namespace std;
int pow(int num, int power)
{
    if (power < 0)
        return 0;
    if (num == 1 || power == 0)
        return 1;
    if (power == 1)
        return num;
    else
        return num * pow(num, power - 1);
}
bool n(int value)
{
    int val = value;
    int size = 0;
    do
    {
        val /= 10;
        size++;
    } while (val != 0);
    for (int i = size - 1; i >= 0; i--)
    {
        val += pow((value / pow(10, i)) % 10, size);
    }
    return val == value;
}
int main()
{
    cout << n(7) << endl;
    cout << n(371) << endl;
    cout << n(122) << endl;
    cout << n(4887) << endl;
}