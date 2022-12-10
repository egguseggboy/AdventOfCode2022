def part1():
	sum = 0
	for line in lines:
		line = line.strip()
		halflen = int(len(line) / 2)
		done = False
		str1 = line[:halflen]
		str2 = line[halflen:]
		for i in str1:
			for j in str2:
				if (not done and i == j):
					if (i.isupper()):
						sum += (ord(i) - 38)
					else:
						sum += (ord(i) - 96)
					done = True
					break
	return sum

def part1Better():
	sum = 0
	for line in lines:
		line = line.strip()
		str1 = line[:len(line)//2]
		str2 = line[len(line)//2:]
		shared = set(str1).intersection(str2).pop()
		sum += ord(shared) - (38 if shared.isupper() else 96)
	return sum

def part2():
	sum = 0
	counter = 0
	group = []
	for line in lines:
		done = False
		line = line.strip()
		group.append(line)
		counter += 1

		if (counter == 3):
			counter = 0
			for i in group[0]:
				for j in group[1]:
					if (not done and i == j):
						for k in group[2]:
							if (not done and i == k):
								if (i.isupper()):
									sum += (ord(i) - 38)
								else:
									sum += (ord(i) - 96)
								done = True
								break
							
			group.clear()
	return sum

def part2Better():
	counter = 0
	sum = 0
	group = []
	for line in lines:
		line = line.strip()
		group.append(line)
		counter += 1

		if (counter == 3):
			shared = set(group[0]).intersection(set(group[1])).intersection(set(group[2])).pop()
			sum += (ord(shared) - (38 if shared.isupper() else 96))
			counter = 0
			group.clear()
	return sum


if __name__ == "__main__":
	file = open("3.txt", "r")
	lines = file.readlines()

	print(part1(), part1Better(), part2(), part2Better())
	file.close()