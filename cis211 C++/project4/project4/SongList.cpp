
#include <iostream>
#include <fstream>
#include <iomanip>
#include "SongList.h"


using namespace std;


//default constructor
SongList::SongList()
{
    head = NULL;
    size = 0;
}

SongList::SongList(int initCapacity, const char inpFileName[])
{
    head = NULL;
    size = 0;
    
    loadAddressBook(inpFileName);
}

SongList::~SongList()
{
    Node * curr = head;
    while(head !=NULL)
    {
        curr = head->next;
        delete head;
        head = curr;
    }
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


void SongList::addEntryBeginning(const Song& anEntry)
{
    Node * newNode = new Node(anEntry);
    
    newNode->next = head;
    head = newNode;
    
//    size++;
}

void SongList::saveSongs(const char fileName[])
{
    ofstream out;
    Node * curr;
    char title[MAX_CHAR];
    char artist[MAX_CHAR];
    char length[MAX_CHAR];
    char album[MAX_CHAR];
    
    
    out.open(fileName);
    if(!out)
    {
        out.clear();
        cerr << endl << "Failed to open " << fileName << "for input" << endl;
        exit(1);
    }

    
    for(curr = head; curr; curr=curr->next)
    {
        curr->data.getTitle(title);
        curr->data.getArtist(artist);
        curr->data.getLength(length);
        curr->data.getAlbum(album);

        
        cout << title << ";" << artist << ";" << length << ";" << album << ";" << endl;
        out << title << ";" << artist << ";" << length << ";" << album << ";" << endl;
        
        
    }
    out.close();
    
}

void SongList::printAll() const
{
    int index = 0;
    Node * curr;
    char title[MAX_CHAR];
    char artist[MAX_CHAR];
    char length[MAX_CHAR];
    char album[MAX_CHAR];
    
    
    
    cout << setw(Index_Width) << "Index"
    << setw(Title_Width) << "Name"
    << setw(Artist_Width) << "Artist"
    << setw(Length_Width) << "Length"
    << setw(Album_Width) << "Album" << endl;
    for(curr = head; curr; curr=curr->next)
    {
        curr->data.getTitle(title);
        curr->data.getArtist(artist);
        curr->data.getLength(length);
        curr->data.getAlbum(album);
        
        cout << setw(Index_Width) << index
        << setw(Title_Width)<< title
        << setw(Artist_Width) << artist
        << setw(Length_Width) << length
        << setw(Album_Width) << album << endl;
        index++;
    }
}

int SongList::getSize()
{
    return size;
}

bool SongList::searchArtist(const char artist[], Song& match) const
{
    Node * curr;
    char    currentTitle[MAX_CHAR];
    char    currentArtist[MAX_CHAR];
    char    currentLength[MAX_CHAR];
    char    currentAlbum[MAX_CHAR];
    
    for(curr = head; curr != NULL; curr = curr->next)
    {
        curr->data.getTitle(currentTitle);
        curr->data.getArtist(currentArtist);
        curr->data.getLength(currentLength);
        curr->data.getAlbum(currentAlbum);
        if(strcmp(artist, currentArtist) == 0)
        {
            match.setTitle(currentTitle);
            match.setArtist(currentArtist);
            match.setLength(currentLength);
            match.setAlbum(currentAlbum);
            break;
        }
    }
    if (!curr)
        return false;
    else
        return true;
}

bool SongList::get(int index, Song& anEntry) const
{
    char title[MAX_CHAR];
    char artist[MAX_CHAR];
    char length[MAX_CHAR];
    char album[MAX_CHAR];
    
    if(index < 0 || index >= size)
        return false;
    int i;
    Node* curr = head;
    for(i = 0; i< index; i++)
    {
        curr = curr->next;
    }
    
    curr->data.getTitle(title);
    curr->data.getArtist(artist);
    curr->data.getLength(length);
    curr->data.getAlbum(album);
    anEntry.setTitle (title);
    anEntry.setArtist(artist);
    anEntry.setLength(length);
    anEntry.setAlbum(album);
    return true;
}

bool SongList::searchAlbum(const char album[], Song& match) const
{
    Node * curr;
    char    currentTitle[MAX_CHAR];
    char    currentArtist[MAX_CHAR];
    char    currentLength[MAX_CHAR];
    char    currentAlbum[MAX_CHAR];
    
    for(curr = head; curr != NULL; curr = curr->next)
    {
        curr->data.getTitle(currentTitle);
        curr->data.getArtist(currentArtist);
        curr->data.getLength(currentLength);
        curr->data.getAlbum(currentAlbum);
        if(strcmp(album, currentAlbum) == 0)
        {
            match.setTitle(currentTitle);
            match.setArtist(currentArtist);
            match.setLength(currentLength);
            match.setAlbum(currentAlbum);
            break;
        }
    }
    if (!curr)
        return false;
    else
        return true;
}

void SongList::append(const Song& anEntry)
{
    Node * newNode = new Node(anEntry);
    
    if(!head)
        head = newNode;
    else
    {
        tail->next = newNode;
//        Node * curr = head;
//        
//        while(curr->next)
//        {
//            curr = curr->next;
//        }
        
    }
    size++;
}

void SongList::addSorted(const Song& anEntry)
{
    char title[MAX_CHAR];
    char currTitle[MAX_CHAR];
    
    anEntry.getTitle(title);
    
    Node * newNode = new Node(anEntry);
    
    Node * prev = NULL;
    Node * curr = head;
    
    while(curr)
    {
        curr->data.getTitle(currTitle);
        if(strcmp(title, currTitle) < 0)
            break;
        
        prev = curr;
        curr = curr->next;
    }
    newNode->next = curr;
    
    if(!prev)
        head = newNode;
    else
        prev->next = newNode;
    size++;
}

void SongList::addEntry(const Song& anEntry)
{
    addSorted(anEntry);
}
//int SongList::removeNumber()
//{
//    int number;
//    cout << "What index would you like to remove: ";
//    cin >> number;
//    return number;
//}

void SongList::removeIndex(const Song& aSong)
{
    Node * curr;
    int size = (getSize() - 1);
    cout << size;
    int index = 0;
    
    //get the index to remove
    cout << "Enter the index you would like to remove: ";
    cin >> index;
    while(index > size && index < 0)
    {
        cout << "Enter a valid index to remove.\n";
        cin >> index;
    }
    if(index == 0)
    {
        curr = head->next;
        head->prev = NULL;
        head->next = NULL;
        delete head;
        head = curr;
    }
    else if(index == size)
    {
        curr = tail->prev;
        tail->next = NULL;
        tail->prev = NULL;
        delete tail;
        tail = curr;
    }
    else
    {
        int i = 0;
        for(curr = head; i == index; curr = curr->next)
        {
            if (i == index)
            {
                Node * previous = curr->prev;
                Node * following = curr->next;
                previous->next = following;
                following->prev = previous;
                curr->next = NULL;
                curr->prev = NULL;
                delete curr;
                
            }
            i++;
        }
    }

}
    


   
//void SongList::removeIndex(int num)
//{
//    
//    char    currentTitle[MAX_CHAR];
//    char    currentArtist[MAX_CHAR];
//    char    currentLength[MAX_CHAR];
//    char    currentAlbum[MAX_CHAR];
//    
//    for(int i = num; i < size; i++)
//    {
//        list[i+1].getTitle(currentTitle);
//        list[i+1].getArtist(currentArtist);
//        list[i+1].getLength(currentLength);
//        list[i+1].getAlbum(currentAlbum);
//        
//        list[i].setTitle(currentTitle);
//        list[i].setArtist(currentArtist);
//        list[i].setLength(currentLength);
//        list[i].setAlbum(currentAlbum);
//    }
//    size--;
//}
//
//void SongList::expandList()
//{
//    Song *  tempList;
//    char    title[MAX_CHAR];
//    char    artist[MAX_CHAR];
//    char    length[MAX_CHAR];
//    char    album[MAX_CHAR];
//    
//    
//    //create new array
//    capacity *= 2;
//    tempList = new Song[capacity];
//    
//    //copy over content
//    for (int index = 0; index < size; index++)
//    {
//        list[index].getTitle(title);
//        list[index].getArtist(artist);
//        list[index].getLength(length);
//        list[index].getAlbum(album);
//        
//        tempList[index].setTitle(title);
//        tempList[index].setArtist(artist);
//        tempList[index].setLength(length);
//        tempList[index].setAlbum(album);
//        
//    }
//    
//    delete [] list;
//    
//    list = tempList;
//    tempList = NULL;
//    
//}