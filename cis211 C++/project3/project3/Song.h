
#ifndef ENTRY_LIST
#define ENTRY_LIST

const int MAX_CHAR = 101;


class Song
{
public:
    //constructor
    Song();
    Song(const char title[], const char artist[], const char length[], const char album[]);
    
    //getter functions
    void getTitle(char title[]) const;
    void getArtist(char artist[]) const;
    void getLength(char length[]) const;
    void getAlbum(char album[]) const;
    void print() const;
    
    //setter functions
    void setTitle(const char title[]);
    void setArtist(const char artist[]);
    void setLength(const char length[]);
    void setAlbum(const char album[]);
    
private:
    char    title[MAX_CHAR];
    
    char    artist[MAX_CHAR];
    
    char    length[MAX_CHAR];
    
    char    album[MAX_CHAR];
    
};

#endif
