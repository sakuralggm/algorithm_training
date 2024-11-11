def solution(n: int, s: list, x: list) -> list:
    dic = {}
    for i in range(n):
        dic[s[i]] = dic.get(s[i], 0) + x[i]
    d = []
    for k, v in dic.items():
        d.append((k, -v, i))
    d.sort(key=lambda x: (x[1], x[2]))
    return [x[0] for x in d]

if __name__ == '__main__':
    print(solution(4, ["a", "b", "c", "d"], [1, 2, 2, 1]) == ['b', 'c', 'a', 'd'])
    print(solution(3, ["x", "y", "z"], [100, 200, 200]) == ['y', 'z', 'x'])
    print(solution(5, ["m", "n", "o", "p", "q"], [50, 50, 30, 30, 20]) == ['m', 'n', 'o', 'p', 'q'])