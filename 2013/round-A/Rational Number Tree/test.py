level = [(1,1)]

def get_next_level(prev_level):
    next_level = []
    for i in prev_level:
        s = i[0]+i[1]
        next_level.append((i[0],s))
        next_level.append((s, i[1]))
    return next_level

total = set()

for _ in range(6):
    sub = set()
    for l in level:
        total.add(l)
        sub.add(l[0])
        sub.add(l[1])
        print("{:2d}/{:2d}".format(*l), end="  ")
    level = get_next_level(level)
    print("  ({})".format(sub))
print(len(total))