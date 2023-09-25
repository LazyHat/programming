#include <numstring.h>

bool check_to_digits(const std::string &k)
{
    for (auto &&i : k)
        if (!(i < '9' && i > '0'))
            return false;
    return true;
}

numstring::numstring(std::string n)
{
    if (!check_to_digits)
        throw numstringexception();
    else
        this->value = n;
}

void add_zeros_front(std::string &a, uint64_t count_zeros);
void subtact_strings(std::string &a, std::string &b, std::string &res);
void sum_strings(std::string &a, std::string &b, std::string &res);

numstring numstring::operator+(numstring other)
{
    std::string res;
    bool am = false, bm = false;
    if (this->value[0] == '-')
    {
        this->value = this->value.substr(1);
        am = true;
    }
    if (other.value[0] == '-')
    {
        other.value = other.value.substr(1);
        bm = true;
    }
    if (am && bm)
    {
        sum_strings(this->value, other.value, res);
        res = '-' + res;
    }
    else if (am)
        subtact_strings(b, a, res);
    else if (bm)
        subtact_strings(a, b, res);
    else
        sum_strings(a, b, res);
}

/// @brief sum strings
/// @param a first operand
/// @param b second operand
/// @param res = a+b
void sum_strings(std::string &a, std::string &b, std::string &res)
{
    res = "";
    bool nextdigit = false;
    if (a.size() > b.size())
        add_zeros_front(b, a.size() - b.size());
    else
        add_zeros_front(a, b.size() - a.size());
    add_zeros_front(res, a.size());
    for (uint64_t i = a.size(); i > 0; i--)
    {
        char r = res[i - 1] + a[i - 1] + b[i - 1] - ('0' * 2);
        if (r > '9')
        {
            r = r - 10;
            if (i == 1)
                nextdigit = true;
            else
                res[i - 2]++;
        }
        res[i - 1] = r;
    }
    if (nextdigit)
        res = '1' + res;
}

/// @brief subtact strings
/// @param a first operand
/// @param b second operand
/// @param res = a-b
void subtact_strings(std::string &a, std::string &b, std::string &res)
{
    res = "";
    bool nextdigit = false;
    if (a.size() > b.size())
        add_zeros_front(b, a.size() - b.size());
    else
        add_zeros_front(a, b.size() - a.size());
    add_zeros_front(res, a.size());
    for (uint64_t i = a.size(); i > 0; i--)
    {
        char r = res[i - 1] + a[i - 1] - b[i - 1];
        if (r < '0')
        {
            r = r + 10;
            if (i == 1)
                nextdigit = true;
            else
                res[i - 2]--;
        }
        res[i - 1] = r;
    }
    while (true)
    {
        if (res[0] == '0')
            res = res.substr(1);
        else
            break;
    }
    if (nextdigit)
    {
        subtact_strings(b, a, res);
        res = '-' + res;
    }
}

void add_zeros_front(std::string &a, uint64_t count_zeros)
{
    for (uint64_t i = 0; i < count_zeros; i++)
    {
        a = '0' + a;
    }
}