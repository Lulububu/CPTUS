# Makefile
# Date: sam. 25/07/2013
#
# Actions :
#	make all 		: compilation (default)
#	make clean 		: remove .o
#	make mrproper 	: remove .o and EXE


CC=gcc
EXEC=rtp_serv
SRC=src/
INC=include/
INC_COMMON=../common/include/
SRC_COMMON=../common/src/

# Linker Flag
LDFLAGS=-lpthread
# Compilation Flag
CFLAGS=-ggdb -I$(INC) -I$(INC_COMMON) -Wall

#ALL
all: $(EXEC)

##################################################

# MAIN
main.o: main.c
	@echo $^
	@$(CC) -c $^ $(CFLAGS)

# Connections management
Crypto_manager.o: $(SRC)Crypto_manager.c
	@echo $^
	@$(CC) -c $^ $(CFLAGS)

# Socket UDP
Socket.o: $(SRC_COMMON)Socket.c
	@echo $^
	@$(CC) -c $^ $(CFLAGS)

# string data through socket (parse)
Data.o: $(SRC_COMMON)Data.c
	@echo $^
	@$(CC) -c $^ $(CFLAGS)

##################################################

# Link edition and EXE creation
$(EXEC): main.o Crypto_manager.o Socket.o Data.o
	@echo "Link output files..."
	@$(CC) -o $@  $^ $(LDFLAGS)
	@echo "OK"
	@echo "Program name is $(EXEC)"

##################################################

clean:
	rm -f *.o

##################################################

mrproper: clean
	rm -f $(EXEC)

# End Makefile