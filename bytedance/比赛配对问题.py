# 打表找规律，发现结果都是n-1，所以直接返回n-1即可
# def solution(x):
#     ans = 0
#     while x > 1:
#         if x % 2 == 0:
#             ans += x // 2
#             x //= 2
#         else:
#             ans += (x - 1) // 2
#             x = (x + 1) // 2
#     return ans

# if __name__ == '__main__':
#     for i in range(1, 100):
#         print(i, solution(i))

def solution(n: int) -> int:
    return n - 1

if __name__ == '__main__':
    print(solution(7) == 6)
    print(solution(14) == 13)
    print(solution(1) == 0)