// https://leetcode.com/problems/next-greater-element-iii/


/*
Think of these questions
Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.

    Logic - SF. Note the use of swap and REVERSE. Also they are coming from back since immediate dreater element
    Code - Stack
*/

class Solution {
public:
    int nextGreaterElement(int n) {
        string temp = to_string(n);
        stack<int> stk;
        int prev=0;
        for (int i=temp.size()-1;i>=0;i--){
            if (!stk.empty() && temp[i]<temp[stk.top()]){
            //find the next smallest number greater than the current element. 
            //swap these two numbers and reverse the later part to keep it minimum 
                while (!stk.empty() && temp[i]<temp[stk.top()]){  
                    prev = stk.top();
                    stk.pop();
                }
                swap(temp[i], temp[prev]);
                reverse(temp.begin()+i+1, temp.end());
                break;
            }
            stk.push(i);
        }
        
        long long res = stoll(temp);
        return (res>INT_MAX || (int)res==n)?-1:(int)res;
        
    }
};

/*
Steps
9 2 6 5 4
9 4 6 5 2
9 4 2 5 6
*/
