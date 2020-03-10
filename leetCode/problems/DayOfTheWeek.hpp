// https://leetcode.com/problems/day-of-the-week/submissions/
class Solution {
private:
    int getDayNumber(int dd,int mm,int yy){
        static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
        yy -= mm < 3;
        return (yy + yy/4 - yy/100 + yy/400 + t[mm-1] + dd) % 7;
    }
public:
    string dayOfTheWeek(int day, int month, int year) {
        string days[] = {
            "Sunday",
            "Monday",
            "Tuesday",
            "Wednesday",
            "Thursday",
            "Friday",
            "Saturday",
        };
        
        return days[getDayNumber(day, month, year)];
    }
};
