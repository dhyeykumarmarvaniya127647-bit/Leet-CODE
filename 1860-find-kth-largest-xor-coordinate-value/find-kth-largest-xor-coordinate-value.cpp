class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> v;
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (i) matrix[i][j] ^= matrix[i-1][j];
                if (j) matrix[i][j] ^= matrix[i][j-1];
                if (i && j) matrix[i][j] ^= matrix[i-1][j-1];
                v.push_back(matrix[i][j]);
            }
        
        nth_element(v.begin(), v.end() - k, v.end());
        return v[v.size() - k];
    }
};
   