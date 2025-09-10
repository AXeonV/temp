s = input()
n = len(s)
maxl = 0
head, tail = -1, -1

def expand(st, ed):
	global maxl, head, tail
	while st - 1 >= 0 and ed + 1 < n and s[st - 1] == s[ed + 1]:
		st -= 1
		ed += 1
	if ed - st + 1 > maxl:
		maxl = ed - st + 1
		head, tail = st, ed

for i in range(n):
	expand(i, i)
	expand(i + 1, i)

print(s[head:tail + 1])