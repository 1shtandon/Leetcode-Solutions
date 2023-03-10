/*
Approach : Random Number Generator

1. First we will count the number of nodes in the linked list.
2. Then we will generate a random number between 0 and count-1.
3. We will traverse the linked list and return the node at the random index.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution
{
private:
    ListNode *head;

public:
    Solution(ListNode *head)
    {
        this->head = head;
        // Seed the random number generator with the current time
        srand(time(NULL));
    }

    int getRandom()
    {
        ListNode *result = NULL;
        int count = 0;
        ListNode *curr = head;
        while (curr != NULL)
        {
            count++;
            // Generate a random number between 0 and count-1
            int r = rand() % count;
            // If the random number is 0, update the result to the current node
            if (r == 0)
            {
                result = curr;
            }
            curr = curr->next;
        }
        // Return the value of the randomly selected node
        return result->val;
    }
};