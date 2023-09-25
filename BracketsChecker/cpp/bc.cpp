#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid(string s)
{
    string st;
    for (auto &c : s)
    {
        switch (c)
        {
        case '}':
            if (st.size() != 0 && *(--st.end()) == '{')
                st.pop_back();
            else
                return false;
            break;
        case ']':
            if (st.size() != 0 && *(--st.end()) == '[')
                st.pop_back();
            else
                return false;
            break;
        case ')':
            if (st.size() != 0 && *(--st.end()) == '(')
                st.pop_back();
            else
                return false;
            break;
        default:
            st.push_back(c);
        }
    }
    return st.size() == 0;
}

int main()
{
    string s;
    getline(cin, s);
    cout << (bool)isValid(s) << endl;
}
