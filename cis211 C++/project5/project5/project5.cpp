//memory leak detection tool headers
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>


#include "Song.h"
#include "SongList.h"
#include "InputTools.h"
#include <iostream>
#include <cctype>

using namespace std;


void printOptions();
char option();
void readInEntry(SongList& anEntry);
void executeOption(char opt, SongList& list);
void readInArtist(char artist[]);
void readInAlbum(char album[]);


int main()

{
    
    
    char            opt = 'z';
    char            fileName[] = "/Users/BinLi/Desktop/cis211/project5/project5/Songs.txt";
    SongList            list(100, fileName);
    
    
    while (opt != 'q')
    {
        printOptions();
        opt = option();
        executeOption(opt, list);
    }
    
    return 0;
    
    
}

void readInEntry(Song& anEntry)
{
    char    title[MAX_CHAR];
    char    artist[MAX_CHAR];
    char    length[MAX_CHAR];
    char    album[MAX_CHAR];
    
    readString("Please enter a Title: ", title, MAX_CHAR);
    readString("Please enter the Artist: ", artist, MAX_CHAR);
    readString("Please enter the Length: ", length, MAX_CHAR);
    readString("Please enter the album: ", album, MAX_CHAR);
    
    
    anEntry.setTitle(title);
    anEntry.setArtist(artist);
    anEntry.setLength(length);
    anEntry.setAlbum(album);
    
}

void printOptions()

{
    
    cout << "\n\nMusic Library Manager\n\n"
    
    << "v) View all your songs.\n"
    
    << "a) Add a song.\n"
    
    << "r) Search for songs by artist.\n"
    
    << "l) Search for songs by album.\n"
    
    << "s) Delete a song by index number.\n"
    
    << "q) Quit and Save the new list\n"
    
    << "What would you like to do(v,a,r,l,s,q): ";
    
}

char option()

{
    
    char option;
    
    cin >> option;
    
    cin.ignore(100, '\n');
    
    return tolower(option);
    
}

void executeOption(char opt, SongList& list)

{
    int     number;
    Song    entry;
    char    artist[MAX_CHAR];
    char    album[MAX_CHAR];
    
    
    
    switch (opt)
    
    {
            
        case 'v':
            list.printAll();
            break;
            
            
        case 'a':
            readInEntry(entry);
            list.addEntry(entry);
            break;
            
            
        case 'r':
            readInArtist(artist);
            if(list.searchArtist(artist, entry))
            {
                entry.getArtist(artist);
                cout << "Artist Found:";
                entry.print();
                
            }
            else
                cout << "The artist you are looking for doesnt exist!" << endl;
            
            break;
            
            
        case 'l':
            readInAlbum(album);
            if(list.searchAlbum(album, entry))
            {
                entry.getAlbum(album);
                cout << "Album found:";
                entry.print();
                
            }
            else
                cout << "The album you are looking for doesnt exist!" << endl;
            break;
            
            
        case 's':
            number = list.removeNumber();
            list.removeIndex(number);
            break;
            
            
        case 'q':
            list.saveSongs();
            cout << "Bye!" << endl;
            
            break;
            
        default: cout << endl << "Illegal value!" << endl;
            
            break;
            
    }
    
}

void readInArtist(char artist[])
{
    readString("Please enter the Artist you want to search: ", artist, MAX_CHAR);
}

void readInAlbum(char album[])
{
    readString("Please enter the Album you want to search: ", album, MAX_CHAR);
}


