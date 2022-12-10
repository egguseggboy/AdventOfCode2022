if __name__ == "__main__":
	file = open("9.txt", "r")
	lines = file.readlines()

	lastHeadPos = [0,0]
	headPos = [0,0]
	tailPos = [0,0]
	positions = []

	longSnake = []
	longSnakePositions = []

	for i in range(10):
		longSnake.append([0,0])

	for line in lines:
		line = line.strip()
		tokens = line.split(" ")
		direction = tokens[0]
		steps = int(tokens[1])

		while (steps > 0):
			steps -= 1
			lastHeadPos = headPos.copy()

			if (direction == 'U'):
				headPos[1] += 1
				longSnake[0][1] += 1
			if (direction == 'D'):
				headPos[1] -= 1
				longSnake[0][1] -= 1
			if (direction == 'L'):
				headPos[0] -= 1
				longSnake[0][0] -= 1
			if (direction == 'R'):
				headPos[0] += 1
				longSnake[0][0] += 1

			# PART 1
			if abs(headPos[0] - tailPos[0]) > 1 or abs(headPos[1] - tailPos[1]) > 1:
				tailPos = lastHeadPos.copy()

			if tailPos not in positions:
				positions.append(tailPos.copy())

			# PART 2
			for i in range(9):
				if abs(longSnake[i][0] - longSnake[i+1][0]) > 1 or abs(longSnake[i][1] - longSnake[i+1][1]) > 1:
					if (longSnake[i][0] < longSnake[i+1][0]):
						longSnake[i+1][0] -= 1
					elif (longSnake[i][0] > longSnake[i+1][0]):
						longSnake[i+1][0] += 1
					
					if (longSnake[i][1] < longSnake[i+1][1]):
						longSnake[i+1][1] -= 1
					elif (longSnake[i][1] > longSnake[i+1][1]):
						longSnake[i+1][1] += 1

			if longSnake[9] not in longSnakePositions:
				longSnakePositions.append(longSnake[9].copy())

	print(len(positions),len(longSnakePositions))

	file.close()