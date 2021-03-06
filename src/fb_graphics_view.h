/*
 * FbSs
 *
 *  Created on: Apr 1, 2012
 *	Copyright 2012 Ryan Henderson
 *
 */


#ifndef FB_GRAPHICS_VIEW_H_
#define FB_GRAPHICS_VIEW_H_

#include <QGraphicsScene>
#include <QGraphicsView>

class FbGraphicsView : public QGraphicsView {

public:
    FbGraphicsView(QWidget *parent = 0) : QGraphicsView(parent) {
    }
	FbGraphicsView(QGraphicsScene *scene, QWidget *parent = 0)
    	: QGraphicsView(scene, parent) {
	}

protected:
    void resizeEvent(QResizeEvent *event);
    virtual void mouseDoubleClickEvent( QMouseEvent * event );

};

#endif /* FB_GRAPHICS_VIEW_H_ */
