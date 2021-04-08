#include <iostream>
#include <memory>
#include <math.h>
#include "FractalCreator.h"

using namespace BitmapAll;
using namespace std;

int main()
{
    int const m_width = 800;
    int const m_height = 600;

    FractalCreator fractalCreator(800, 600);

    fractalCreator.addZoom(Zoom(295, m_height - 202, 0.1));
    fractalCreator.addZoom(Zoom(312, m_height - 304, 0.1));

    fractalCreator.calculateIteration();
    fractalCreator.calculateTotalIterations();
    fractalCreator.drawFractal();
    fractalCreator.writeBitmap("test.bmp");
    cout << "Finished" << endl;
    return 0;
}