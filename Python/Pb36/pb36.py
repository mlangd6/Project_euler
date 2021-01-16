# Double base Palyndrom
# I use here a brut function

def func():
    res = 0
    for i in range(1, 1000000):
        if str(i) == "".join(reversed(str(i))):
            a = str(bin(i))
            b = a[2:]
            if b == "".join(reversed(b)):
                res += i
    return res
