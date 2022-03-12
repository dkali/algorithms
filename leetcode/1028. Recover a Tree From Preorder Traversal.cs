// https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/

// We run a preorder depth-first search (DFS) on the root of a binary tree.
// At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.
// If a node has only one child, that child is guaranteed to be the left child.
// Given the output traversal of this traversal, recover the tree and return its root.

public class TreeNode
{
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null)
    {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class Solution
{
    public TreeNode RecoverFromPreorder(string traversal)
    {
        Stack<TreeNode> st = new Stack<TreeNode>();
        TreeNode root = null;
        int nodeLevel = 0;
        StringBuilder sb = new StringBuilder("", 10);

        foreach (char ch in traversal)
        {
            if (ch == '-')
            {
                if (sb.Length != 0)
                {
                    int num = Int32.Parse(sb.ToString());
                    AddNode(ref st, num, ref root);
                    sb.Clear();
                    nodeLevel = 0;
                }
                
                nodeLevel++;
            }
            else
            {
                while (st.Count > nodeLevel)
                    st.Pop();

                sb.Append(ch);
            }
        }

        int lastNum = Int32.Parse(sb.ToString());
        AddNode(ref st, lastNum, ref root);

        return root;
    }

    private void AddNode(ref Stack<TreeNode> st, int val, ref TreeNode root)
    {
        TreeNode newNode = new TreeNode(val);

        if (st.Count != 0)
        {
            TreeNode parent = st.Peek();
            if (parent.left == null)
                parent.left = newNode;
            else
                parent.right = newNode;
        }
        else
        {
            root = newNode;
        }
        st.Push(newNode);
    }

}