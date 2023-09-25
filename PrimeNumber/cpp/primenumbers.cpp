#include <iostream>

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

int sqrt(int num)
{
    int answer = 0;
    int num2 = num;
    int size = 0;
    do
    {
        num2 /= 100;
        size += 2;
    } while (num2 != 0);
    int temp = 0;
    int flag = 1;
    for (int i = 0; i <= size - 2; i += 2)
    {
        temp += num / pow(10, size - i - 2);
        num %= pow(10, size - i - 2);
        for (int j = 9; j >= 0; j--)
        {
            if ((answer * 2 * 10 + j) * j <= temp)
            {
                temp = (temp - (answer * 2 * 10 + j) * j) * 100;
                if (flag == 2)
                {
                    answer *= 10;
                    answer += j;
                }
                else
                {
                    answer += j;
                }
                flag = 2;
                break;
            }
        }
    }
    return answer;
}

bool isprime(int num)
{
    if (num <= 0)
        return false;
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::cout << isprime(1) << std::endl;
    std::cout << isprime(3) << std::endl;
    std::cout << isprime(5) << std::endl;
    std::cout << isprime(29) << std::endl;
    std::cout << isprime(51) << std::endl;
    std::cout << isprime(49) << std::endl;
    std::cout << isprime(56) << std::endl;
    std::cout << isprime(11) << std::endl;
    std::cout << isprime(13) << std::endl;
}