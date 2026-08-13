/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        
        List<List<Integer>> ans = new ArrayList<>();

        List<Integer> path = new ArrayList<>();
        
                findPath(root, targetSum, path, ans);

        return ans;
    }

    public void findPath(TreeNode root, int targetSum,List<Integer> path,
            List<List<Integer>> ans) {

        if (root == null) {
            return;
        }

        path.add(root.val);

        if (root.left == null && root.right == null &&
            targetSum == root.val) {

            ans.add(new ArrayList<>(path));
        }

        findPath(root.left, targetSum - root.val, path, ans);
        findPath(root.right, targetSum - root.val, path, ans);

        path.remove(path.size() - 1);
    }
}