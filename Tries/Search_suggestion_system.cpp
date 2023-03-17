class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        // sorting the products
        sort(products.begin(), products.end());

        vector<vector<string>> ans;
        string prefix = "";

        for (char c : searchWord)
        {
            prefix += c;
            vector<string> temp;
            for (string product : products)
            {
                // if the product starts with the prefix
                if (product.find(prefix) == 0)
                {
                    temp.push_back(product);
                }
                // if the product is greater than the prefix
                if (prefix > product)
                {
                    continue;
                }
                if (temp.size() == 3)
                {
                    break;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
