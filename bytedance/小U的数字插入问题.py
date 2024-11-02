def solution(a: int, b: int) -> int:
    a_str = str(a)
    max_num = -1
    for i in range(len(a_str) + 1):
        new_num = int(a_str[:i] + str(b) + a_str[i:])
        if new_num > max_num:
            max_num = new_num
    return max_num



if __name__ == '__main__':
    print(solution(76543, 4) == 765443)
    print(solution(1, 0) == 10)
    print(solution(44, 5) == 544)
    print(solution(666, 6) == 6666)