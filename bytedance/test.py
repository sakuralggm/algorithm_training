def solution(numbers):
    ans = 0
    def dfs(u, sum):
        if u == len(numbers):
            nonlocal ans
            if sum % 2 == 0:
                ans += 1
        for i in range(0, len(str(numbers[u]))):
            dfs(u + 1, sum + int(str(numbers[u])[i]))
    dfs(0, 0)
    return ans