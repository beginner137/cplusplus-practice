#ifndef __RGB_H__
#define __RGB_H__

namespace BitmapAll
{
    struct RGB
    {
        double r;
        double g;
        double b;

        RGB(double r, double g, double b);
    };

    RGB operator-(const RGB &first, const RGB &second);

}

#endif // __RGB_H__