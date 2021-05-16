CC = gcc
LIBFDR = libfdr/
OBJ = main.o $(LIBFDR)libfdr.a

all: compile

compile: kripto

kripto: main.o $(LIBFDR)libfdr.a
	$(CC) $(OBJ) -o $@

main.o: main.c
	$(CC) -I $(LIBFDR) -o $@ -c $<

run: clean compile
	./kripto -e ornek_metin encripted
	./kripto -d encripted decripted

clean:
	rm -f *.o
	rm -f kripto
	rm -f encripted
	rm -f decripted

cleanall: clean
	rm -f .kilit
	rm -f ornek_metin
	rm -f *.txt
