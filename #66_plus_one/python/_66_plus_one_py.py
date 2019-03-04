class Solution:
    def plusOne(self, digits: 'List[int]') -> 'List[int]':
        if (len(digits) == 0):
            return digits
        
        digits[-1] += 1
        if (digits[-1] == 10):
            digits[-1] = 0
            
        for i in range(len(digits) - 2, -1, -1): 
            if (digits[i + 1] == 0):
                digits[i] += 1
                if (digits[i] == 10):
                    digits[i] = 0
            else:
                break
                
        if (digits[0] == 0):
            digits.insert(0, 1)
            
        return digits    

def main():

    digits = [9, 9]

    sol = Solution() 
    result = sol.plusOne(digits)

    print(result, end ='')

    return


if __name__ == '__main__':
    main()