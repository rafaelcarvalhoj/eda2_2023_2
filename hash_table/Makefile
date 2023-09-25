MAIN=hash
FLAGS= -Wall -pedantic -Wextra
CC=gcc
#LDFLAG = -lm


#DIRECTORIES
SRCDIR=src
OBJDIR=obj
BINDIR=bin

#SOURCE ARCHIVES
SOURCE=$(wildcard $(SRCDIR)*.c))

#OBJECT ARCHIVES
OBJ=$(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SOURCE))

all: binfolder objfolder $(BINDIR)/$(MAIN).out clean

binfolder:
	@ echo "Gerando pasta bin"
	mkdir -p $(BINDIR)

objfolder:
	@ echo "Gerando pasta obj"
	mkdir -p $(OBJDIR)

bin/$(MAIN).out:	$(OBJECT)
	@ echo "linkando no .out"
	$(CC) $(FLAGS) $(OBJECT) -o $@
	./$(BINDIR)/$(MAIN).out

obj/%.o:	src/%.c list.h hash.h
	@ echo "Compilando objetos"
	$(CC) $(CFLAGS) -c $< -o $@



.PHONY:	clean objfolder binfolder

clean:
	rm -f $(BINDIR)/* $(OBJDIR)/*
	rmdir $(BINDIR) $(OBJDIR)
