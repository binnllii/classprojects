#include "image.h"
#include "sink.h"
#include "source.h"
#include <stdio.h>

#ifndef FILTERS_H
#define FILTERS_H


class filters: public source, public Sink
{
public:
    virtual const char * FilterName() = 0;
    virtual const char * SourceName();
    virtual const char * SinkName();
    void Update();
};

class Shrinker : public filters
{
public:
    const char * FilterName();
    void Execute();
};

class LRConcat : public filters
{
public:
    const char * FilterName();
    void Execute();
};

class TBConcat : public filters
{
public:
    const char * FilterName();
    void Execute();
};

class Blender : public filters
{
protected:
    float percent;
public:
    const char * FilterName();
    void SetFactor(float percent);
    void Execute();
};

class Grayscale : public filters
{
public:
    const char * FilterName();
    void Execute();
};

class Blur : public filters
{
public:
    const char * FilterName();
    void Execute();
};

class Subtract : public filters
{
public:
    const char * FilterName();
    void Execute();
};

class Rotate : public filters
{
public:
    const char * FilterName();
    void Execute();
};


class  Mirror : public filters
{
public:
    const char * FilterName();
    void Execute();
};

class CheckSum : public Sink
{
public:
    const char *SinkName();
    void OutputCheckSum(const char *filename);
    
};

class Color : public filters
{
public:
    const char * FilterName();
    Color(int wid, int heig, unsigned char r, unsigned char g, unsigned char b);
    void Execute();
    //virtual void Update();
    
protected:
    int width;
    int height;
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

#endif
