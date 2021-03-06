/*
 * FbSs
 *
 *  Created on: Apr 1, 2012
 *	Copyright 2012 Ryan Henderson
 *
 */

#include <QDebug>
#include <QDir>
#include "FbSs.h"

FbSs::FbSs() : d_current(0), d_store("store")
{
	connect(&d_fb_ui, SIGNAL(nextImage(int)), this, SLOT(nextImage(int)));
	updateStore();
	nextImage(0);
	d_fb_ui.show();
	d_fb_ui.setFocus();
	d_fb_ui.showLogin();
}

void FbSs::updateStore() {
	d_filenames.clear();
	d_filenames = QDir(d_store).entryList(QDir::Files);
}

void FbSs::nextImage(int direction) {
	if ( !d_filenames.size() )
		return;

	d_current+=direction;
	if ( d_current >= d_filenames.size())
		d_current = 0;
	if ( d_current < 0 )
		d_current = d_filenames.size()-1;

	d_fb_ui.showImage(d_store + "/" + d_filenames[d_current]);
}
