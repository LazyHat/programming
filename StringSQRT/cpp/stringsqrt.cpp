
#include <string>

std::string sum_strings(const std::string &a, const std::string &b)
{
    std::string sum;
    bool nextd = false;
    int temp;
    int subsize = a.size() - b.size();
    if (subsize > 0)
    {
        for (int i = a.size() - 1; i >= 0; i--)
        {
            temp = (a[i] - 48) + nextd;
            nextd = false;
            if (i - subsize >= 0)
            {
                temp += (b[i - subsize] - 48);
                if (temp > 9)
                {
                    sum = char((temp - 10) + 48) + sum;
                    nextd = true;
                }
                else
                {
                    sum = char((temp + 48)) + sum;
                }
            }
            else
            {
                if (temp > 9)
                {
                    sum = char((temp - 10) + 48) + sum;
                    nextd = true;
                }
                else
                {
                    sum = char((temp + 48)) + sum;
                }
            }
        }
    }
    else
    {
        for (int i = b.size() - 1; i >= 0; i--)
        {
            temp = (b[i] - 48) + nextd;
            nextd = false;
            if (i + subsize >= 0)
            {
                temp += (a[i + subsize] - 48);
                if (temp > 9)
                {
                    sum = char((temp - 10) + 48) + sum;
                    nextd = true;
                }
                else
                {
                    sum = char((temp + 48)) + sum;
                }
            }
            else
            {
                if (temp > 9)
                {
                    sum = char((temp - 10) + 48) + sum;
                    nextd = true;
                }
                else
                {
                    sum = char((temp + 48)) + sum;
                }
            }
        }
    }
    if (nextd == true)
    {
        sum = '1' + sum;
    }
    return sum;
}

std::string divide(std::string a, std::string b)
{
}

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

int main()
{
    int n = sqrt(63);
    n = n;
    std::string a = sum_strings("1245", "-1245");
    a = a;
}