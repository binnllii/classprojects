/* This file should contain your struct definitions for Circle, Triangle, and 
   Rectangle */

typedef struct
{
    double minX;
    double minY;
    double maxX;
    double maxY;        
} Rectangle;

typedef struct
{
    double radius;
    double origin;
    double originY;
} Circle;


typedef struct
{
    double pt1X;
    double pt2X;
    double minY;
    double maxY;
} Triangle;