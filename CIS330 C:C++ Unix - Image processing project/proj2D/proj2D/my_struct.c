/* This file should contain the 9 functions defined in prototypes.h */
#include <my_struct.h>
#include <prototypes.h>
#include <math.h>
#define PI 3.14159



void InitializeCircle(struct Shape *C, double radius, double origin, double originY){
    C->st = ci;
    C->ft.GetArea = GetCircleArea;
    C->ft.GetBoundingBox = GetCircleBoundingBox;  
    C->su.c.radius = radius;
    C->su.c.origin = origin;
    C->su.c.originY = originY;
}


void InitializeRectangle(struct Shape *R, double minX, double maxX, double minY, double maxY){
    R->st = re;
    R->ft.GetArea = GetRectangleArea;
    R->ft.GetBoundingBox = GetRectangleBoundingBox;
    R->su.r.minX = minX;
    R->su.r.minY = minY;
    R->su.r.maxX = maxX;
    R->su.r.maxY = maxY;
}

void InitializeTriangle(struct Shape *T, double pt1X, double pt2X, double minY, double maxY){
    T->st = tr;
    T->ft.GetArea = GetTriangleArea;
    T->ft.GetBoundingBox = GetTriangleBoundingBox;
    T->su.t.pt2X = pt1X;
    T->su.t.pt2X = pt2X;
    T->su.t.minY = minY;
    T->su.t.maxY = maxY;
}

double GetCircleArea(struct Shape *C){
    
    double r = PI*(C->su.c.radius)*(C->su.c.radius);
    return r;
}

double GetRectangleArea(struct Shape *R){
    double x = ((R->su.r.maxX) - (R->su.r.minX));
    double y = ((R->su.r.maxY) - (R->su.r.minY));
    return (x*y);
}

double GetTriangleArea(struct Shape *T){
    double x = ((T->su.t.pt2X) - (T->su.t.pt1X));
    double y = ((T->su.t.maxY) - (T->su.t.minY));
    return ((x*y)/2);
}

void GetCircleBoundingBox(struct Shape *C, double *cCircle){
    
    cCircle[0] = ((C->su.c.origin) - (C->su.c.radius));
    cCircle[1] = ((C->su.c.origin) + (C->su.c.radius));
    cCircle[2] = ((C->su.c.originY) - (C->su.c.radius));
    cCircle[3] = ((C->su.c.originY) + (C->su.c.radius));
}

void GetRectangleBoundingBox(struct Shape *R, double *rRectangle){
    rRectangle[0] = R->su.r.minX;
    rRectangle[1] = R->su.r.maxX;
    rRectangle[2] = R->su.r.minY;
    rRectangle[3] = R->su.r.maxY;
}

void GetTriangleBoundingBox(struct Shape *T, double *tTriangle){
    tTriangle[0] = T->su.t.pt1X;
    tTriangle[1] = T->su.t.pt2X;
    tTriangle[2] = T->su.t.minY;
    tTriangle[3] = T->su.t.maxY;

}
