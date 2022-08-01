// Given a BST and a value k, the task is to delete the nodes having values greater than or equal to k.

class Solution{
  public:
    /*The function should return the root of the modified tree*/
    Node* deleteNode(Node* root, int k)
    {
        if(root==NULL)
            return root;
        if(root->data>=k || root->data==k){
            Node* leftNode = deleteNode(root->left,k);
            return leftNode;
        }
        else if(root->data<k)
            root->right=deleteNode(root->right,k);
        return root;
    }
};