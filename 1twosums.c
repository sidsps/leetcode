/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *index = (int*)malloc(2*sizeof(int));
    for(int i = 0;i < numsSize - 1;i++)
    {
        for(int j = i+1;j < numsSize;j++)
        {
            if(nums[i] + nums[j] == target)
            {
                i = i + 1;
                j = j + 1;
                if(i <= j)
                {
                    index[0] = i;
                    index[1] = j;
                    return index;
                }
                else
                {
                    index[0] = j;
                    index[1] = i;
                    return index;
                }
            }
        }
    }
    return NULL;
}
