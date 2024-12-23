def solution(n: str) -> int:
    def check(s: str) -> bool:
        """
        # 判断s中是否含有除了0和1之外的字符
        for i in s:
            if i != '0' and i != '1':
                return False
        return True
        """
        return all(c in "01" for c in s)

    ans = 1
    while not check(n):
        tosub = "".join("1" if c > "1" else c for c in n)
        n = str(int(n) - int(tosub))
        ans += 1
    return ans


if __name__ == "__main__":
    print(solution("10101") == 1)
    print(solution("212") == 2)
    print(solution("1000000") == 1)
    print(solution("123456789") == 9)
    print(solution("9876543210") == 9)
