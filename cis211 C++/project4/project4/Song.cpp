
#include "Song.h"
#include <iostream>

using namespace std;


//default constructor
Song::Song()
{
    title = new char[strlen("no name") + 1];
    strcpy(title, "no name");
    artist = new char[strlen("no artist") + 1];
    strcpy(artist, "no artist");
    length = new char[strlen("no length") + 1];
    strcpy(length, "no length");
    album = new char[strlen("no album") + 1];
    strcpy(album, "no album");
}

//constructor initialize title, artist, length, album with passed in value.
Song::Song(const char title[], const char artist[], const char length[], const char album[])
{
    this->title = new char[strlen(title) + 1];
    strcpy(this->title, title);
    this->artist = new char[strlen(artist) + 1];
    strcpy(this->artist, artist);
    this->length = new char[strlen(length) + 1];
    strcpy(this->length, length);
    this->album = new char[strlen(album) + 1];
    strcpy(this->album, album);
}

//destructor
Song::~Song()
{
    if(title != NULL)
        delete [] title;
    if(artist != NULL)
        delete [] artist;
    if(length != NULL)
        delete [] length;
    if(album != NULL)
        delete [] album;
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
    if(this->title != NULL)
        delete [] this-> title;
    this->title = new char[strlen(title) + 1];
    strcpy(this->title, title);
}

void Song::setArtist(const char artist[])
{
    if(this->artist != NULL)
        delete [] this-> artist;
    this->artist = new char[strlen(title)+ 1];
    strcpy(this->artist, artist);
}

void Song::setLength(const char length[])
{
    if(this->length != NULL)
        delete [] this-> length;
    this->length = new char[strlen(length)+ 1];
    strcpy(this->length, length);
}

void Song::setAlbum(const char album[])
{
    if(this->album !=NULL)
        delete [] this->album;
    this->album = new char[strlen(album) + 1];
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