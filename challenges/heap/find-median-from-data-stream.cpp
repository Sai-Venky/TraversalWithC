// https://leetcode.com/problems/find-median-from-data-stream

// NOte the use of heap here to store hte 2 halfs and maintaining that in median calculations.
class MedianFinder {
private:
    priority_queue<int> firstQ; // max_heap for the first half
    priority_queue<int, std::vector<int>, std::greater<int> > secQ; // min_heap for the second half
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        if(firstQ.empty() || (firstQ.top()>num)) firstQ.push(num); // if it belongs to the smaller half
        else secQ.push(num); 
        
        // rebalance the two halfs to make sure the length difference is no larger than 1
        if(firstQ.size() > (secQ.size()+1))
        {
            secQ.push(firstQ.top());
            firstQ.pop();
        }
        else if(firstQ.size()+1<secQ.size())
        {
            firstQ.push(secQ.top());
            secQ.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if(firstQ.size() == secQ.size()) return firstQ.empty()?0:( (firstQ.top()+secQ.top())/2.0);
        else return (firstQ.size() > secQ.size())? firstQ.top():secQ.top(); 
    }
};

/*
If the range of the numbers is in [0...100], we use a bucket to collect the frequency of each number. By accumulating the frequency of elements in the bucket, we can know the median numbers.
	class MedianFinder {
        int A[] = new int[101], n = 0;
		
		// O(1)
        public void addNum(int num) {
            A[num]++;
            n++;
        }
		
		// O(100) = O(1)
        public double findMedian() {
		
			// find 1st median number
            int count = 0, i = 0;			
            while (count < n/2) count += A[i++];
			
			// find 2nd median number
            int j = i;
            while (count < n/2+1) count += A[j++];
			
            return (n%2 == 1) ? i : (i-1+j-1) / 2.0;
        }
    }
If 1% numbers are outside of the range [0...100], we know that when the set of numbers is large, the median numbers must be in the range of [0...100], because this range contains 99% numbers. We don't need to store values of 1% numbers, but the counts of these numbers (countLessZero & countGreater100). The findMedian method is almost the same, the difference is we start counting from countLessZero value
	class MedianFinder {
        int A[] = new int[101], n = 0;
		int countLessZero = 0;
		// int countGreater100 = 0; // not needed
		
		// O(1)
        public void addNum(int num) {
			if (num < 0) countLessZero++;
			// else if (num > 100) countGreater100++;
			else A[num]++;
            n++;
        }
		
		// O(100) = O(1)
        public double findMedian() {
		
			// find 1st median number
            int count = countLessZero, i = 0;			
            while (count < /2) count += A[i++];
			
			// find 2nd median number
            int j = i;
            while (count < n/2+1) count += A[j++];
			
            return (n%2 == 1) ? i : (i-1+j-1) / 2.0;
        }
    }
*/