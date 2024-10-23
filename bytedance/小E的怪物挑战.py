def solution(n: int, H: int, A: int, h: list, a: list) -> int:
    monsters = sorted(zip(h, a), reverse=True)
    dp = [0 for _ in range(n + 1)]
    for i in range(n - 1, -1, -1):
        dp[i] = 1
        for j in range(n - 1, i, -1):
            if monsters[j][0] < monsters[i][0] and monsters[j][1] < monsters[i][1]:
                dp[i] = max(dp[i], dp[j] + 1)
    ans = 0
    for i in range(n):
        if monsters[i][0] < H and monsters[i][1] < A:
            ans = max(ans, dp[i])
    return ans


if __name__ == '__main__':
    print(solution(3, 4, 5, [1, 2, 3], [3, 2, 1]) == 1)
    print(solution(5, 10, 10, [6, 9, 12, 4, 7], [8, 9, 10, 2, 5]) == 2)
    print(solution(4, 20, 25, [10, 15, 18, 22], [12, 18, 20, 26]) == 3)