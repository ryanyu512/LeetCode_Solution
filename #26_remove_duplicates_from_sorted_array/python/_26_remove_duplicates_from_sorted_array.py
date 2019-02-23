class Solution:
    def removeDuplicates(self, nums: 'List[int]') -> 'int':
        
        if len(nums) == 0:
            return 0

        length = 0
        for i in range(1, len(nums)):
            if (nums[i] != nums[length]):
                length += 1
                nums[length] = nums[i]

        length += 1

        return length

def main():

    nums = [1, 1, 2]

    sol = Solution()

    length = sol.removeDuplicates(nums)

    for i in range(length):
        print(nums[i], ' ', end = '')

    return 


if __name__ == '__main__':
    main()