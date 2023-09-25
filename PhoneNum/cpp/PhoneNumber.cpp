#include <string>

std::string createPhoneNumber(const int arr[10])
{
    char buf[15];
    snprintf(buf, 15, "(%d%d%d) %d%d%d-%d%d%d%d", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8], arr[9]);
    return buf;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    std::string k = createPhoneNumber(arr);
    k = k;
}