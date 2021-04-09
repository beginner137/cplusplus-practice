#include <iostream>
#include <memory>
#include <math.h>
#include "FractalCreator.h"
#include "RGB.h"
#include "Zoom.h"

using namespace BitmapAll;
using namespace std;

int main()
{
    FractalCreator fractalCreator(800, 600);
    fractalCreator.addZoom(Zoom(295, 202, 0.1));
    fractalCreator.addZoom(Zoom(312, 304, 0.1));
    fractalCreator.run("test.bmp");
    cout << "Finished" << endl;
    return 0;
}