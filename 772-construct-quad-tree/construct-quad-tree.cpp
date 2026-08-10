/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n =  grid.size();

        function<Node*(int,int,int)> solve = [&](int r, int c, int len) {
            bool same = true;

            for (int i = r; i < r + len; i++)
                for (int j = c; j < c + len; j++)
                    if (grid[i][j] != grid[r][c])
                        same = false;

            if (same)
                return new Node(grid[r][c], true);

            int h = len / 2;
            Node* root = new Node(true, false);

            root->topLeft = solve(r, c, h);
            root->topRight = solve(r, c + h, h);
            root->bottomLeft = solve(r + h, c, h);
            root->bottomRight = solve(r + h, c + h, h);

            return root;
        };

        return solve(0, 0, n);
    }
};