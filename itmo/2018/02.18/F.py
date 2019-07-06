mast = {'h': 0, 'd': 1, 'c': 2, 's': 3, '0': -1}
weight = {'J' : 11, 'Q' : 12, 'K': 13, 'A': 1}
mast1 = ['h', 'd', 'c', 's']
weight1 = [i for i in range(11)] + ['J', 'Q', 'K']
weight1[1] = 'A'

def get_card(card):
	ret = [-1, card[-1]]
	card = card[:-1]
	ret[0] = weight.get(card, -1)
	if ret[0] == -1:
		ret[0] = int(card)
	return tuple(ret)

decks = list(map(get_card, input().split()))
# print(decks)

arr = [[] for _ in range(7)]
sz = [0] * 7
cnt = 0
deck_min = {'h': 20,'d': 20,'c': 20,'s': 20}

for i in range(7):
	l = input().split()
	sz[i] = int(l[0])
	arr[i] = list(map(get_card, l[1:]))
	for j in arr[i]:
		deck_min[j[1]] = min(j[0], deck_min[j[1]])
	# print(sz[i], arr[i])
	if sz[i] != 0:
		cnt += 1
# print(deck_min)
cnt11 = 0
while cnt > 0 and cnt11 < 10 ** 3:
	for i in range(7):
		if len(arr[i]) == 0:
			continue
		for j in range(4):
			if len(arr[i]) > 0 and decks[j][0] + 1 == arr[i][-1][0] and decks[j][1] == arr[i][-1][1]:
				print(weight1[arr[i][-1][0]], arr[i][-1][1], end=' ', sep='')
				decks[j] = arr[i][-1]
				arr[i].pop(-1)
				sz[i] -= 1
				if sz[i] == 0:
					cnt -= 1
				break
		if sz[i] == 0 or deck_min[arr[i][-1][1]] != arr[i][-1][0]:
			continue
		for j in range(4):
			if decks[j][1] == '0':
				print(weight1[arr[i][-1][0]], arr[i][-1][1], end=' ', sep='')
				decks[j] = arr[i][-1]
				arr[i].pop(-1)
				sz[i] -= 1
				if sz[i] == 0:
					cnt -= 1
				break
	cnt11 += 1
print()
