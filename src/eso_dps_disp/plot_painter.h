#ifndef PLOT_PAINTER_H
#define PLOT_PAINTER_H

#include "qcustomplot/qcustomplot.h"

typedef QVector< double > Values;

class PlotPainter
{
public:
    static void clearGraphs( QCustomPlot* customPlot );
    static void paintOnePlot( QCustomPlot* customPlot,
                              QVector<double> &x, QVector<double>& y,
                              QColor color = Qt::blue,
                              QColor brush_color = QColor( 0,0,255,20 ),
                              bool clear = false );
};

#endif // PLOT_PAINTER_H
