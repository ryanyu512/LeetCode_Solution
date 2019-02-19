class Solution:
    def longestCommonPrefix(self, strs: 'List[str]') -> 'str':
       
        input_len = len(strs)

        if (input_len == 0):
            return ""

        min_idx = -1
        min_word_len = len(strs[0])

        for i in range(input_len):
            if (min_word_len > len(strs[i])):
                min_word_len = len(strs[i])
                min_idx = i
        
        is_same = [False for i in range(min_word_len)]
        com_prefix_length = 0
        for i in range(min_word_len):
            is_same[i] = True
            for j in range(input_len):
                if (strs[j][i] != strs[min_idx][i]):
                    is_same[i] = False
                    break
            if (is_same[i] != False):
                com_prefix_length += 1
        
        if (com_prefix_length == 0):
            return ""
        
        last_idx = -1
        for i in range(min_word_len):
            if (is_same[i]):
                last_idx += 1
            else:
                break
        
        com_prefix = strs[min_idx][0:last_idx + 1]

        return com_prefix       

def main():

    input = ["flower","flow","flight"]
    
    sol = Solution()
    result = sol.longestCommonPrefix(input)

    print(result, end = '')

    return

if __name__ == '__main__':
    main()