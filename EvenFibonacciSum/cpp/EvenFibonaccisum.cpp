unsigned long long fibonacci(unsigned long long max)
{
    unsigned long long i = 1, k = 0, t = 0, sum = 0;
    do
    {
        k = i;
        i = t;
        sum += (i % 2 == 0) ? i : 0;
        t = i + k;
    } while (t < max);
    return sum;
}

int main()
{
    unsigned long long k = fibonacci(33);
    k = k;
}