Step 1 just find the max depth of the tree
Step 2 take sum of all nodes on that depth
step 3 return sum

upvote if it works

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{

  int height;
  int sum = 0;

private:
  int h(TreeNode *x)
  {
    if (!x)
      return 0;

    int l = h(x->left);
    int r = h(x->right);

    return (1 + max(l, r));
  }

  void preorder(TreeNode *x, int h)
  {

    if (!x)
      return;

    if (h == height - 1)
    {
      sum += x->val;
    }

    preorder(x->left, h + 1);
    preorder(x->right, h + 1);
  }

public:
  int deepestLeavesSum(TreeNode *root)
  {
    height = h(root);
    preorder(root, 0);
    return sum;
  }
};
