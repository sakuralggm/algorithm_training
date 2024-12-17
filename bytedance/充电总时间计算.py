def solution(n: int, x: int, a: list) -> str:
    ans = 0
    for i in range(n):
        ans += a[i] / (4 * x)
    return '{:.2f}'.format(ans)

if __name__ == '__main__':
    print(solution(4, 1, [2, 3, 4, 5]) == '3.50')
    print(solution(3, 2, [4, 6, 8]) == '2.25')
    print(solution(2, 1, [10, 5]) == '3.75')