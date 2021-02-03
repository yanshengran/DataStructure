/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p == NULL && q == NULL)return true;
    bool judge = true;
    if(!(p!=NULL && q!=NULL && p->val == q->val))judge = false;
    if(judge == false)return false;
    judge = isSameTree(p->left, q->left);
    if(judge == false)return false;
    judge = isSameTree(p->right, q->right);
    return judge;
}
