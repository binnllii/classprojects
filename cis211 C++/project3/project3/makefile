CC = g++
CPPFLAGS = -std=c++11 -g -c -Wall
OBJTS = Song.o SongList.o InputTools.o project3.o

app: $(OBJTS)

project3.o: Song.h SongList.h InputTools.h

Song.o: Song.h InputTools.h SongList.h

SongList.o: SongList.h InputTools.h Song.h

InputTools.o: InputTools.h

clean:
rm project3 $(OBJTS)
