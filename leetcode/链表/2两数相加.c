struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int damn = 0;//判断是否需要进位
    struct ListNode* List = malloc(sizeof(struct ListNode));
    List->val = 0;
    List->next = NULL;
    struct ListNode* ret = List;
    int v = 0,v1 = 0, v2 = 0, cal = 0;
    while(l1 != NULL || l2 != NULL){
        struct ListNode* P = malloc(sizeof(struct ListNode));
        P->next = NULL;
        if(l1 == NULL)v1 = 0;
        else v1 = l1->val;
        if(l2 == NULL)v2 = 0;
        else v2 = l2->val;
        if(damn == 1)cal = v1+v2+1;
        else cal = v1+v2;
        P->val = cal%10;
        if(cal >= 10)damn = 1;
        else damn = 0;
        List->next = P;
        List = List->next;
        if(l1 != NULL)l1 = l1->next;
        if(l2 != NULL)l2 = l2->next;
    }
    if(damn == 1){
        struct ListNode* P = malloc(sizeof(struct ListNode));
        P->next = NULL;
        P->val = 1;
        List->next = P;
    }
    ret = ret->next;
    return ret;
}
