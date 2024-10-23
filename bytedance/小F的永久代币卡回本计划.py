from math import ceil

def solution(a: int, b: int) -> int:
    # 方法1：return (a + b - 1) // b
    return ceil(a / b)

if __name__ == '__main__':
    print(solution(10, 1) == 10)
    print(solution(10, 2) == 5)
    print(solution(10, 3) == 4)