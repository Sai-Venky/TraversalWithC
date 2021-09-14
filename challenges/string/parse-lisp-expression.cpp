// https://leetcode.com/problems/parse-lisp-expression/

// Note the traversal with recursion. IMP question to understand

class Solution {
public:
  int evaluate(string expression) {
    int i = 0;
    unordered_map<string, int> m;
    return parse(expression, expression.size(), i, m);
  }

  int parse(string& s, int n, int& i, unordered_map<string, int> m) {
    int res = 0;
    if (s[i] == '(') ++i;
    if (s.substr(i, 3) == "add") { // add expr
      i += 4;
      int left = parse(s, n, i, m);
      ++i;
      int right = parse(s, n, i, m);
      res = left + right;
    } else if (s.substr(i, 4) == "mult") { // mult expr
      i += 5;
      int left = parse(s, n, i, m);
      ++i;
      int right = parse(s, n, i, m);
      res = left * right;
    } else if (s.substr(i, 3) == "let") { // let expr
      i += 4;
      while (i < n && s[i] != ')') {
        string var;
        if (isalpha(s[i])) while (i < n && isalnum(s[i])) var += s[i++];
        else { res = parse(s, n, i, m); break; }
        if (s[i] == ' ') {
          ++i;
          m[var] = parse(s, n, i, m);
          ++i;
        } else if (s[i] == ')') res = m[var];
      }
    } else if (isalpha(s[i])) { // assigned expr
      string var;
      while (i < n && isalnum(s[i])) var += s[i++];
      res = m[var];
    } else { // integer expr
      int sign = 1;
      if (s[i] == '-') { sign = -1; ++i; }
      while (i < n && isdigit(s[i])) res = res*10 + s[i++]-'0';
      res *= sign;
    }
    if (s[i] == ')') ++i;
    return res;
  }
};