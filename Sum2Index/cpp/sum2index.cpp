#include <vector>
#include <iostream>
using namespace std;
pair<size_t, size_t> two_sum(const vector<double> &numbers, double target)
{
    int temp;
    for (int i = 0; i < numbers.size(); i++)
    {
        temp = target - numbers[i];
        for (int f = 0; f < numbers.size(); f++)
        {
            if (numbers[f] == temp && f != i)
                return {i, f};
        }
    }
    return {0, 0};
}

int main()
{
    cout << two_sum({1, 2, 3, 4, 5}, 5).first << "," << two_sum({1, 2, 3, 4, 5}, 5).second << endl;
}