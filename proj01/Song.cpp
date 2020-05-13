/*
 * Song.cpp
 *
 *  Created on: Sep 14, 2019
 *      Author: mjs96
 */

#include "Song.h"

Song::Song()                                                            // Song default constructor
{
	myTitle = "";
	myArtist = "";
	myYear = 0;                                                     // myTitle && myArtist == "" && myYear == 0;
}

string Song::getTitle() const                                           // Getter method for myTitle
{
	return myTitle;
}

string Song::getArtist() const                                          // Getter method for myArtist
{
	return myArtist;
}

unsigned Song::getYear() const                                          // Getter method for myYear
{
	return myYear;
}

Song::Song(const string& title, const string& artist, unsigned year)    // Explicit constructor
{
	myTitle = title;
	myArtist = artist;
	myYear = year;                                                  // Sets myElement equal to element
}

void Song::readFrom(istream& in)
{
	getline(in, myTitle);                                           // Takes title from file
	getline(in, myArtist);                                          // Takes artist from file
	string yearString;
	getline(in, yearString);                                        // Takes year from file
	myYear = atoi( yearString.c_str() );                            // Converts  year from string to unsigned integer
}

void Song::writeTo(ostream& out) const
{
	out << myTitle << '\n'                                          // Writes these to the file
			<< myArtist << '\n'
			<< myYear  << '\n';
}

bool Song::operator==(const Song& song2) const
		{
	return  myTitle  == song2.getTitle() &&
			myArtist == song2.getArtist() &&
			myYear   == song2.getYear();                    // Because of the format of this return, it ensures that all entities match
		}
