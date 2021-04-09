#ifndef __FRACTALCREATOR_H__
#define __FRACTALCREATOR_H__
#include "Zoom.h"
#include <string>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "RGB.h"

using namespace std;
namespace BitmapAll
{
    class FractalCreator
    {
    private:
        int m_width;
        int m_height;
        unique_ptr<int[]> m_histogram;
        unique_ptr<int[]> m_fractal;
        Bitmap m_bitmap;
        ZoomList m_zoomList;
        int m_total{0};

        void calculateIteration();
        void calculateTotalIterations();
        void drawFractal();
        void writeBitmap(string name);

    public:
        FractalCreator(int width, int height);
        void run(string name);
        void addZoom(const Zoom &zoom);
        virtual ~FractalCreator();
    };
}

#endif // __FRACTALCREATOR_H__