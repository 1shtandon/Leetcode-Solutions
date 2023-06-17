// gfg questionF

class Solution
{
    public:
    //Function to delete middle element of a stack.
    
    void helperRecursion(stack<int> &st , int k)
    {
        // base condition
        if(k == 1)
        {
            st.pop();
            return;
        }
        
        // remove top element and recursion on stack, at last insert the top again
        int top = st.top();
        st.pop();
        helperRecursion(st , k - 1);
        
        st.push(top);
    }
    
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        int k = (sizeOfStack / 2) + 1;
        
        helperRecursion(s , k);
    }
};