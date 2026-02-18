test = int(input())

while test:
    string = input()
    dimonds = 0
    less_than = 0
    for c in range(len(string)):
        if string[c] == "<":
            less_than += 1

        if string[c] == ">" and less_than > 0:
            dimonds += 1
            less_than -= 1

    print(dimonds)
    test -= 1
