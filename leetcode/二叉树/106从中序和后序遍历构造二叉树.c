struct TreeNode* mybuild(int* inorder, int inStart, int inEnd, int* postorder, int postEnd){
    if(inStart > inEnd)return NULL;
    else{
        struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        root->val = postorder[postEnd]; //得到根
        int in_left_end, in_right_start, post_left_end, post_right_end, right_size = 0;
        for(int i = inStart; i <= inEnd; i++){
            if(inorder[i] == postorder[postEnd]){
                in_left_end = i-1; //左子树中序遍历数组结束处的下标
                right_size = inEnd - i;
                in_right_start = i+1; //右子树中序遍历开始处的下标
                break;
            }
        }
        //____________________________________________________________________________计算各个数组的始末
        post_right_end = postEnd - 1;
        post_left_end = postEnd - right_size - 1;
        //____________________________________________________________________________递归左右子树
        root->left = mybuild(inorder, inStart, in_left_end, postorder, post_left_end);
        root->right = mybuild(inorder, in_right_start, inEnd, postorder, post_right_end);
        return root;
    }
}
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    return mybuild(inorder, 0, inorderSize-1, postorder, postorderSize-1);
}
