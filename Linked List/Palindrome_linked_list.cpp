class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        stack<int> st;

        if (!head or !head->next)
            return true;

        ListNode *dummyHead = head;

        while (dummyHead)
        {
            st.push(dummyHead->val);
            dummyHead = dummyHead->next;
        }

        while (st.size() / 2)
        {
            if (st.top() != head->val)
            {
                return false;
            }

            st.pop();
            head = head->next;
        }

        return true;
    }
};



class Solution {
public:
  bool isPalindrome(ListNode* head) {
    ListNode *slow = head, *fast = head;
    ListNode *next, *prev = new ListNode();

    while(fast && fast->next) {
      // for finding middle
      slow = slow->next;
      fast = fast->next->next; 

      // reversing first half
      next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }
 
    // for edge cases
    if(fast) slow = slow->next;
    head = prev;

    // comparing first half to second one
    while(slow) {
      if(head->val != slow->val) return false;
      head = head->next, slow = slow->next;
    }
    return true;
  }
};