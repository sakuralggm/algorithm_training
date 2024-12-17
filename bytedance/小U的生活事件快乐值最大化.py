def solution(n: int, T: int, H: int, t: list, h: list, a: list) -> int:
    dp = [[0] * (H + 1) for _ in range(T + 1)]
    for i in range(n):
        for j in range(T, t[i] - 1, -1):
            for k in range(H, h[i] - 1, -1):
                dp[j][k] = max(dp[j][k], dp[j - t[i]][k - h[i]] + a[i])
    return dp[T][H]

if __name__ == '__main__':
    print(solution(n = 2, T = 2, H = 2, t = [1, 3], h = [3, 1], a = [3, 4]) == 0)
    print(solution(n = 3, T = 5, H = 5, t = [2, 1, 3], h = [1, 3, 2], a = [10, 7, 8]) == 18)
    print(solution(n = 1, T = 3, H = 3, t = [4], h = [4], a = [5]) == 0)