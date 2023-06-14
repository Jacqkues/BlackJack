# commande de compilation
CC = gcc -Wall
# commande de uppression 
RM = rm -rf 
# commande de copie
CP = cp -r
#commande pour crée l'archive
TAR =tar -cvzf

# commande de création de dossier
MK = mkdir

# fichier sources
SRC = $(wildcard $(srcdir)*.c)
# fichier entete
HEAD = $(wildcard $(srcdir)*.h)
# fichier objets
OBJ = $(subst $(srcdir), $(bindir),$(SRC:.c=.o))
# nom du programme
PROG = $(bindir)exe
# fichier restauration
RES = $(wildcard $(savedir)*)

# repertoire qui contient les sources, et les entetes du projet
srcdir = ./src/
# repertoire qui contient les objets, et executables du projet
bindir = ./bin/
# repertoire qui contient la documentation technique du projet
docdir = ./doc/
# repertoire qui contient les fichiers de sauvegarde du projet
savedir = ./save/
# repertoire d'archive
archivedir = dumoradane-tp9
#nom de l'executable
exename = blackjack


all : $(PROG)

# compilation du programme
$(PROG) : $(OBJ) 
	$(CC) $(OBJ) -o $(exename) -lm

# compilation des objets
$(bindir)%.o : $(srcdir)%.c 
	$(CC) -c $^ -o $@

# sauvegarde des fichiers
.PHONY : save
save : $(SRC) $(HEAD)
	$(CP) $(SRC) $(savedir)
	$(CP) $(HEAD) $(savedir)

# generation de la documentation
.PHONY : doc
doc : 
	doxygen Doxyfile

# restauration des fichiers
restore : $(RES)
	$(CP) $(RES) $(srcdir)

# genere l'archive pour le rendu
give : 
	$(MK) $(archivedir)
	$(CP) $(srcdir) $(archivedir)
	$(CP) $(savedir) $(archivedir)
	$(CP) $(docdir) $(archivedir)
	$(CP) $(bindir) $(archivedir)
	$(CP) Makefile $(archivedir)
	$(CP) Doxyfile $(archivedir)
	$(CP) readme.md $(archivedir)
	$(TAR) $(archivedir).tar.gz $(archivedir)
	$(RM)$(archivedir)



# effacement des objets
.PHONY : clean
clean : 
	$(RM) $(OBJ) $(PROG)