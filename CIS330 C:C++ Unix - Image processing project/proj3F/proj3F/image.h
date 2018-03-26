#include <stdio.h>
#ifndef IMAGE_H
#define IMAGE_H

class source;
class Image
{
private:
    unsigned char *buffer;
    
    int height, width, maxval;
    source * sour;

public:
    Image(void);
    void setData2(int,int);
    void setValues(int, int);
    int getHeight() const;
    int getWidth() const;
    int getMaxVal() const;
    void setData();
    unsigned char* getData() const;
    void Update() const;
    void setSource(source * s);
    void setWidth(int);
    void setHeight(int);
};


#endif
