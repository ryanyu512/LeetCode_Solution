class Solution:
    def merge(self, nums1: 'List[int]', m: 'int', nums2: 'List[int]', n: 'int') -> 'None':
        """
        Do not return anything, modify nums1 in-place instead.
        """
        if n == 0:
            return
        
        i = j = k = 0
        
        nums = [0 for i in range(m + n)]
        while(i < m and j < n):
            if (nums1[i] < nums2[j]):
                nums[k] = nums1[i]
                i += 1
            else:
                nums[k] = nums2[j]
                j += 1
            k += 1            
                
        while(i < m):
            nums[k] = nums1[i]
            k+=1
            i+=1
        while(j < n):
            nums[k] = nums2[j]
            k+=1
            j+=1
        
        for i in range(len(nums1)):
            nums1[i] = nums[i] 

def main():

    sol = Solution()


    nums1 = [1,2,3,0,0,0]
    nums2 = [2,5,6]
    sol.merge(nums1, 3, nums2, 3)

    print(nums1, end = '')

    return

if __name__ == '__main__':
    main()

