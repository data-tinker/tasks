class MyCalendarThree {
private:
    map<int, int> pointsToTimes;
public:
    MyCalendarThree() {
    }

    int book(int start, int end) {
        ++pointsToTimes[start];
        --pointsToTimes[end];
        int booked = 0;
        int maxBooked = numeric_limits<int>::min();

        for (const auto& pointToTimes : pointsToTimes) {
            booked += pointToTimes.second;
            maxBooked = max(maxBooked, booked);
        }

        return maxBooked;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
