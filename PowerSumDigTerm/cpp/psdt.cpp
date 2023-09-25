#include <iostream>
#include <list>

unsigned long power(unsigned long num, unsigned long pow)
{
    if (pow <= 1)
        return num;
    else
        return num * power(num, pow - 1);
}
unsigned int size(unsigned long num)
{
    int size = 0;
    do
    {
        size++;
        num /= 10;
    } while (num > 0);
    return size;
}
unsigned int sumdigits(unsigned long num)
{
    int sum = 0;
    do
    {
        sum += num % 10;
        num /= 10;
    } while (num > 0);
    return sum;
}
unsigned long powerSumDigTerm(unsigned int n)
{
    std::list<unsigned long> arr = {81};
    unsigned long p;
    unsigned long bp;
    for (unsigned long i = 7; i < 181; i++)
    {
        bp = 1;
        for (int j = 1; j < 32; j++)
        {
            p = power(i, j);
            if (p / bp != i)
                break;
            if (sumdigits(p) == i && size(p) > 1)
            {
                if (*(--arr.end()) < p)
                {
                    arr.push_back(p);
                }
                else if (*(arr.begin()) > p)
                {
                    arr.push_front(p);
                }
                else
                {
                    for (auto k = arr.begin(); k != arr.end(); k++)
                    {
                        if (p == *k)
                            break;
                        else if (p < *k)
                        {
                            arr.insert(k, p);
                            break;
                        }
                    }
                }
            }
            bp = p;
        }
    }
    auto it = arr.begin();
    std::advance(it, n - 1);
    return *it;
}

int main()
{
    unsigned long z = powerSumDigTerm(30);
    z = z;
    return z;
}