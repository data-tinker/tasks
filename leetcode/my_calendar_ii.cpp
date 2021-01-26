class MyCalendarTwo {
private:
    map<int, int> pointsToTimes;
public:
    MyCalendarTwo() {
    }

    bool book(int start, int end) {
        ++pointsToTimes[start];
        --pointsToTimes[end];
        int booked = 0;

        for (const auto& pointToTimes : pointsToTimes) {
            booked += pointToTimes.second;
            if (booked == 3) {
                --pointsToTimes[start];
                ++pointsToTimes[end];
                return false;
            }
        }

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
