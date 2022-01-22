
import java.util.Queue;
import java.util.LinkedList;

public class Solution {

    public TreeNode findNearestRightNode(TreeNode root, TreeNode ancor) {
        
        if (root == null) {
            return null;
        }
        
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            int nodesCurrentInLevel = queue.size();
            while (nodesCurrentInLevel-- > 0) {

                TreeNode node = queue.poll();
                if (node == ancor) {
                    return nodesCurrentInLevel > 0 ? queue.poll() : null;
                }

                if (node.left != null) {
                    queue.add(node.left);
                }
                if (node.right != null) {
                    queue.add(node.right);
                }
            }
        }
        return null;
    }
}

class TreeNode {

    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
