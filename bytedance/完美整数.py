def solution(x, y):
    def check(num):
        s = str(num)
        for i in range(1, len(s)):
            if s[i] != s[0]:
                return False
        return True
    ans = 0
    for i in range(x, y + 1):
        if check(i):
            ans += 1
    return ans
        


if __name__ == "__main__":
    # Add your test cases here

    print(solution(1, 10) == 9)
    print(solution(2, 22) == 10)