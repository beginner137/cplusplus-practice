#ifndef ZOOMLIST_H_
#define ZOOMLIST_H_
#include "Zoom.h"
#include <vector>
#include <utility>

using namespace std;
namespace BitmapAll
{
    class ZoomList
    {
    private:
        int m_width{0};
        int m_height{0};
        vector<Zoom> zooms;

    public:
        ZoomList(int width, int height);
        void add(const Zoom &zoom);
        pair<double, double> doZoom(int x, int y);
    };
}

#endif