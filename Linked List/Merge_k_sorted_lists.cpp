/*
Approach 1: Brute Force

1. Creating a dummy head node and setting the current node to this head.
2. We will iterate through the lists and find the minimum value node.
3. We will add this node to the current node and move the current node to the next node.
4. We will repeat this process until all the lists are empty.

Time Complexity: O(NlogN), where N is the total number of nodes.
Space Complexity: O(1)
*/

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return NULL;

        ListNode *dummyHead = new ListNode(0);
        ListNode *currentNode = dummyHead;

        while (true)
        {
            int minIndex = -1;
            for (int i = 0; i < lists.size(); i++)
            {
                if (lists[i] == NULL)
                    continue;
                if (minIndex == -1)
                    minIndex = i;
                else if (lists[i]->val < lists[minIndex]->val)
                    minIndex = i;
            }

            if (minIndex == -1)
                break;

            currentNode->next = lists[minIndex];
            lists[minIndex] = lists[minIndex]->next;
            currentNode = currentNode->next;
        }

        return dummyHead->next;
    }
};