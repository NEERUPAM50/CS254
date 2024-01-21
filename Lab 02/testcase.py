from random import randint
file = open("input_5.txt", "w")
tests = 20

file.write(f"{tests}\n")

for tt in range(tests):
    n = 2**(tt+1)
    # m = n//2

    file.write(f"{n}\n") #{m}\n

    a = []
    # b = []

    for i in range(n):
        a.append(randint(1, n))

    # for j in range(m):
    #     b.append(randint(1, m))

    a.sort()
    # b.sort()

    astr = " ".join(str(i) for i in a)
    # bstr = " ".join(str(i) for i in b)

    file.write(f"{astr}\n") # n{bstr}
