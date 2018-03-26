#ifndef SONG_OPTIONS
#define SONG_OPTIONS
#include "Song.h"

//Const variables

const int       Title_Width = 25;
const int       Artist_Width = 25;
const int       Length_Width = 15;
const int       Album_Width = 25;
const int       Index_Width = 6;
const int       SONG_CAPACITY = 100;


class SongList
{
public:
    //constructors
    SongList();
    SongList(int initCapacity, const char fileName[]);
    
    //destructors
    ~SongList();
    
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
    Song*    list;
    int     size;
    int     capacity;
    
    void expandList();
};

#endif