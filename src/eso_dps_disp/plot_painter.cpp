#include "plot_painter.h"

void PlotPainter::clearGraphs(QCustomPlot *customPlot)
{
    customPlot->clearGraphs();
}

void PlotPainter::paintOnePlot( QCustomPlot *customPlot, QVector<double> &x, QVector<double> &y,
                                QColor color, QColor brush_color, bool clear )
{
    if( clear )
        customPlot->clearGraphs();
    auto graph = customPlot->addGraph();
    graph->setPen( color ); // line color blue for first graph
    graph->setBrush(QBrush( brush_color )); // first graph will be filled with translucent blue

    // configure right and top axis to show ticks but no labels:
    customPlot->xAxis2->setVisible(true);
    customPlot->xAxis2->setTickLabels(false);
    customPlot->yAxis2->setVisible(true);
    customPlot->yAxis2->setTickLabels(false);

    customPlot->setInteractions( QCP::iRangeDrag | QCP::iRangeZoom );

    // pass data points to graphs:
    graph->setData(x, y);

    // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
    graph->rescaleAxes();

    // repaint
    customPlot->replot();
}
