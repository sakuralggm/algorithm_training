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

# 3 4 5 第一行n H A
# 1 2 3 第二行h
# 3 2 1 第三行a
if __name__ == "__main__":
    data = input().split()
    n = int(data[0])
    H = int(data[1])
    A = int(data[2])
    h = list(map(int, input().split()))
    a = list(map(int, input().split()))
    
    print(solution(n, H, A, h, a))