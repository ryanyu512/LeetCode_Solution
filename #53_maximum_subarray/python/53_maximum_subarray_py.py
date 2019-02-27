import sys

class Solution:
    def maxSubArray(self, nums: 'List[int]') -> 'int':

        if(len(nums) == 0):
            return 0

        if (len(nums) == 1):
            return nums[0]

        last_idx = -1
        first_idx = -1

        max_val = -sys.maxsize - 1
        cur_max_val = -sys.maxsize - 1
        sum = 0

        for i in range(len(nums)):

            if (sum == 0):
                first_idx = i
                last_idx = i
            
            if (sum + nums[i] > cur_max_val):
                last_idx = i
                cur_max_val = sum + nums[i]

            sum += nums[i]

            if (sum <= 0 or i == len(nums) - 1):
                if (cur_max_val > max_val):
                    max_val = cur_max_val

                cur_max_val = -sys.maxsize - 1
                first_idx = last_idx
                i = last_idx
                last_idx = -1
                sum = 0

        return max_val

def main():

    sol = Solution()
    sum = sol.maxSubArray([-2, 1, 2, 0, -3, 5])

    print(sum)

    return

if __name__ == '__main__':
    main()