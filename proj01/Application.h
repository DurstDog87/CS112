/*
 * Application.h
 *
 *  Created on: Sep 14, 2019
 *      Author: mjs96
 */

#include "PlayList.h"
#ifndef APPLICATION_H_
#define APPLICATION_H_

class Application {
public:
	Application();
	void searchByArtist();
	void searchByYear();
	void searchByTitlePhrase();
	void addSong();
	void removeSong();
	void save();
	void doNothing();
private:
	PlayList pList;
};

#endif /* APPLICATION_H_ */
