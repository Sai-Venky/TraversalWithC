// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string

/*
  Logic - SF. Note trick how push and pop is toggled to ensure duplicates are not inserted also.
  Code - Stack
 */

string removeDuplicates(string S) {
    string res = "";
    for (char& c : S)
        if (res.size() && c == res.back())
            res.pop_back();
        else
            res.push_back(c);
    return res;
}