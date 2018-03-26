
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
    void saveSongs(const char fileName[]);
    int getSize();
    bool searchArtist(const char title[], Song& match) const;
    bool get(int index, Song& anEntry) const;
    bool searchAlbum(const char album[], Song& match) const;
    int removeNumber();
    void removeIndex(const Song& aSong);
    
    
    //set functions
    void addEntry(const Song& anEntry);
    void append(const Song& anEntry);
    void addSorted(const Song& anEntry);
    void addEntryBeginning(const Song& anEntry);
    void loadAddressBook(const char fileName[]);
    
private:
    struct Node
    {
        Song    data;
        Node * next;
        Node * prev;
        
        Node(const Song& aData)
        {
            char    title[MAX_CHAR];
            char    artist[MAX_CHAR];
            char    length[MAX_CHAR];
            char    album[MAX_CHAR];
            
            aData.getTitle(title);
            aData.getArtist(artist);
            aData.getLength(length);
            aData.getAlbum(album);
            
            data.setTitle(title);
            data.setArtist(artist);
            data.setLength(length);
            data.setAlbum(album);
            next = NULL;
        }
    };
    
    
    Node *  head, * tail;
    int     size;
};

#endif