Facebook Question

/*

    Given a list of N triangles with integer side lengths, determine how many different triangles there are. 
    Two triangles are considered to be the same if they can both be placed on the plane such that their vertices occupy exactly the same three points.

    Example 1
    arr = [[2, 2, 3], [3, 2, 2], [2, 5, 6]]
    output = 2
    The first two triangles are the same, so there are only 2 distinct triangles.
    Example 2
    arr = [[8, 4, 6], [100, 101, 102], [84, 93, 173]]
    output = 3
    All of these triangles are distinct.
    Example 3
    arr = [[5, 8, 9], [5, 9, 8], [9, 5, 8], [9, 8, 5], [8, 9, 5], [8, 5, 9]]
    output = 1
    All of these triangles are the same.

*/

struct sides{
  long long a;
  long long b;
  long long c;
};

// Add any helper functions you may need here

int countDistinctTriangles(vector <sides> arr) {
  // Write your code here
  unordered_set<string> s;
  for(auto v:arr) {
    vector<long long> sideArray{v.a, v.b, v.c};
    sort(sideArray.begin(), sideArray.end());
    string str = to_string(sideArray[0]) + to_string(sideArray[1]) + to_string(sideArray[2]);
    if(s.count(str)>0) continue;
    s.insert(str);
  }
  return s.size();
}
