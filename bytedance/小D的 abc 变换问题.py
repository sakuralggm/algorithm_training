def solution(s: str, k: int) -> str:
    ans = ""
    for i in range(k):
        for j in range(len(s)):
            if s[j] == 'a':
                ans += "bc"
            elif s[j] == 'b':
                ans += "ca"
            else:
                ans += "ab"
        s = ans
        ans = ""
    return s

if __name__ == '__main__':
    print(solution("abc", 2) == 'caababbcbcca')
    print(solution("abca", 3) == 'abbcbccabccacaabcaababbcabbcbcca')
    print(solution("cba", 1) == 'abcabc')