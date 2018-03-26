#include <iostream>
#include <fstream>
#include <iomanip>
#include "SongList.h"

using namespace std;


//default constructor
SongList::SongList()
{
    capacity = SONG_CAPACITY;
    list = new Song[capacity];
    size = 0;
}

SongList::SongList(int initCapacity, const char inpFileName[])
{
    capacity = initCapacity;
    list = new Song[capacity];
    size = 0;
    
    loadAddressBook(inpFileName);
}

//destructor
SongList::~SongList()
{
    if(list != NULL)
        delete [] list;
}


void SongList::loadAddressBook(const char fileName[])
{
    ifstream in;
    char title[MAX_CHAR];
    char artist[MAX_CHAR];
    char length[MAX_CHAR];
    char album[MAX_CHAR];
    Song anEntry;
    
    in.open(fileName);
    if(!in)
    {
        in.clear();
        cerr << endl << "Failed to open " << fileName << "for input" << endl;
        exit(1);
    }
    in.get (title, MAX_CHAR, ';');
    while(!in.eof())
    {
        
        in.get();
        
        in.get(artist, MAX_CHAR, ';');
        
        in.get();
        
        in.get(length, MAX_CHAR, ';');
        
        in.get();
        
        in.get(album, MAX_CHAR, ';');
        
        in.get();
        
        in.ignore(MAX_CHAR, '\n');
        
        anEntry.setTitle(title);
        anEntry.setArtist(artist);
        anEntry.setLength(length);
        anEntry.setAlbum(album);
        
        addEntry(anEntry);
        
        
        
        in.get(title, MAX_CHAR, ';');
        
        
    }
    in.close();
}


void SongList::addEntry(const Song& anEntry)
{
    char title[MAX_CHAR];
    char artist[MAX_CHAR];
    char length[MAX_CHAR];
    char album[MAX_CHAR];
    
    anEntry.getTitle(title);
    anEntry.getArtist(artist);
    anEntry.getLength(length);
    anEntry.getAlbum(album);
    list[size].setTitle(title);
    list[size].setArtist(artist);
    list[size].setLength(length);
    list[size].setAlbum(album);
    
    size++;
}

void SongList::saveSongs()
{
    ofstream out;
    int index;
    char title[MAX_CHAR];
    char artist[MAX_CHAR];
    char length[MAX_CHAR];
    char album[MAX_CHAR];
    
    //  out.open(fileName);
    if(!out)
    {
        out.clear();
        //     cerr << endl << "Fail to open " << fileName << " for output!" << endl << endl;
        exit(1);
    }
    
    for(index = 0; index < size; index++)
    {
        list[index].getTitle(title);
        list[index].getArtist(artist);
        list[index].getLength(length);
        list[index].getAlbum(album);
        
        
        
        cout << title << ";" << artist << ";" << length << ";" << album << ";" << endl;
        out << title << ";" << artist << ";" << length << ";" << album << ";" << endl;
        
        
    }
    out.close();
    
}

void SongList::printAll() const
{
    if(size == 0)
    {
        cout << "list is empty" << endl;
        return;
    }
    int index;
    char title[MAX_CHAR];
    char artist[MAX_CHAR];
    char length[MAX_CHAR];
    char album[MAX_CHAR];
    
    
    
    cout << right << setw(Index_Width) << "Index"
    << setw(Title_Width) << "Name"
    << setw(Artist_Width) << "Artist"
    << setw(Length_Width) << "Length"
    << setw(Album_Width) << "Album" << endl;
    for(index = 0; index < size; index++)
    {
        list[index].getTitle(title);
        list[index].getArtist(artist);
        list[index].getLength(length);
        list[index].getAlbum(album);
        
        cout << right << setw(Index_Width) << index
        << setw(Title_Width)<< title
        << setw(Artist_Width) << artist
        << setw(Length_Width) << length
        << setw(Album_Width) << album << endl;
    }
}

int SongList::getSize()
{
    return size;
}

bool SongList::searchArtist(const char artist[], Song& match) const
{
    int     index;
    char    currentTitle[MAX_CHAR];
    char    currentArtist[MAX_CHAR];
    char    currentLength[MAX_CHAR];
    char    currentAlbum[MAX_CHAR];
    
    for(index = 0; index < size; index++)
    {
        list[index].getTitle(currentTitle);
        list[index].getArtist(currentArtist);
        list[index].getLength(currentLength);
        list[index].getAlbum(currentAlbum);
        if(strcmp(artist, currentArtist) == 0)
        {
            match.setTitle(currentTitle);
            match.setArtist(currentArtist);
            match.setLength(currentLength);
            match.setAlbum(currentAlbum);
            break;
        }
    }
    if (index == size)
        return false;
    else
        return true;
}

bool SongList::get(int index, Song& anEntry) const
{
    char Title[MAX_CHAR];
    char Artist[MAX_CHAR];
    char Length[MAX_CHAR];
    char Album[MAX_CHAR];
    
    if(index < 0 || index >= size)
        return false;
    
    list[index].getTitle (Title);
    list[index].getArtist (Artist);
    list[index].getLength (Length);
    list[index].getAlbum (Album);
    anEntry.setTitle (Title);
    anEntry.setArtist(Artist);
    anEntry.setLength(Length);
    anEntry.setAlbum(Album);
    return true;
}

bool SongList::searchAlbum(const char album[], Song& match) const
{
    int     index;
    char    currentTitle[MAX_CHAR];
    char    currentArtist[MAX_CHAR];
    char    currentLength[MAX_CHAR];
    char    currentAlbum[MAX_CHAR];
    
    for(index = 0; index < size; index++)
    {
        list[index].getTitle(currentTitle);
        list[index].getArtist(currentArtist);
        list[index].getLength(currentLength);
        list[index].getAlbum(currentAlbum);
        if(strcmp(album, currentAlbum) == 0)
        {
            match.setTitle(currentTitle);
            match.setArtist(currentArtist);
            match.setLength(currentLength);
            match.setAlbum(currentAlbum);
            break;
        }
    }
    if (index == size)
        return false;
    else
        return true;
}

int SongList::removeNumber()
{
    int number;
    cout << "What index would you like to remove: ";
    cin >> number;
    return number;
}

void SongList::removeIndex(int num)
{
    
    char    currentTitle[MAX_CHAR];
    char    currentArtist[MAX_CHAR];
    char    currentLength[MAX_CHAR];
    char    currentAlbum[MAX_CHAR];
    
    for(int i = num; i < size; i++)
    {
        list[i+1].getTitle(currentTitle);
        list[i+1].getArtist(currentArtist);
        list[i+1].getLength(currentLength);
        list[i+1].getAlbum(currentAlbum);
        
        list[i].setTitle(currentTitle);
        list[i].setArtist(currentArtist);
        list[i].setLength(currentLength);
        list[i].setAlbum(currentAlbum);
    }
    size--;
}

void SongList::expandList()
{
    Song *  tempList;
    char    title[MAX_CHAR];
    char    artist[MAX_CHAR];
    char    length[MAX_CHAR];
    char    album[MAX_CHAR];
    
    
    //create new array
    capacity *= 2;
    tempList = new Song[capacity];
    
    //copy over content
    for (int index = 0; index < size; index++)
    {
        list[index].getTitle(title);
        list[index].getArtist(artist);
        list[index].getLength(length);
        list[index].getAlbum(album);
        
        tempList[index].setTitle(title);
        tempList[index].setArtist(artist);
        tempList[index].setLength(length);
        tempList[index].setAlbum(album);
        
    }
    
    delete [] list;
    
    list = tempList;
    tempList = NULL;
    
}