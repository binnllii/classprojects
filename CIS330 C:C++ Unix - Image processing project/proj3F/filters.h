#include "image.h"
#include "Sink.h"
#include "Source.h"
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

#endif
