class ASum
{
public:
    static long long findNb(long long m)
    {
        long long k = 0;
        while (true)
        {
            k++;
            m -= k * k * k;
            if (m == 0)
                return k;
            else if (m < 0)
                return -1;
        }
    }
};

int main()
{
    ASum as;
    long long l = 4183059834009;
    l = as.findNb(l);
    return l;
}
