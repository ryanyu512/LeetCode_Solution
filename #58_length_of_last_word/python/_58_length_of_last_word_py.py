class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if (len(s) == 0):
            return 0

        length = 0
        for i in range(len(s) - 1, -1, -1):
            if (length == 0 and s[i] == ' '):
                continue
            elif (length >= 0 and s[i] != ' '):
                length += 1
            elif (length > 0 and s[i] == ' '):
                break

        return length


def main():
    
    s = "Hel lo "

    sol = Solution()
    length = sol.lengthOfLastWord(s)

    print(s, ': ', length, end = '') 

    return

if __name__ == '__main__':
    main()