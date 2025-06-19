//coordin.h -- structures templates and function prototypes
//structure templates
#ifndef COORDIN_H
#define COORDIN_H

struct polar
{
    double distance;
    double angle;
};

struct rect
{
    double x;
    double y;
};

polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

#endif

