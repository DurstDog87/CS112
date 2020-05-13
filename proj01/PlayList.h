/*
 * PlayList.h
 *
 *  Created on: Sep 14, 2019
 *      Author: mjs96
 */

#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include "Song.h"
#include <vector>
#include <string>
using namespace std;

class PlayList {
public:
	PlayList();
	PlayList(const string& fileName);
	unsigned getNumSongs() const;
	void addSong(const Song& newSong);
	void removeSong(const Song& aSong);
	void save() const;
	vector<Song> searchByArtist(const string& artist) const;
	vector<Song> searchByYear(unsigned year);
	vector<Song> searchByTitlePhrase(const string& phrase);
private:
	vector<Song> mySongs;
	string myPlayList;
};

#endif /* PLAYLIST_H_ */

