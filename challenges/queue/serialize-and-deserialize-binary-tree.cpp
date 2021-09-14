// https://leetcode.com/problems/serialize-and-deserialize-binary-tree

/*
    Note the use of string stream here and logic of the 
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
      
      if(root==NULL) return "#";
      return to_string(root->val) + ',' + serialize(root->left) + ',' + serialize(root->right);
    }
  
    TreeNode* deserial(istringstream &iss) {
      string str;
      TreeNode* root=NULL;
      getline(iss, str, ',');
      if(str=="#") return root;
      else {
        root=new TreeNode(stoi(str));
        root->left=deserial(iss);
        root->right=deserial(iss);
      }
      return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
      istringstream iss(data);
      return deserial(iss);
    }
};

// See the ostringstream here

class Codec {
public:

    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }

private:

    void serialize(TreeNode* root, ostringstream& out) {
        if (root) {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out << "# ";
        }
    }

    TreeNode* deserialize(istringstream& in) {
        string val;
        in >> val;
        if (val == "#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};