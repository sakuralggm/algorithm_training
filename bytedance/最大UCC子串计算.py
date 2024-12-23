"""
题解：https://bytedance.larkoffice.com/docx/WGGidwQk3o5h3XxjWGEcHwDGnZb

经验：题目中给了多个字符串的操作，我们需要先考虑化简这些操作。考虑哪些操作可以被其他操作替代，哪些操作对结果没有影响。这道题的结论是插入是最优的操作，删除是完全不操作的，替换操作完全可以由插入操作代替。

已知只执行插入操作，那如何操作可以得到最多的UCC子串？
前提：字符不能重复利用
1. 优先记录已经有的UCC子串的个数
2. 优先记录UC和CC的个数，因为它们只需要插入一次就可以得到UCC子串
3. 剩下的字符，需要插入两次才能得到UCC子串
4. 如果对现有的字符进行插入操作后次数还有剩余，那么剩余的次数可以用来直接插入UCC
"""


def solution(m: int, s: str) -> int:
    res, n = 0, 0
    i = 0
    length = len(s)
    while i < length:
        if (
            s[i : i + 3] == "UCC"
        ):  # 这里的判断条件可以更简洁，不用每次都判断i是否越界 因为如果i+3越界的话，s[i:i+3]得到的是s[i:]，不会报错，也不会等于'UCC'
            res += 1
            i += 3
        elif s[i : i + 2] == "UC" or s[i : i + 2] == "CC":
            n += 1
            i += 2
        else:
            i += 1

    # 优化的写法，更简洁，但是不容易理解
    ans = res + min(n, m)
    m = max(0, m - n)
    remaining = length - res * 3 - n * 2
    ans += min(remaining, m // 2)
    m = max(0, m - remaining * 2)  # m -= min(m, remaining * 2) 也可以
    ans += m // 3
    """
    ans = res
    if n >= m:
        ans += m
    else:
        ans += n
        m -= n
        twice = len(s) - res * 3 - n * 2
        if m >= twice * 2:
            ans += twice
            m -= twice * 2
            ans += m // 3
        else:
            ans += m // 2
    """
    return ans


if __name__ == "__main__":
    print(solution(m=3, s="UCUUCCCCC") == 3)
    print(solution(m=6, s="U") == 2)
    print(solution(m=2, s="UCCUUU") == 2)


# UC U UCC CC C
