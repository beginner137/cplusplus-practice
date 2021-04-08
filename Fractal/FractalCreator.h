#ifndef __FRACTALCREATOR_H__
#define __FRACTALCREATOR_H__
#include "Zoom.h"
#include <string>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"

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

    public:
        FractalCreator(int width, int height);
        virtual ~FractalCreator();
        void calculateIteration();
        void calculateTotalIterations();
        void drawFractal();
        void addZoom(const Zoom &zoom);
        void writeBitmap(string name);
    };
}

#endif // __FRACTALCREATOR_H__