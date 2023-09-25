#include <vector>
#include <iostream>

int maxSequence(const std::vector<int> &arr)
{
    int max = 0;
    int tmax = 0;
    for (int size = arr.size(); size >= 1; size--)
    {
        for (int start = 0; start < arr.size() && start + size <= arr.size(); start++)
        {
            for (int i = start; i < start + size; i++)
            {
                tmax += arr[i];
            }
            max = (tmax > max) ? tmax : max;
            tmax = 0;
        }
    }
    return max;
}

int main()
{
    std::cout << maxSequence({-2, 1, -3, 4, -1, 2, 1, -2, 4}) << "\n";
}