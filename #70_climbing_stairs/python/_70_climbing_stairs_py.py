class Solution:
    def climbStairs(self, n: int) -> int:
        
        if n <= 2:
            return n
        
        prev = 1
        cur = 2
        
        for i in range(3, n + 1):
            temp = cur + prev
            prev = cur
            cur = temp
            
        return cur    
        
def main():

    sol = Solution()
    print(sol.climbStairs(5), end = "")

if __name__ == '__main__':
    main()