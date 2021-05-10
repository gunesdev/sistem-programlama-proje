all: compile

compile:
	gcc -I ./libfdr -o ./lib/dllist.o -c ./libfdr/dllist.c
	gcc -I ./libfdr -o ./lib/fields.o -c ./libfdr/fields.c
	gcc -I ./libfdr -o ./lib/jrb.o -c ./libfdr/jrb.c
	gcc -I ./libfdr -o ./lib/jval.o -c ./libfdr/jval.c
	gcc -I ./libfdr -o ./kripto ./lib/dllist.o ./lib/fields.o ./lib/jrb.o ./lib/jval.o ./main.c
