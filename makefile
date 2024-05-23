hepsi: derle calistir

derle:
	gcc -I ./include/ -o ./lib/CANLI.o -c ./src/CANLI.c
	gcc -I ./include/ -o ./lib/BITKI.o -c ./src/BITKI.c
	gcc -I ./include/ -o ./lib/BOCEK.o -c ./src/BOCEK.c
	gcc -I ./include/ -o ./lib/SINEK.o -c ./src/SINEK.c
	gcc -I ./include/ -o ./lib/PIRE.o -c ./src/PIRE.c
	gcc -I ./include/ -o ./lib/HABITAT.o -c ./src/HABITAT.c
	gcc -I ./include/ -o ./bin/TEST ./lib/CANLI.o ./lib/BITKI.o ./lib/BOCEK.o ./lib/SINEK.o ./lib/PIRE.o ./lib/HABITAT.o ./src/TEST.c
		
calistir:
	./bin/TEST