def solution(s: str) -> int:
    s = s.lower()
    count_k = s.count("k")
    count_u = s.count("u")
    return min(count_k, count_u)

if __name__ == '__main__':
    print(solution("AUBTMKAxfuu") == 1)
    print(solution("KKuuUuUuKKKKkkkkKK") == 6)
    print(solution("abcdefgh") == 0)