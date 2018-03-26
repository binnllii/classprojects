#include "image.h"
#include "Sink.h"
#include "Source.h"
#include <stdio.h>

#ifndef FILTERS
#define FILTERS


class filter: public source, public Sink
{

};
class Shrinker : public filter
{
public:
    void Execute();
};
class LRConcat : public filter
{
public:
    void Execute();
};
class TBConcat : public filter
{
public:
    void Execute();
};
class Blender : public filter
{
protected:
    float percent;
public:
    void SetFactor(float percent);
    void Execute();
};

#endif
