#include <string>

using namespace std;
string rot13(string msg)
{
    for (auto &&i : msg)
    {
        if (i >= 65 && i <= 90)
        {
            if (i >= 78)
                i -= 13;
            else
                i += 13;
        }
        else if (i >= 97 && i <= 122)
        {
            if (i >= 110)
                i -= 13;
            else
                i += 13;
        }
    }
    return msg;
}

int main()
{
    string k = rot13("test");
    k = k;
}