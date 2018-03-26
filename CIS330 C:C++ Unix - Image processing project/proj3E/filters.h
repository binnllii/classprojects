#include "image.h"
#include "sink.h"
#include "source.h"
#include <stdio.h>

#ifndef FILTERS_H
#define FILTERS_H


class filters: public source, public Sink
{
    void Update();
};

class Shrinker : public filters
{
public:
    void Execute();
    
};

class LRConcat : public filters
{
public:
    void Execute();
};

class TBConcat : public filters
{
public:
    void Execute();
    
};

class Blender : public filters
{
protected:
    float percent;
public:
    void SetFactor(float percent);
    void Execute();
};

#endif
