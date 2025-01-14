# 题解：https://bytedance.larkoffice.com/docx/FBj5dyLwZof6alxsvTvcCmWzn6g
def solution(n: int) -> int:
    d = {
        0: [4, 6],
        1: [6, 8],
        2: [7, 9],
        3: [4, 8],
        4: [0, 3, 9],
        5: [],
        6: [0, 1, 7],
        7: [2, 6],
        8: [1, 3],
        9: [2, 4]
    }
    '''
    dp数组是二维的写法
    dp[i][j]表示已经按下i个数字且最后一个数字是j的号码数量
    # 创建一个二维数组，第一维大小是n，第二维大小是10
    dp = [[0] * 10 for _ in range(n + 1)]
    for i in range(10):
        dp[1][i] = 1
    for i in range(2, n + 1):
        for j in range(10):
            for k in d[j]:
                dp[i][j] += dp[i - 1][k] # dp[i][j]一开始是0，然后加上dp[i - 1][k]的值
    return sum(dp[n]) % 1000000007
    '''
    dp = [1] * 10
    for _ in range(2, n + 1):
        t = [0] * 10
        for j in range(10):
            for k in d[j]:
                t[j] += dp[k]
        dp = t
    return sum(dp) % 1000000007

if __name__ == '__main__':
    print(solution(1) == 10)
    print(solution(2) == 20)
    print(solution(3) == 46)
    print(solution(4) == 104)