int removeDuplicates(int* nums, int numsSize){
    if(numsSize == 0)return 0;
    int j = 0, i = 0, current = nums[i];
    nums[j] = current;
    i++;
    j++;
    while(i < numsSize){
        if(nums[i] != current){
            current = nums[i];
            nums[j] = nums[i];
            j++;
        }
        i++;
    }
    return j;
}
