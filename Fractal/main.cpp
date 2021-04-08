#include <iostream>
#include "Bitmap.h"
#include "Mandelbrot.h"

using namespace BitmapAll;
using namespace std;

int main()
{
    int const WIDTH = 800;
    int const HEIGHT = 600;

    Bitmap bitmap(WIDTH, HEIGHT);
    double min = 999999;
    double max = -999999;
    // make the entire bitmap red.
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            double xFractal = (x - WIDTH / 2 - 200) * 2.0 / HEIGHT;

            double yFractal = (y - HEIGHT / 2) * 2.0 / HEIGHT;
            int iterations = Mandelbrot::getIterations(xFractal, yFractal);

            uint8_t color = (uint8_t)(256 * (double)iterations / Mandelbrot::MAX_ITERATIONS);
            color = color * color * color;
            bitmap.setPixel(x, y, 0, color, 0);
            if (color < min)
                min = color;
            if (color > max)
                max = color;
        }
    }
    cout << min << "," << max << endl;
    bitmap.write("test.bmp");
    cout << "Finished" << endl;
    return 0;
}