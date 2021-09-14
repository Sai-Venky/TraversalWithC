// https://leetcode.com/problems/flatten-nested-list-iterator

// Note the use of iterators here to store the bginning and ends

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        begins.push(nestedList.begin());
        ends.push(nestedList.end());
    }

    int next() {
        return (begins.top()++)->getInteger();
    }

    bool hasNext() {
        while (begins.size()) {
            if (begins.top() == ends.top()) {
                begins.pop();
                ends.pop();
            } else {
                auto x = begins.top();
                if (x->isInteger())
                    return true;
                begins.top()++;
                begins.push(x->getList().begin());
                ends.push(x->getList().end());
            }
        }
        return false;
    }

private:
    stack<vector<NestedInteger>::iterator> begins, ends;
};

// with pointers 
/* Note that start and end can have element reference also
NestedIterator(vector<NestedInteger> &nestedList) {
        Start.push(&nestedList[0]);
        End.push(&nestedList[nestedList.size()-1]);
    }
/*

class NestedIterator {
public:
    stack<NestedInteger*> Start, End; // stores pointer to start & end of nested lists
    NestedIterator(vector<NestedInteger> &nestedList) {
        Start.push(&nestedList.front());
        End.push(&nestedList.back());
    }
    // will only return the next integer and increment the pointer on top of stack
    int next() {
        return Start.top()++ -> getInteger();
    }
    // Returns true only if there's more integer(s) yet to be traversed
	// If there are next integers, this function also ensures the stack top points to it
	// when size of stack becomes 0, we have traversed all of nestedList
    bool hasNext() {  
        while(size(Start)){
            auto top = Start.top();            
            if(Start.top() > End.top()){ // when a list is completely traversed
                Start.pop(), End.pop();
                continue;
            }                            
            if(top -> isInteger()) break;            
            Start.top()++;
            if(!size(top -> getList())) continue;
            Start.push(&top -> getList().front());  
            End.push(&top -> getList().back());
        }
        return size(Start);
    }
};