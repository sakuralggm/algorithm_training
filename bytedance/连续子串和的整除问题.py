'''
余数：如果两个前缀和的余数相同，那么它们之间的子串和一定可以被 b 整除。
解释：s1 = k1 * b + r, s2 = k2 * b + r, s2 - s1 = (k2 - k1) * b，即 s2 和 s1 之间的子串和一定可以被 b 整除。

'''
def solution(n, b, sequence):
    prefix_sum = [0] * (n + 1)
    for i in range(1, n + 1):
        prefix_sum[i] = prefix_sum[i - 1] + sequence[i - 1]

    print(prefix_sum)
    remainder_count = {}
    ans = 0

    for i in range(n + 1): # 对于前0个元素的前缀和的余数为0，这个也要统计。如果s[i] % b == 0，那么a[0]~a[i - 1]的子串是符合条件的。
        remainder = prefix_sum[i] % b
        if remainder in remainder_count:
            ans += remainder_count[remainder] # s[i]与remainder_count[remainder]之间的子串和都可以被b整除，ans加上它们的个数
            remainder_count[remainder] += 1 # 更新remainder_count[remainder]的值
        else:
            remainder_count[remainder] = 1 # 如果remainder不在remainder_count中，那么就加入remainder_count中

    return ans

if __name__ == "__main__":
    # You can add more test cases here
    print(solution(3, 3, [1, 2, 3]) == 3)