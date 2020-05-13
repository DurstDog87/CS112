/*
 * Song.h
 *
 *  Created on: Sep 10, 2019
 *      Author: mjs96
 */

#ifndef SONG_H
#define SONG_H

#include <string>
using namespace std;

class Song {
public:
	Song();
	string getTitle() const;
	string getArtist() const;
	unsigned getYear() const;
	Song(const string& title, const string& artist, unsigned year);
	void readFrom(istream& in);
	void writeTo(ostream& out) const;
private:
	string   myTitle;
	string   myArtist;
	unsigned myYear;
};

#endif /*SONG_H_*/
