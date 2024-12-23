# 题解：https://bytedance.larkoffice.com/docx/W4q5dpCaDok6AFxqKyUcq2Y7ndc
'''
朴素的思路：枚举替换的位置，然后计算替换后的最大子数组和
对于每个位置i，计算包含a[i]的最大子数组和的方法是先计算前面的元素的贡献和后面的元素的贡献，然后再加上max(a[i], x)。而计算贡献可以用前缀和来优化。

这道题与最大连续子数组和模板题的区别在于，模板题是不允许替换元素的，而这道题是允许替换元素的。对于前者，我们可以枚举每个位置i，然后计算以a[i]结尾的最大连续子数组和，最后取最大值。但是在这道题中，如果采用同样方法，我们就无法考虑替换后的a[i]对后面的数的贡献。因此我们枚举的是包含a[i]的最大子数组和，而不是以a[i]结尾的最大子数组和。
'''
def solution(n: int, x: int, a: list) -> int:
    # 将a数组中的最小值替换为x
    m = min(a)
    if x < m:
        a[a.index(m)] = x
    pre, suf = [0] * (n + 1), [0] * (n + 1)
    for i in range(n):
        pre[i] = max(0, pre[i - 1] + a[i - 1] if i > 0 else 0)
    for i in range(n - 1, -1, -1):
        suf[i] = max(0, suf[i + 1] + a[i + 1] if i < n - 1 else 0)
    return max(pre[i] + suf[i] + max(x, a[i]) for i in range(n))
            

if __name__ == '__main__':
    print(solution(n = 5, x = 10, a = [5, -1, -5, -3, 2]) == 15)
    print(solution(n = 2, x = -3, a = [-5, -2]) == -2)
    print(solution(n = 6, x = 10, a = [4, -2, -11, -1, 4, -1]) == 15)
    print(solution(n = 16, x = 1, a = [17,17,4,13,11,3,6,13,7,13,13,13,6,16,6,11]) == 167)