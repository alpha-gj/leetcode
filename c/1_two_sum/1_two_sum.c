#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define err_exit(MESSAGE) ( \
	perror(MESSAGE),		\
	exit(1)					\
)

int* twoSum(int* nums, int numsSize, int target) {

	// because the return of function is pointer, it need to use the static data type prevent the data released when levaving the function 
	static int sol_array[2] = {};

	for(int firstIndex = 0; firstIndex < numsSize; firstIndex++) {
		for (int secondIndex = 0; secondIndex < numsSize; secondIndex++) {

			//printf("nums[%d] is %d, nums[%d] is %d ", firstIndex, nums[firstIndex], secondIndex, nums[secondIndex]);

			if ((nums[firstIndex] + nums[secondIndex] ==  target) && (firstIndex != secondIndex)) {
				sol_array[0] = firstIndex;
				sol_array[1] = secondIndex;
				return sol_array;
			}

		}
	}

	// It can't find the answer 
	return sol_array; 
}

int main(void)
{
	printf("Please copy it to https://leetcode.com/problems/two-sum/description/\n");
	return 0;
}
