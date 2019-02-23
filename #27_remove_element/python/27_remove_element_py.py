class Solution:
    def removeElement(self, nums: 'List[int]', val: int) -> 'int':

        if(len(nums) == 0):
            return 0
        
        length = -1
        for i in range(len(nums)):
            if (nums[i] != val):
                length += 1
                nums[length] = nums[i]

        length += 1
        
        return length

def main():

    nums = [0,1,2,2,3,0,4,2]

    val = 2

    sol = Solution()
    length = sol.removeElement(nums, val)
    
    for i in range(length):
        print(nums[i], ' ', end ='')

    return

if __name__ == '__main__':
    main()