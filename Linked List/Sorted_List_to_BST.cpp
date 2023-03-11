/*
Approach: Recursion

1. First we will find the middle element of the linked list.
2. Make the middle element as the root of the tree.
3. Recursively call the function for the left half of the linked list and make the root of the left subtree as the left child of the root.
4. Recursively call the function for the right half of the linked list and make the root of the right subtree as the right child of the root.

Time Complexity: O(nlogn) because we find the middle element of the linked list in each recursive call.
Space Complexity: O(logn) as we are using recursion and the maximum depth of the recursion tree can go upto logn.
*/

class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return new TreeNode(head->val);
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = NULL;
        while (fast != NULL && fast->next != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
};