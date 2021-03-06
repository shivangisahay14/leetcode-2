// Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
// For example,
//
// [2,3,4], the median is 3
//
// [2,3], the median is (2 + 3) / 2 = 2.5
//
// Design a data structure that supports the following two operations:
//
//
// 	void addNum(int num) - Add a integer number from the data stream to the data structure.
// 	double findMedian() - Return the median of all elements so far.
//
//
//  
//
// Example:
//
//
// addNum(1)
// addNum(2)
// findMedian() -> 1.5
// addNum(3) 
// findMedian() -> 2
//
//
//  
//
// Follow up:
//
//
// 	If all integer numbers from the stream are between 0 and 100, how would you optimize it?
// 	If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?
//
//


class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        left.push(num);
        if (left.size() - right.size()>0) {
            //if(left.top)
            right.push(left.top());
            left.pop();
        }
        else
        {
            if(left.top()>right.top())
            {               
                left.push(right.top());
                right.pop();
                right.push(left.top());
                left.pop();
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        return left.size() < right.size() ? right.top() : 0.5 *(left.top()+ right.top());
    }

private:
    priority_queue<int> left;
    priority_queue<int,std::vector<int>,greater<int>> right;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
