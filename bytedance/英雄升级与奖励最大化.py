'''
题目链接：https://www.marscode.cn/practice/8ee68j852y64nl?problem_id=7414004855076470828
官方题解：https://bytedance.larkoffice.com/docx/OJSBd0oBcorDvwxxWATcF99enKb

想要获得对应的奖励，小W需要将英雄的初始能力值升级到 b_i，并且所有英雄的初始能力值都为 1，所以我们可以先对每个目标能力值 b_i 预处理出对应所需的升级次数，用数组 d 表示， d[i] 表示想达到目标值 i 所需的升级次数
在处理出 d 数组后，我们将问题转化为了：有 n 个英雄，最多通过k 次升级操作来提升英雄的能力值，然后每个英雄需要 d[b[i]]次操作，才能获得对应的奖励 c[i]。这是一个经典的01背包问题，套上模版即可通过

难点：如何处理出 d 数组
d[t]表示从1到t需要的最小操作次数
操作的规定为：
* 选择一个正整数x
* a = a + a // x (即下取整)
思路：
对于正整数t，它一定是由一个比它小的数i加上一个数i//j得到的，其中j是一个正整数。
j <= i，因为j > i时，i//j = 0，没有意义。
正向思维：我们可以枚举i和j，然后计算出t，然后更新d[t] = min(d[t], d[i] + 1)，代码为：
for i in range(1, t):
        for j in range(1, i + 1):
            x = i + i // j
            if x == t:
                d[t] = min(d[i] + 1, d[t])
这是求解一个d[t]的方法。

但是我们需要求解d[1]到d[m]的值，其中m是b数组中的最大值。
因此：我们可以枚举从1到m的数，对于每个数i，我们枚举j，然后计算出它所有可以一步到达的数t，如果t <= m，那么我们就更新d[t] = min(d[i] + 1, d[t])。由于t一定是由比它小的某个数一步到达的，因此我们可以保证枚举完d[t]的所有情况，将它更新为最小。代码为：
for i in range(1, m + 1):
        for j in range(1, i + 1):
            t = i + i // j
            if t <= m:
                d[t] = min(d[i] + 1, d[t])
                
                
总结：这个思路的来源是一个数的最优解与比它小的数的最优解有关，因此我们可以从小到大递推，最终得到所有数的最优解。
'''
def solution(n, k, b, c):
    m = max(b)
    d = [1e9] * (m + 1)
    d[1] = 0
    for i in range(1, m + 1):
        for j in range(1, i + 1):
            t = i + i // j
            if t <= m:
                d[t] = min(d[i] + 1, d[t])
    cost = [int(d[i]) for i in b]
    # 从n个人（物品）中选，最多选k个（背包容量是k），每个人（物品）的体积是cost，价值是c
    # 要求选出的物品的价值和最大
    # 01背包问题
    dp = [0] * (k + 1)
    for i in range(n):
        for j in range(k, cost[i] - 1, -1):
            dp[j] = max(dp[j], dp[j - cost[i]] + c[i])
    return dp[k]


if __name__ == "__main__":
    # Add your test cases here
    print(solution(4, 4, [1, 7, 5, 2], [2, 6, 5, 2]) == 9)
    print(solution(3, 0, [3, 5, 2], [5, 4, 7]) == 0)
    print(solution(3, 3, [3, 5, 2], [5, 4, 7]) == 12)
