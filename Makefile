all: ttt_main.o ttt_lib.o
	gcc -o ttt ttt_main.o ttt_lib.o

clean: 
	rm -rf ttt *.o *~

