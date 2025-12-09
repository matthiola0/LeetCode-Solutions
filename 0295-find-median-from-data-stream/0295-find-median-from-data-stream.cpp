class MedianFinder {
private:
    priority_queue<double> left;
    priority_queue<double, vector<double>, greater<double>> right;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if (left.size() == right.size()) {
            left.push(num);
            right.push(left.top());
            left.pop();
        } else {
            right.push(num);
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if (right.size() == 0) return 0.0;
        if (left.size() == right.size()) {
            return (right.top() + left.top()) / 2;
        }
        return right.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */