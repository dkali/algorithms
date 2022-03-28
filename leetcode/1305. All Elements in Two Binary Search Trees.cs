// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/submissions/

// Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.

// Example 1:
// Input: root1 = [2,1,4], root2 = [1,0,3]
// Output: [0,1,1,2,3,4]

// Example 2:
// Input: root1 = [1,null,8], root2 = [8,1]
// Output: [1,1,8,8]
 
public class Solution
{
    public IList<int> GetAllElements(TreeNode root1, TreeNode root2)
    {
        List<int> result = new List<int>();
        Stack<TreeNode> st1 = new Stack<TreeNode>();
        Stack<TreeNode> st2 = new Stack<TreeNode>();

        TreeNode currentNode1 = root1;
        TreeNode currentNode2 = root2;
        int? currentDigit1 = getNextInorderTraversal(ref currentNode1, ref st1);
        int? currentDigit2 = getNextInorderTraversal(ref currentNode2, ref st2);
        
        do
        {
            if (currentDigit1 != null &&
                (currentDigit1 <= currentDigit2 || currentDigit2 == null))
            {
                result.Add((int)currentDigit1);
                currentDigit1 = getNextInorderTraversal(ref currentNode1, ref st1);
            }

            if (currentDigit2 != null &&
                (currentDigit2 < currentDigit1 || currentDigit1 == null)) 
            {
                result.Add((int)currentDigit2);
                currentDigit2 = getNextInorderTraversal(ref currentNode2, ref st2);
            }
        } while (currentDigit1 != null || currentDigit2 != null);

        return result;
    }

    // 1) Create an empty stack S.
    // 2) Initialize current node as root
    // 3) Push the current node to S and set current = current->left until current is NULL
    // 4) If current is NULL and stack is not empty then
    //      a) Pop the top item from stack.
    //      b) Print the popped item, set current = popped_item->right
    //      c) Go to step 3.
    // 5) If current is NULL and stack is empty then we are done.
    private int? getNextInorderTraversal(ref TreeNode currentNode, ref Stack<TreeNode> stack)
    {
        while (currentNode != null)
        {
            stack.Push(currentNode);
            currentNode = currentNode.left;
        }

        if (stack.Count == 0)
            return null; // we are done
        else
        {
            TreeNode tmp = stack.Pop();
            currentNode = tmp.right;
            return tmp.val;
        }
    }
}