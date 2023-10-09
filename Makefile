build:
	gcc -o tema1 task1.c main.c
run:
	./tema1
clean:
	rm tema1
valgrind:
	valgrind --leak-check=yes --track-origins=yes ./test