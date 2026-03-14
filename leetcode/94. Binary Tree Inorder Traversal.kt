// https://leetcode.com/problems/binary-tree-inorder-traversal/description/

// Given the root of a binary tree, return the inorder traversal of its nodes' values.

// Example 1:
// Input: root = [1,null,2,3]
// Output: [1,3,2]

// Example 2:
// Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
// Output: [4,2,6,5,7,1,3,9,8]

// Example 3:
// Input: root = []
// Output: []

// Example 4:
// Input: root = [1]
// Output: [1]

// Constraints:
// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100

package task94

class TreeNode(var `val`: Int) {
    var left: TreeNode? = null
    var right: TreeNode? = null
}

class Solution {
    fun inorderTraversalRecursive(root: TreeNode?): List<Int> {
        val result =  mutableListOf<Int>()
        traverse(root, result)
        return result
    }

    fun traverse(root: TreeNode?, result: MutableList<Int>) {
        if (root == null) {
            return
        }

        traverse(root.left, result)
        result.add(root.`val`)
        traverse(root.right, result)
    }

    ///////////////////////////////
    fun inorderTraversalIterative(root: TreeNode?): List<Int> {
      val result = mutableListOf<Int>()
      val stack = ArrayDeque<TreeNode>()
      var current = root

      while (current != null || stack.isNotEmpty()) {

          while (current != null) {
              stack.addLast(current)
              current = current.left
          }

          current = stack.removeLast()
          result.add(current.`val`)

          current = current.right
      }

      return result
    }
}