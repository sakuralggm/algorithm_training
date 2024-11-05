def solution(n: int, l: int, r: int, a: list) -> int:
    cnt = 0
    for i in a:
        if l <= i <= r and i % 2 == 0:
           cnt += 1
    return cnt 

if __name__ == '__main__':
    print(solution(5, 3, 8, [1, 2, 6, 8, 7]) == 2)
    print(solution(4, 10, 20, [12, 15, 18, 9]) == 2)
    print(solution(3, 1, 10, [2, 4, 6]) == 3)