
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }

    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {
    }
};

class Solution {
public:

    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* ancor) {
        if (root == nullptr) {
            return nullptr;
        }

        queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            int nodesCurrentInLevel = queue.size();
            while (nodesCurrentInLevel-- > 0) {

                TreeNode* node = queue.front();
                queue.pop();
                if (node == ancor) {
                    return nodesCurrentInLevel > 0 ? queue.front() : nullptr;
                }

                if (node->left != nullptr) {
                    queue.push(node->left);
                }
                if (node->right != nullptr) {
                    queue.push(node->right);
                }
            }
        }
        return nullptr;
    }
};
