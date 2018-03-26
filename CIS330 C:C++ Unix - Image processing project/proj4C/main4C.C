#include <PNMreader.h>
#include <PNMwriter.h>
#include <filters.h>
#include <logging.h>
#include <iostream>



int main(int argc, char *argv[])
{
    
    Color red(250, 250, 255, 0, 0);
    Color blue(250, 250, 0, 0, 255);
    Blender bl;
    bl.SetFactor(.5);
    
    bl.SetInput(red.GetOutput());
    bl.SetInput2(blue.GetOutput());
    
    bl.GetOutput()->Update();
    
    Blender b2;
    b2.SetFactor(.5);
    Color red2(500, 500, 255, 0, 0);
    Color blue2(500, 500, 0, 0, 255);

    
    b2.SetInput(red2.GetOutput());
    b2.SetInput2(blue2.GetOutput());
    
    b2.GetOutput()->Update();

    Blender b3;
    Color red3(1000, 1000, 255, 0, 0);
    Color blue3(1000, 1000, 0, 0, 255);

    
    b3.SetInput(red3.GetOutput());
    b3.SetInput2(blue3.GetOutput());
    
    b3.GetOutput()->Update();

    Blender b4;
    Color red4(2000, 2000, 255, 0, 0);
    Color blue4(2000, 2000, 0, 0, 255);

    
    b4.SetInput(red4.GetOutput());
    b4.SetInput2(blue4.GetOutput());
    
    b4.GetOutput()->Update();

    
    PNMwriter writer;
    writer.SetInput(bl.GetOutput());
    writer.Write(argv[1]);
}
