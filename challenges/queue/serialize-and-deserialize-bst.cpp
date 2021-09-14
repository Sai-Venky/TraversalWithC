// https://leetcode.com/problems/serialize-and-deserialize-bst/

// note the use of istringstream here

class Codec {
  public:
    void serial(TreeNode* root, string &s) {
        if (root == NULL) return ;
        s += to_string(root->val) + " ";
        serial(root->left, s);
        serial(root->right, s);
    }
    TreeNode* deserial(queue<int> &q, int lo, int hi) {
        if (q.empty()) return NULL;
        int val = q.front();
        if (val < lo || val > hi) return NULL;
        TreeNode *root = new TreeNode(val);
        q.pop();
        root->left  = deserial(q, lo, val);
        root->right = deserial(q, val, hi);
        return root;
    }

    string serialize(TreeNode* root) {
        string s;
        serial(root, s);
        return s;
    }

    TreeNode* deserialize(string data) {
        istringstream iss(data);
        queue<int> q;
        string s;
        while (iss >> s) q.push(stoi(s));
        return deserial(q, INT_MIN, INT_MAX);
    }
};

// Note use of find here and then substr
/*
class Codec {
public:
    void serializehelper(TreeNode* root, string& s){
        if(root==nullptr) return;
        
        s+=to_string(root->val) + ","; // ',' for seperating each value
        serializehelper(root->left, s);
        serializehelper(root->right, s);
    }
    
    string serialize(TreeNode* root) {
        if(root==nullptr) return "";
        
        string s="";
        serializehelper(root, s);
        
        return s;
    }
    
    int convertStringtoInt(string& data, int& pos){ // Find ',' and return value
        pos=data.find(',');
        int value=stoi(data.substr(0, pos));
        return value;
    }
    
    TreeNode* deserializehelper(string& data, int min, int max) {
        if(data.size()==0) return nullptr; // If no more elements, return nullptr
        
        int pos=0;
        int value = convertStringtoInt(data, pos); // Find new value and position of ','
        if (value < min || value > max) return nullptr; // Is new value in given range
        
        TreeNode* tnode = new TreeNode(value); 
        data=data.substr(pos+1); // Update only when in range
        
        tnode->left=deserializehelper(data, min, tnode->val); // Branch off to left & right subtree with given ranges
        tnode->right=deserializehelper(data, tnode->val, max);
        return tnode;
    }
    
    TreeNode* deserialize(string data) {
        if(data=="") return nullptr;
        return deserializehelper(data, INT_MIN, INT_MAX);
    }
};
*/