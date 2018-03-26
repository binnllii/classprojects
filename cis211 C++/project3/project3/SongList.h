
#ifndef SONG_OPTIONS
#define SONG_OPTIONS
#include "song.h"

//Const variables

const int       Title_Width = 24;
const int       Artist_Width = 24;
const int       Length_Width = 12;
const int       Album_Width = 18;
const int       Index_Width = 6;
const int       SONG_CAPACITY = 100;


class SongList
{
public:
    //constructors
    SongList();
    SongList(const char fileName[]);
    
    //get functions
    void printAll() const;
    void saveSongs();
    int getSize();
    bool searchArtist(const char title[], Song& match) const;
    bool get(int index, Song& anEntry) const;
    bool searchAlbum(const char album[], Song& match) const;
    int removeNumber();
    void removeIndex(int num);
    
    //set functions
    void addEntry(const Song& anEntry);
    void loadAddressBook(const char fileName[]);
    
private:
    int     size;
    Song    list[SONG_CAPACITY];
    char    fileName[MAX_CHAR];
    
};

#endif