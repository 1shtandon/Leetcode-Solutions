class Solution {
public:
    int res = INT_MAX;

    void solve(vector<int> &cookies , vector<int> &children , int idx , int maxm){
        if(idx >= cookies.size()){
            res = min(res , maxm);
            return;
        }

        for(int i = 0 ; i < children.size() ; i++){
            //  giving cookie to this child
                children[i] += cookies[idx];
                // recrusively solving for next 
                solve(cookies , children , idx + 1 , max(maxm , children[i]));
                // backtracking step
                children[i] -= cookies[idx];
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> children(k , 0);
        solve(cookies , children , 0 , 0);
        return res;
    }
};