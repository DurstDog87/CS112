/*
 * PlayListTester.h
 *
 *  Created on: Sep 14, 2019
 *      Author: mjs96
 */

#ifndef PLAYLISTTESTER_H_
#define PLAYLISTTESTER_H_

class PlayListTester {
public:
	void runTests();
	void testConstructors();
	void testSearchByTitlePhrase();
	void testSearchByArtist();
	void testSearchByYear();
	void testAddSong();
	void testRemoveSong();
	void testSave();
};

#endif /* PLAYLISTTESTER_H_ */

