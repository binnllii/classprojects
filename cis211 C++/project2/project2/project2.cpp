

#include <iostream>

#include <cstring>

#include <fstream>

#include <iomanip>

#include <cctype>

using namespace std;



//Const variables

const int       MAX_CHAR = 100;

const int       Title_Width = 20;

const int       Artist_Width = 20;

const int       Length_Width = 20;

const int       Album_Width = 20;



//Create type musicLibrary

struct musicLib

{
    
    char    title[MAX_CHAR];
    
    char    artist[MAX_CHAR];
    
    char    length[MAX_CHAR];
    
    char    album[MAX_CHAR];
    
};



//Functions







void printOptions();



char option();



void readinSearch(char search[]);



void readInput (const char prompt[], char inputStr[], int maxChar);



void executeOption(char opt, musicLib list[], int& listSize);



void allSongs(const musicLib list[], int listSize);



void readInEntry(musicLib& anEntry);



void addEntry(const musicLib& anEntry, musicLib list[], int& listSize);



bool artistSearch(const char search[], const musicLib list[], int listSize);



bool albumSearch(const char search[], const musicLib list[], int listSize);



void loadFile(const char fileName[], musicLib list[], int& listSize);



void saveFile(const char fileName[], const musicLib list[], int listSize);



void removeSong(musicLib list[], int& listSize);



//Main



int main()

{
    
    int            listSize;
    
    char           opt;
    
    musicLib   list[MAX_CHAR];
    
    char           fileName[] = "/Users/BinLi/Desktop/cis211/project2/project2/songs.txt";
    
    
    
    loadFile(fileName, list, listSize);
    
    printOptions();
    
    opt = option();
    
    while (opt != 'q')
        
    {
        
        executeOption(opt, list, listSize);
        
        printOptions();
        
        opt = option();
        
    }
    
    
    
    saveFile(fileName, list, listSize);
    
    return 0;
    
    
    
}



//Display menu



void printOptions()

{
    
    cout << "\n\nMusic Library Manager\n\n"
    
    << "v) View all your songs.\n"
    
    << "a) Add a song.\n"
    
    << "r) Search for songs by artist.\n"
    
    << "l) Search for songs by album.\n"
    
    << "s) Delete a song by index number.\n"
    
    << "q) Quit\n"
    
    << "What would you like to do(v,a,r,l,s,q): ";
    
}



//Read in option



char option()

{
    
    char option;
    
    cin >> option;
    
    cin.ignore(100, '\n');
    
    return tolower(option);
    
}



//Switching different cases



void executeOption(char opt, musicLib list[], int& listSize)

{
    
    musicLib    entry;
    
    char            search[MAX_CHAR];
    
    
    
    switch (opt)
    
    {
            
        case 'v': allSongs(list, listSize);
            
            break;
            
            
            
        case 'a': readInEntry(entry);
            
            addEntry(entry, list, listSize);
            
            allSongs(list, listSize);
            
            break;
            
            
            
        case 'r': readinSearch(search);
            
            artistSearch(search, list, listSize);
            
            break;
            
            
            
        case 'l': readinSearch(search);
            
            albumSearch(search, list, listSize);
            
            break;
            
            
            
        case 's': removeSong(list, listSize);
            
            break;
            
            
            
        case 'q':
            
            cout << "Bye!" << endl;
            
            break;
            
            
            
            
            
            
            
        default: cout << endl << "Illegal value!" << endl;
            
            break;
            
    }
    
}



//Display songs in different columns



void allSongs(const musicLib list[], int listSize)

{
    
    int index;
    
    cout << setw(Title_Width) << "Title"
    
    << setw(Artist_Width) << "Artist"
    
    << setw(Length_Width) << "Length"
    
    << setw(Album_Width) << "Album"
    
    << endl;
    
    
    
    for(index = 0; index < listSize; index++)
        
    {
        
        cout << index << setw(Title_Width) << list[index].title
        
        << setw(Artist_Width) << list[index].artist
        
        << setw(Length_Width) << list[index].length
        
        << setw(Album_Width) << list[index].album
        
        << endl;
        
    }
    
    
    
    cout << "Number of record: " << listSize << endl;
    
}

void readInput (const char prompt[], char inputStr[], int maxChar)

{
    
    cout << endl << prompt;
    
    //read until new line
    
    cin.get(inputStr, maxChar, '\n');
    
    while(!cin)
        
    {
        
        cin.clear ();
        
        cin.ignore (100, '\n');
        
        cout << endl << prompt;
        
        cin.get(inputStr, maxChar, '\n');
        
    }
    
    
    
    
    
    
    
    //Discard new line
    
    
    
    cin.ignore (100, '\n');
    
}

//Read in keywords to search for in music library



void readinSearch(char search[])

{
    
    readInput("Please enter the name of the artist/album: ", search, MAX_CHAR);
    
}



//Search for artist in music library



bool artistSearch(const char search[], const musicLib list[], int listSize)



{
    
    int         index;
    
    bool found = false;
    
    cout << "Here are the matched songs: " << endl;
    
    for(index = 0; index < listSize; index++)
        
    {
        
        if(strcmp(search, list[index].artist) == 0)
            
        {
            
            cout << index << setw(Title_Width) << list[index].title
            
            << setw(Artist_Width) << list[index].artist
            
            << setw(Length_Width) << list[index].length
            
            << setw(Album_Width) << list[index].album
            
            << endl;
            
            found = true;
            
        }
        
    }
    
    
    
    //Display the error msg when no matches are found
    
    
    
    if ( found == false)
        
    {
        
        cout << "No matches found." << endl;
        
    }
    
    
    
    return found;
    
}



//Search keyword in album column.



bool albumSearch(const char search[], const musicLib list[], int listSize)

{
    
    int         index;
    
    bool found = false;
    
    
    
    cout << "Here are the matched songs: " << endl;
    
    for(index=0; index<listSize; index++)
        
    {
        
        
        
        if(strcmp(search, list[index].album) == 0)
            
        {
            
            // cout << list[index] << endl;
            
            
            
            cout << index << setw(Title_Width) << list[index].title
            
            << setw(Artist_Width) << list[index].artist
            
            << setw(Length_Width) << list[index].length
            
            << setw(Album_Width) << list[index].album
            
            << endl;
            
            found = true;
            
        }
        
    }
    
    if ( found == false)
        
    {
        
        cout << "No matches found." << endl;
        
    }
    
    return found;
    
    
    
}







void readInEntry(musicLib& anEntry)

{
    
    char    title[MAX_CHAR];
    
    char    artist[MAX_CHAR];
    
    char    length[MAX_CHAR];
    
    char    album[MAX_CHAR];
    
    
    
    
    
    readInput("Please enter the title: ", title, MAX_CHAR);
    
    readInput("Please enter the artist: ", artist, MAX_CHAR);
    
    readInput("Please enter the length of the song: ", length, MAX_CHAR);
    
    readInput("Please enter the name of the album: ", album, MAX_CHAR);
    
    
    
    //populate the passed in object
    
    strcpy(anEntry.title, title);
    
    strcpy(anEntry.artist, artist);
    
    strcpy(anEntry.length, length);
    
    strcpy(anEntry.album, album);
    
}



//Add info for each column.



void addEntry(const musicLib& anEntry, musicLib list[], int& listSize)

{
    
    strcpy(list[listSize].title, anEntry.title);
    
    strcpy(list[listSize].artist, anEntry.artist);
    
    strcpy(list[listSize].length, anEntry.length);
    
    strcpy(list[listSize].album, anEntry.album);
    
    listSize++;
    
    
    
}



//Load the txt file



void loadFile(const char fileName[], musicLib list[], int& listSize)



{
    
    ifstream        in;
    
    char            title[MAX_CHAR];
    
    char            artist[MAX_CHAR];
    
    char            length[MAX_CHAR];
    
    char            album[MAX_CHAR];
    
    musicLib    anEntry;
    
    
    
    in.open (fileName);
    
    if(!in)
        
    {
        
        in.clear();
        
        cerr << endl << "Fail to open " << fileName << " for input!" << endl << endl;
        
        exit(1);
        
    }
    
    
    
    in.get(title, MAX_CHAR, ';');
    
    while (!in.eof())
        
    {
        
        in.get();
        
        in.get(artist, MAX_CHAR, ';');
        
        in.get();
        
        in.get(length, MAX_CHAR, ';');
        
        in.get();
        
        in.get(album, MAX_CHAR, ';');
        
        in.get();
        
        in.ignore(MAX_CHAR, '\n');
        
        
        
        
        
        strcpy(anEntry.title, title);
        
        strcpy(anEntry.artist, artist);
        
        strcpy(anEntry.length, length);
        
        strcpy(anEntry.album, album);
        
        
        
        addEntry(anEntry, list, listSize);
        
        
        
        in.get(title, MAX_CHAR, ';');
        
    }
    
    in.close();
    
}



//Save changes



void saveFile(const char fileName[], const musicLib list[], int listSize)



{
    
    ofstream    out;
    
    int         i;
    
    out.open    (fileName);
    
    if(!out)
        
    {
        
        out.clear();
        
        cerr << endl << "Fail to open " << fileName << " for output!" << endl << endl;
        
        exit(1);
        
    }
    
    
    
    
    
    
    
    for(i = 0; i < listSize; i++)
        
    {
        
        out << list[i].title << ';'
        
        << list[i].artist << ';'
        
        << list[i].length << ';'
        
        << list[i].album << ';'
        
        << endl;
        
    }
    
    out.close();
    
}





void removeSong(musicLib list[], int& listSize)

{
    
    int     i;
    
    cout << "Enter the index number of the song to delete: " << endl;
    
    cin >> i;
    
    if (i < 0 || i >= listSize)
        
    {
        
        cout << "Illegal value." << endl;
        
        return;
        
    }
    
    
    
    if (i == listSize - 1)
        
    {
        
        listSize = listSize - 1;
        
    }
    
    
    
    else
        
    {
        
        strcpy(list[i].title, list[listSize - 1].title);
        
        strcpy(list[i].artist, list[listSize - 1].artist);
        
        strcpy(list[i].length, list[listSize - 1].length);
        
        strcpy(list[i].album, list[listSize - 1].album);
        
        listSize = listSize - 1;
        
    }
    
    
    
    cout << "Updated reordered list." << endl;
    
    allSongs(list, listSize);
    
    
    
}














