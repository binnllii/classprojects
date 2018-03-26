#include <image.h>
#include <PNMreader.h>
int main(int argc, char *argv[]){
    Image i;
    PNMreader(argv[1], i);
}

