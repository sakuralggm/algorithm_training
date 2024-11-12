def solution(s: str) -> str:
    s = s.replace("a", "%100")
    return s
if __name__ == '__main__':
    print(solution(s="abcdwa") == '%100bcdw%100')
    print(solution(s="banana") == 'b%100n%100n%100')
    print(solution(s="apple") == '%100pple')