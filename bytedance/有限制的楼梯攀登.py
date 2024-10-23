def solution(n):
    dp = [[0 for _ in range(2)] for _ in range(n + 1)]
    dp[0][0] = 1
    dp[1][0] = 1
    dp[1][1] = 0
    for i in range(2, n + 1):
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1]
        dp[i][1] = dp[i - 2][0]
    return dp[n][0] + dp[n][1]
if __name__ == "__main__":
    # Add your test cases here

    print(solution(2) == 2)  # 样例1
    print(solution(3) == 3)  # 样例2
    print(solution(4) == 4)  # 样例3