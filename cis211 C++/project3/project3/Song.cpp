
#include "Song.h"
#include <iostream>

using namespace std;


//default constructor
Song::Song()
{
    strcpy(title, "no name");
    strcpy(artist, "no artist");
    strcpy(length, "no length");
    strcpy(album, "no album");
}

//constructor initialize title, artist, length, album with passed in value.
Song::Song(const char title[], const char artist[], const char length[], const char album[])
{
    strcpy(this->title, title);
    strcpy(this->artist, artist);
    strcpy(this->length, length);
    strcpy(this->album, album);
}


//getters
void Song::getTitle(char title[]) const
{
    strcpy(title, this->title);
}

void Song::getArtist(char artist[]) const
{
    strcpy(artist, this->artist);
}

void Song::getLength(char length[]) const
{
    strcpy(length, this->length);
}

void Song::getAlbum(char album[]) const
{
    strcpy(album, this->album);
}


//setters
void Song::setTitle(const char title[])
{
    strcpy(this->title, title);
}

void Song::setArtist(const char artist[])
{
    strcpy(this->artist, artist);
}

void Song::setLength(const char length[])
{
    strcpy(this->length, length);
}

void Song::setAlbum(const char album[])
{
    strcpy(this->album, album);
}

// print function
void Song::print() const
{
    cout << title << " -> "
    <<  artist << " -> "
    <<  length << " -> "
    <<  album << endl;
}