with open("../../tmp/iterator.txt", "w") as file:
    for i in range(5000000):
        file.write(str(i) + "\n")
