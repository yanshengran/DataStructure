/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* mybuild(int* pre, int preStart, int preSize, int* post, int postSize, int postStart){
    if(preSize == 0)return NULL;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = pre[preStart];
    root->left = NULL;
    root->right = NULL;
    if(preSize == 1)return root;
    int LeftRoot = pre[preStart + 1], LeftLength = 0;
    for(int i = postStart; i < postSize + postStart; i++){
        if(LeftRoot == post[i]){
            LeftLength = i+1-postStart; //左子树长度
            break;
        }
    }
    int RightLength = preSize-LeftLength-1;  //CHECK
    int RightPreStart = LeftLength + 1 + preStart; //CHECK
    root->left = mybuild(pre, preStart+1, LeftLength, post, LeftLength, postStart);
    root->right = mybuild(pre, RightPreStart, RightLength, post, RightLength, LeftLength + postStart);
    return root;
}
struct TreeNode* constructFromPrePost(int* pre, int preSize, int* post, int postSize){
    return mybuild(pre, 0, preSize, post, postSize, 0);
}
