class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = true;
        for (auto itr = digits.rbegin();  itr != digits.rend();  ++itr)  {

            if(*itr == 9) {
                carry = true;
                *itr = 0;
            } else {
                *itr = *itr + 1;
                carry = false;
            }
            if(carry == false) {
                break;
            }
        }
        if(carry == true) {
            digits.emplace(digits.begin(), 1);
        }
        return digits;
    }
};
    