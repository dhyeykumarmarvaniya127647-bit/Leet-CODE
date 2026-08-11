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
    Node* intersect(Node* a, Node* b) {
        if (a->isLeaf) return a->val ? new Node(1,1) : b;
        if (b->isLeaf) return b->val ? new Node(1,1) : a;

        Node* n = new Node(0,0);
        n->topLeft = intersect(a->topLeft,b->topLeft);
        n->topRight = intersect(a->topRight,b->topRight);
        n->bottomLeft = intersect(a->bottomLeft,b->bottomLeft);
        n->bottomRight = intersect(a->bottomRight,b->bottomRight);

        if (n->topLeft->isLeaf && n->topRight->isLeaf &&
            n->bottomLeft->isLeaf && n->bottomRight->isLeaf &&
            n->topLeft->val == n->topRight->val &&
            n->topLeft->val == n->bottomLeft->val &&
            n->topLeft->val == n->bottomRight->val)
            return new Node(n->topLeft->val,1);

        return n;
    }
};