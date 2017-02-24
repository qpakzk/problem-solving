N = int(input())
for x in range(1, N + 1):
	for blank in range(1, N - x + 1):
		print(" ", end="")
	for y in range(N - x + 1, N + 1):
		print("*", end="")
	print()
