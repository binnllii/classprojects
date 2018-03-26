/* This file should contain the 9 functions defined in prototypes.h */

#include <prototypes.h>
#include <math.h>
#define PI 3.14159
void InitializeCircle(Circle *C, double radius, double origin, double originY){
    C -> radius = radius;
    C -> origin = origin;
    C -> originY = originY;
}


void InitializeRectangle(Rectangle *R, double minX, double maxX, double minY, double maxY){
    R -> minX = minX;
    R -> minY = minY;
    R -> maxX = maxX;
    R -> maxY = maxY;
}

void InitializeTriangle(Triangle *T, double pt1X, double pt2X, double minY, double maxY){
    T -> pt2X = pt1X;
    T -> pt2X = pt2X;
    T -> minY = minY;
    T -> maxY = maxY;
}

double GetCircleArea(Circle *C){
    double r = PI*(C->radius)*(C->radius);
    return r;
}

double GetRectangleArea(Rectangle *R){
    double x = ((R->maxX) - (R->minX));
    double y = ((R->maxY) - (R->minY));
    return (x*y);
}

double GetTriangleArea(Triangle *T){
    double x = ((T->pt2X) - (T->pt1X));
    double y = ((T->maxY) - (T->minY));
    return ((x*y)/2);
}

void GetCircleBoundingBox(Circle *C, double *cCircle){
    cCircle[0] = ((C->origin) - (C->radius));
    cCircle[1] = ((C->origin) + (C->radius));
    cCircle[2] = ((C->originY) - (C->radius));
    cCircle[3] = ((C->originY) + (C->radius));
}

void GetRectangleBoundingBox(Rectangle *R, double *rRectangle){
    rRectangle[0] = R->minX;
    rRectangle[1] = R->maxX;
    rRectangle[2] = R->minY;
    rRectangle[3] = R->maxY;
}

void GetTriangleBoundingBox(Triangle *T, double *tTriangle){
    tTriangle[0] = T->pt1X;
    tTriangle[1] = T->pt2X;
    tTriangle[2] = T->minY;
    tTriangle[3] = T->maxY;

}
