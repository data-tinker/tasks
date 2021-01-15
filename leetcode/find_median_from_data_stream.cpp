class MedianFinder {
private:
    priority_queue<int> lowerHalf;
    priority_queue<int,  vector<int>, greater<int>> biggerHalf;

public:
    /** initialize your data structure here. */
    MedianFinder() {
    }

    void addNum(int num) {
        lowerHalf.push(num);
        biggerHalf.push(lowerHalf.top());
        lowerHalf.pop();

        if (lowerHalf.size() < biggerHalf.size()) {
            lowerHalf.push(biggerHalf.top());
            biggerHalf.pop();
        }
    }

    double findMedian() {
        if (lowerHalf.size() == biggerHalf.size()) {
            return (lowerHalf.top() + biggerHalf.top()) / 2.0;
        }

        return lowerHalf.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
