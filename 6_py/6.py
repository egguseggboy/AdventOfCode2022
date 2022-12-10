def calc(line, part):
	part = 4 if (part == 1) else 14
	for i in range(part, len(line)):
		count = 0
		fourchars = line[i-part:i]
		for c in fourchars:
			if fourchars.count(c) > 1:
				count = count + 1
		if count == 0:
			print(fourchars)
			return i

if __name__ == "__main__":
	file = open("6.txt", "r")
	line = file.readline()
	line = line.strip()

	print(calc(line, 1))
	print(calc(line, 2))

	file.close()