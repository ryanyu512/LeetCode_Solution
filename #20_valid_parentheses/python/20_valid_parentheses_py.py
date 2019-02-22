class Solution:
    def isValid(self, s: 'str') -> 'bool':
        if (len(s) == 0):
            return True

        if (len(s)%2 != 0):
            return False

        stack = []

        for i in range(len(s)):
            if (s[i] == '[' or s[i] == '{' or s[i] == '('):
                stack.insert(0, s[i])
            else:
                if (len(stack) == 0):
                    return False
                
                if (stack[0] == '[' and s[i] == ']' or
                    stack[0] == '(' and s[i] == ')' or
                    stack[0] == '{' and s[i] == '}'):
                    stack.pop(0)
                else:
                    return False              

        if (len(stack) != 0):
            return False

        return True


def main():

    sol = Solution()

    is_valid = sol.isValid("")

    print(is_valid)

    return 

if __name__ == '__main__':
    main()