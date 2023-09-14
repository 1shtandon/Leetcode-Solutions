class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head or k == 1)
            return head;

        int len = 0;
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;

        ListNode *curr = dummyNode, *prev = dummyNode, *next = dummyNode;

        while (curr->next)
        {
            len++;
            curr = curr->next;
        }

        // for considering only k group wise
        while (len >= k)
        {
            curr = prev->next;
            next = curr->next;

            // now reversing each link at a time for k - 1 iters
            for (int i = 1; i < k; i++)
            {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }

            prev = curr;

            len -= k;
        }

        return dummyNode->next;
    }
};






// Recursive approach Space O(N) (Stack)
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = 0;
        ListNode *temp = head;
        while(temp!=NULL){
            temp = temp -> next;
            size++;
        }
        if(size < k)    return head;   

        // Base call
        if(head == NULL)
            return NULL;

        // Step 1 - Reverse first k nodes
        ListNode *curr = head, *prev = NULL, *next = NULL;
        int count = 0;
        while(curr != NULL && count <k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Step 2 - Use recursion to reverse rest of the nodes
        if(next!=NULL){
            head->next = reverseKGroup(next, k);
        }

        // Step 3 - Return head
        return prev;
    }
};

// Iterative approach Space - O(1)
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *before = dummy, *after = head;
        ListNode *curr = NULL, *prev = NULL, *nxt = NULL;
        while(true){
            ListNode* cursor = after;
            for(int i = 0; i < k; i++){
                if(cursor == nullptr) 
                    return dummy->next;
                cursor = cursor->next;
            }
            curr = after;
            prev = before;
            for(int i = 0; i < k; i++){
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
            after->next = curr;
            before->next = prev;
            before = after;
            after = curr;
        }
    }
};