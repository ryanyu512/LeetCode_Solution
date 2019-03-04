class Solution:
    def addBinary(self, a: str, b: str) -> str:
        if (len(a) == 0):
            return b
        if (len(b) == 0):
            return a
        
        i = len(a) - 1
        j = len(b) - 1
        temp = 0
        
        result = ""
        while(i >= 0 or j >= 0 or temp > 0):
            if (i >= 0):
                temp = temp + int(a[i])
                i = i - 1
            if (j >= 0):
                temp = temp + int(b[j])
                j = j - 1
                
            result += str(temp%2)
            temp = int(temp/2)
            
        result = result[::-1]

        return result


def main():

    sol = Solution();

    str1 = "11"
    str2 = "1"

    result = sol.addBinary(str1, str2)

    print(str1, " ", str2, "= ", result, end = "")

    return

if __name__ == '__main__':
    main()