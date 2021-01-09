struct Interval {
    static int n;
    int start;
    int end;

    Interval(int start, int end)
        : start(start)
        , end(end)
    {}

    int getDistance() const {
        if (start == 0) {
            return end;
        } else if (end == n - 1) {
            return n - 1 - start;
        } else if (end < start) {
            return -1;
        }

        return (end - start) / 2;
    }

    int getPosition() {
        if (start == 0) {
            return 0;
        } else if (end == n - 1) {
            return n - 1;
        }

        return (start + end) / 2;
    }

    bool operator<(const Interval& other) const {
        int distance = getDistance();
        int distanceOther = other.getDistance();

        if (distance != distanceOther) {
            return distance > distanceOther;
        }

        return start < other.start;
    }
};

int Interval::n = 0;

class ExamRoom {
private:
    vector<int> takenSeats;
    set<Interval> intervals;
    unordered_map<int, int> startToEnd;
    unordered_map<int, int> endToStart;
    int n;

    int seatLog() {
        auto interval = *intervals.begin();
        intervals.erase(intervals.begin());

        int position = interval.getPosition();

        intervals.insert(Interval(interval.start, position - 1));
        intervals.insert(Interval(position + 1, interval.end));

        startToEnd[interval.start] = position - 1;
        endToStart[position - 1] = interval.start;

        startToEnd[position + 1] = interval.end;
        endToStart[interval.end] = position + 1;

        return position;
    }

    void leaveLog(int p) {
        int start = endToStart[p - 1];
        int end = startToEnd[p + 1];

        intervals.erase(Interval(start, p - 1));
        intervals.erase(Interval(p + 1, end));
        intervals.insert(Interval(start, end));

        startToEnd[start] = end;
        endToStart[end] = start;

        endToStart.erase(p - 1);
        startToEnd.erase(p + 1);
    }

    int seatN() {
        if (takenSeats.size() == 0) {
            takenSeats.push_back(0);
            return 0;
        }

        int d = max(takenSeats[0], n - 1 - takenSeats[takenSeats.size() - 1]);

        for (size_t i = 0; i < takenSeats.size() - 1; ++i) {
            d = max(d, (takenSeats[i + 1] - takenSeats[i]) / 2);
        }

        if (takenSeats[0] == d) {
            takenSeats.insert(takenSeats.begin(), 0);
            return 0;
        }

        for (size_t i = 0; i < takenSeats.size() - 1; ++i) {
            if ((takenSeats[i + 1] - takenSeats[i]) / 2 == d) {
                takenSeats.insert(takenSeats.begin() + i + 1, (takenSeats[i + 1] + takenSeats[i]) / 2);
                return takenSeats[i + 1];
            }
        }

        takenSeats.push_back(n - 1);
        return n - 1;
    }

    void leaveN(int p) {
        for (size_t i = 0; i < takenSeats.size(); ++i) {
            if (takenSeats[i] == p) {
                takenSeats.erase(takenSeats.begin() + i);
            }
        }
    }
public:
    ExamRoom(int N)
    : n(N)
    {
        Interval::n = n;
        intervals.clear();
        startToEnd.clear();
        endToStart.clear();

        intervals.insert(Interval(0, n - 1));

        startToEnd[0] = n - 1;
        endToStart[n - 1] = 0;
    }

    int seat() {
        return seatLog();
    }

    void leave(int p) {
        leaveLog(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
