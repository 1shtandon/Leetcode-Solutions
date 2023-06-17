class Solution{
    public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    
    void solve(int n , int source , int dest , int helper)
    {
        // base case when only one disk, move from src to dest
        if(n == 1)
        {
            cout << "move disk " << n << " from rod " << source << " to rod " << dest << endl; 
            return;
        }
        
        // now recursively solve for n - 1 disks from src to helper, then the last disk from src to dest, at last those n - 1 from helper to dest
        // note that one tower is from , other is to, so the remaining will act as aux
        
        solve(n - 1, source , helper , dest);
        
        // now move the last from src to dest directly, so print
        cout << "move disk " << n << " from rod " << source << " to rod " << dest << endl; 
        
        // rest n - 1 from helper to dest using source as aux
        
        solve(n - 1 , helper , dest , source);
    }
    
    long long toh(int N, int from, int to, int aux) {
        // Your code here
        solve(N , from ,to , aux);
        
        return (long long)pow(2 , N) - 1;
    }

};