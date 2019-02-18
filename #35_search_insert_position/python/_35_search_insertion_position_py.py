class Solution:

    def __init__(self):
        self.is_found = False

    def BinarySearch(self, input: 'List[int]', tar_val: 'int', left_bound: 'int', right_bound: 'int') -> 'int':
    
        if (right_bound < left_bound):
            self.is_found = True
            return -1

        idx = (int)((left_bound + right_bound)/2)

        if (input[idx] == tar_val):
            return idx

        if (input[idx] > tar_val):
            tar_idx = self.BinarySearch(input, tar_val, left_bound, idx - 1)
        else:
            tar_idx = self.BinarySearch(input, tar_val, idx + 1, right_bound)

        if (tar_idx == -1):
            tar_idx = idx 

        if (self.is_found and (tar_idx < 0 or tar_idx >= len(input))):
            return tar_idx

        if (self.is_found and input[tar_idx] < tar_val):
            tar_idx += 1

        return tar_idx

    def searchInsert(self, nums: 'List[int]', target: 'int') -> 'int':
        
        tar_idx = self.BinarySearch(nums, target, 0, len(nums) - 1)

        self.is_found = True

        return tar_idx
        


def main():

    input = [1,3,5,6]
    tar_val = -1

    sol = Solution()
    tar_idx = sol.searchInsert(input, tar_val)

    for i in range(len(input)):
        print(input[i], end ='')
    print(tar_idx)    


    return
    
if __name__ == '__main__':
    main()          