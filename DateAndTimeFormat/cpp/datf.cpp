#include <string>

std::string format_duration(int seconds)
{
    std::string result = "";
    int time[] = {0, 0, 0, 0, 0};
    std::string names[] = {"years", "days", "hours", "minutes", "seconds"};
    std::string names1[] = {"year", "day", "hour", "minute", "second"};
    if (seconds == 0)
        return "now";
    else
    {
        time[4] = seconds % 60;
        time[3] = (seconds / 60) % 60;
        time[2] = (seconds / 3600) % 24;
        time[1] = (seconds / 86400) % 365;
        time[0] = seconds / 31536000;
        int i = 4;
        int counter = 0;
        while (i >= 0)
        {
            if (time[i] != 0)
            {
                if (counter == 1)
                    result = " and " + result;
                else if (counter > 1)
                    result = ", " + result;
            }
            switch (time[i])
            {
            case 0:
                i--;
                continue;
            case 1:
                result = std::to_string(time[i]) + " " + names1[i] + result;
                counter++;
                i--;
                break;
            default:
                result = std::to_string(time[i]) + " " + names[i] + result;
                counter++;
                i--;
                break;
            }
        }
    }
    return result;
}

int main()
{
    std::string k = format_duration(22342);
    k = k;
}