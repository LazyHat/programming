#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string r = strs[0];
    for (auto it = strs.begin(); it != strs.end(); it++)
    {
        if (r.size() > it->size())
            r = *it;
    }
m1:
    for (auto it = strs.begin(); it != strs.end(); it++)
    {
        if (it->substr(0, r.size()) != r)
        {
            r.pop_back();
            goto m1;
        }
    }
    return r;
}

int main()
{
    vector<string> k = {"sdl", "s", "sdsdsg"};

    string res = longestCommonPrefix(k);
    return 0;
}