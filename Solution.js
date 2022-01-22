
function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val);
    this.left = (left === undefined ? null : left);
    this.right = (right === undefined ? null : right);
}

/**
 * @param {TreeNode} root
 * @param {TreeNode} ancor
 * @return {TreeNode}
 */
var findNearestRightNode = function (root, ancor) {

    if (root === null) {
        return null;
    }

    const queue = new Queue();
    queue.enqueue(root);

    while (!queue.isEmpty()) {
        let nodesCurrentInLevel = queue.size();
        while (nodesCurrentInLevel-- > 0) {

            const node = queue.dequeue();
            if (node === ancor) {
                return nodesCurrentInLevel > 0 ? queue.dequeue() : null;
            }

            if (node.left !== null) {
                queue.enqueue(node.left);
            }
            if (node.right !== null) {
                queue.enqueue(node.right);
            }
        }
    }
    return null;
};
