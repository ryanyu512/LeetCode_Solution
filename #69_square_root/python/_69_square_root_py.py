class Solution:
    def mySqrt(self, x: int) -> int:
        
        return int(self.BinarySearch(x, 0, x))
        
    def BinarySearch(self, tar_val: float, start_val: float, end_val: float) -> float:
        
        if (start_val >= end_val):
            if (start_val**2 > tar_val):
                return start_val - 1
            else:
                return start_val
       
        mid_val = int((start_val + end_val)/2)
        est_val = mid_val**2
        
        if (est_val == tar_val):
            return mid_val
        
        if (est_val > tar_val):
            return self.BinarySearch(tar_val, start_val, mid_val - 1)
        else:
            return self.BinarySearch(tar_val, mid_val + 1, end_val)
            
def main():

    sol = Solution()
    print(sol.mySqrt(4), end = "")

    return

if __name__ == '__main__':
    main()