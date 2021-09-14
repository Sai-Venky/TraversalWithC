// https://leetcode.com/problems/my-calendar-i


/*
    Note the use of set here and in map ->first part and decrement part.
    class MyCalendar {
        set<pair<int, int>> books;
    public:
        bool book(int s, int e) {
            auto next = books.lower_bound({s, e}); // first element with key not go before k (i.e., either it is equivalent or goes after).
            if (next != books.end() && next->first < e) return false; // a existing book started within the new book (next)
            if (next != books.begin() && s < (--next)->second) return false; // new book started within a existing book (prev)
            books.insert({ s, e });
            return true;
        }
    };
*/

class MyCalendar {
public:
    map<int, int> m; 
    MyCalendar() {
    }
    
    bool book(int start, int end) {
      
      auto itr=m.lower_bound(start);
      
      if(itr!=m.end() && itr->first < end) return false;
      if(itr!=m.begin() && (--itr)->second>start) return false;
      
      m[start]=end;
      return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

