// https://leetcode.com/problems/design-an-ordered-stream/

// SF

class OrderedStream {
public:
    int track=1;
    vector<string> arr;
    OrderedStream(int n) {
      arr.assign(n+1, "");
    }
    
    vector<string> insert(int idKey, string value) {
      vector<string> out;
      
      arr[idKey] = value;
      
      while(track<arr.size() && arr[track] != "") {
        out.push_back(arr[track++]);
      }
      return out;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */