class Solution {
public:
    
    int daysFromEpoch(string date) {
        static const int monthDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int y = stoi(date.substr(0,4));
        int m = stoi(date.substr(5,2));
        int days = stoi(date.substr(8,2));
        for (int i = 0; i < m - 1; ++i)
            days += monthDays[i];
        if (m > 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))) days += 1;
        days += 365 * y + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400;
        return days;
    }
    int daysBetweenDates(string date1, string date2) {
        return abs(daysFromEpoch(date1) - daysFromEpoch(date2));
    }
};