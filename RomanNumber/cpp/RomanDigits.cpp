#include <string>

int powt(unsigned int pow)
{
    if (pow <= 1)
        return 10;
    else
        return 10 * powt(pow - 1);
}
std::string multiply(const std::string s, unsigned int mult)
{
    std::string k = "";
    for (int i = 0; i < mult; i++)
    {
        k += s;
    }
    return k;
}
std::string roman(unsigned int num, const std::string r1, const std::string r5, const std::string r10)
{
    if (num % 10 <= 3)
    {
        return multiply(r1, num);
    }
    else if (num % 10 == 4)
    {
        return r1 + r5;
    }
    else if (num % 10 >= 5 && num % 10 <= 8)
    {
        return r5 + multiply(r1, num - 5);
    }
    else if (num % 10 == 9)
    {
        return r1 + r10;
    }
    else
    {
        return r10;
    }
}
class RomanHelper
{
public:
    std::string to_roman(int num)
    {
        int size = 0;
        unsigned int n = num;
        do
        {
            n /= 10;
            size++;
        } while (n != 0);
        std::string s = "";
        for (int i = ((size > 4) ? 4 : size); i >= 1; i--)
        {
            switch (i)
            {
            case 4:
                s += multiply("M", num / powt(3));
                break;
            case 3:
                s += roman((num / powt(2)) % 10, "C", "D", "M");
                break;
            case 2:
                s += roman((num / powt(1)) % 10, "X", "L", "C");
                break;
            case 1:
                s += roman(num % 10, "I", "V", "X");
                break;
            }
        }
        return s;
    }
    int from_roman(std::string rn)
    {
        int res = 0;
        for (int i = 0; i < rn.size(); i++)
        {
            switch (rn[i])
            {
            case 'C':
                if (rn[i + 1] == 'M')
                {
                    res += 900;
                    i++;
                }
                else if (rn[i + 1] == 'D')
                {
                    res += 400;
                    i++;
                }
                else
                    res += 100;
                break;
            case 'X':
                if (rn[i + 1] == 'C')
                {
                    res += 90;
                    i++;
                }
                else if (rn[i + 1] == 'L')
                {
                    res += 40;
                    i++;
                }
                else
                    res += 10;
                break;
            case 'I':
                if (rn[i + 1] == 'X')
                {
                    res += 9;
                    i++;
                }
                else if (rn[i + 1] == 'V')
                {
                    res += 4;
                    i++;
                }
                else
                    res += 1;
                break;
            default:
                switch (rn[i])
                {
                case 'M':
                    res += 1000;
                    break;
                case 'D':
                    res += 500;
                    break;
                case 'L':
                    res += 50;
                    break;
                case 'V':
                    res += 5;
                    break;
                }
                break;
            }
        }
        return res;
    }
} RomanNumerals;

int main()
{
    int o = 99;
    int k;
    k = RomanNumerals.from_roman(RomanNumerals.to_roman(o));
    k = k;
}