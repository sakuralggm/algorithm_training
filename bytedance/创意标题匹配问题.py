import re

def solution(n, template, titles):
    # Convert template to regex pattern
    pattern = re.sub(r'\{.*?\}', '.*', template)
    pattern = f"^{pattern}$"

    # Check each title against the pattern
    results = []
    for title in titles:
        if re.match(pattern, title):
            results.append("True")
        else:
            results.append("False")

    return ",".join(results)

if __name__ == "__main__":
    #  You can add more test cases here
    testTitles1 = ["adcdcefdfeffe", "adcdcefdfeff", "dcdcefdfeffe", "adcdcfe"]
    testTitles2 = ["CLSomGhcQNvFuzENTAMLCqxBdj", "CLSomNvFuXTASzENTAMLCqxBdj", "CLSomFuXTASzExBdj", "CLSoQNvFuMLCqxBdj", "SovFuXTASzENTAMLCq", "mGhcQNvFuXTASzENTAMLCqx"]
    testTitles3 = ["abcdefg", "abefg", "efg"]

    print(solution(4, "ad{xyz}cdc{y}f{x}e", testTitles1) == "True,False,False,True" )
    print(solution(6, "{xxx}h{cQ}N{vF}u{XTA}S{NTA}MLCq{yyy}", testTitles2) == "False,False,False,False,False,True" )
    print(solution(3, "a{bdc}efg", testTitles3) == "True,True,False" )