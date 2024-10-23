def solution(n: int, a: list) -> int:
    cur = 1
    ans = []
    for i in a:
        if i == cur:
            cur += 1
            ans.append(i)
    if len(ans) == 0:
        return -1
    else:
        return n - len(ans)

if __name__ == '__main__':
    print(solution(5, [1, 4, 2, 3, 5]) == 2)
    print(solution(3, [3, 3, 2]) == -1)
    print(solution(5, [1, 2, 3, 4, 5]) == 0)