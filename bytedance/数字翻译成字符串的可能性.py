def solution(num):
    num = str(num)
    ans = 0
    def dfs(u):
        nonlocal ans
        if u >= len(num) - 1:
            ans += 1
            return
        dfs(u + 1)
        if num[u:u + 2] <= '25' and num[u:u + 2] >= '10':
            dfs(u + 2)
    dfs(0)
    return ans
    
if __name__ == "__main__":
    #  You can add more test cases here
    print(solution(12258) == 5)
    print(solution(1400112) == 6)
    print(solution(2110101) == 10)