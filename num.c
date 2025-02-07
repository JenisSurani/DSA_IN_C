#include <stdio.h>
#include <stdlib.h>

int *twosum(int *nums, int numsSize, int target)
{
    int ii = -1, jj = -1;
    int *ret;
    for (int i = 0; i < numsSize; i++)
    {
        int temp = nums[i];
        for (int j = 0; j < numsSize; j++)
        {
            if (i == j)
            {
                continue;
            }

            if (nums[i] + nums[j] == target)
            {
                ii = i;
                jj = j;
                goto end;
            }
        }
    }
end:
    ret = (int *)malloc(2 * sizeof(int));
    ret[0] = ii;
    ret[1] = jj;
    return ret;
}

int main()
{
    int arr[] = {2, 7, 11, 15};
    int size = sizeof(arr) / sizeof(int);
    int target = 26 ;
    int *ret = twosum(arr, size, target);

    printf("%d %d", ret[0], ret[1]);
    return 0;
}