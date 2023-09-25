#include <string>
#include <map>

std::string numberToWords(int num)
{
    std::string result = "";
    std::map<int, std::string> nums = {{0, ""},
                                       {1, "One"},
                                       {2, "Two"},
                                       {3, "Three"},
                                       {4, "Four"},
                                       {5, "Five"},
                                       {6, "Six"},
                                       {7, "Seven"},
                                       {8, "Eight"},
                                       {9, "Nine"},
                                       {10, "Ten"},
                                       {11, "Eleven"},
                                       {12, "Twelve"},
                                       {13, "Thirteen"},
                                       {14, "Fourteen"},
                                       {15, "Fifteen"},
                                       {16, "Sixteen"},
                                       {17, "Seventeen"},
                                       {18, "Eighteen"},
                                       {19, "Nineteen"},
                                       {20, "Twenty"},
                                       {30, "Thirty"},
                                       {40, "Fourty"},
                                       {50, "Fifty"},
                                       {60, "Sixty"},
                                       {70, "Seventy"},
                                       {80, "Eighty"},
                                       {90, "Ninety"},
                                       {100, "Hundred"},
                                       {1000, "Thousand"},
                                       {1000000, "Million"},
                                       {1000000000, "Billion"}};
    int size = 0;
    int n = num;
    do
    {
        size++;
        n /= 10;
    } while (n > 0);
    if (num / 1000000000 != 0)
    {
        result += nums[num / 1000000000] + "Billion";
    }
    if ((num / 1000000) % 1000 != 0)
    {
        int n1000 = (num % 1000000000) / 1000000;
        if ((n1000 % 1000) / 100 != 0)
            result += nums[(n1000 % 1000) / 100] + "Hundred";
        if (n1000 % 100 < 20)
            result += nums[n1000 % 100];
        else
        {
            if ((n1000 % 100) / 10 != 0)
                result += nums[((n1000 % 100) / 10) * 10];
            if (n1000 % 10 != 0)
                result += nums[n1000 % 10];
        }
        result += "Million";
    }
    if ((num / 1000) % 1000 != 0)
    {
        int n1000 = (num % 1000000) / 1000;
        if ((n1000 % 1000) / 100 != 0)
            result += nums[(n1000 % 1000) / 100] + "Hundred";
        if (n1000 % 100 < 20)
            result += nums[n1000 % 100];
        else
        {
            if ((n1000 % 100) / 10 != 0)
                result += nums[((n1000 % 100) / 10) * 10];
            if (n1000 % 10 != 0)
                result += nums[n1000 % 10];
        }
        result += "Thousand";
    }
    if ((num % 1000) / 100 != 0)
        result += nums[(num % 1000) / 100] + "Hundred";
    if (num % 100 < 20)
        result += nums[num % 100];
    else
    {
        if ((num % 100) / 10 != 0)
            result += nums[((num % 100) / 10) * 10];
        if (num % 10 != 0)
            result += nums[num % 10];
    }
    bool flag = false;
    for (int i = 0; i < result.size(); i++)
    {
        if (result[i] >= 'A' && result[i] <= 'Z')
        {
            if (flag)
            {
                result.insert(i, 1, ' ');
                i++;
            }
            else
                flag = true;
        }
    }
    return result;
}

int main()
{
    std::string k = numberToWords(1233232525);
    k = k;
}