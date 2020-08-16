build: BS.c
	gcc -Wall BS.c -o battleship -lncurses -lm
run: battleship
	./battleship input.txt
clean: battleship
	rm battleship