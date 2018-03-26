#include <stdlib.h>
#include <string.h>

class Image 
{
    private:
        int height;
        int width;
        unsigned char *buffer;        

    public:
        Image(void);
        Image(int height, int width, unsigned char *buffer);
        Image(const Image &img);

        int getHeight();
        int getWidth();
        void ResetSize(int width, int height);
        void setData(unsigned char *b);
        unsigned char* getData();
};
