class MedianFinder {

    priority_queue<int> s;
    priority_queue<int, vector<int>, greater<int>> l;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        s.push(num);
        if(!l.empty() && l.top() < s.top()) {
            l.push(s.top());
            s.pop();
        }

        if(l.size() + 1 < s.size()) {
            l.push(s.top());
            s.pop();
        }

        if(s.size() + 1 < l.size()) {
            s.push(l.top());
            l.pop();
        }
         
    }
    
    double findMedian() {
        if(s.size() == l.size()) return (s.top() + l.top()) / 2.0;
        else if(s.size() > l.size()) return s.top(); 
        else return l.top(); 
    }
};
