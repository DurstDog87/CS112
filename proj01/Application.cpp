/*
 * Application.cpp
 *
 *  Created on: Sep 14, 2019
 *      Author: mjs96
 */

#include "Song.h"
#include "PlayList.h"
#include "Application.h"

#include <iostream>
#include <cstdlib>
#include <string>
#include <cassert>
#include <ios>
#include <limits>
using namespace std;

Application::Application()

{
	int command = -1;
	PlayList pList("testPlayList.txt");
	while ( command != 0 )
	{
		cout << "\nPLAYLIST MANAGER\n" << endl;
		cout << "\tTo search playlist by TITLE, please press 1 " << endl;
		cout << "\tTo search playlist by ARTIST, please press 2 " << endl;
		cout << "\tTo search playlist by YEAR, please press 3 " << endl;
		cout << "\tTo ADD a song to the playlist, please press 4 " << endl;
		cout << "\tTo REMOVE a song from the playlist, please press 5 " << endl;
		cout << "\tTo SAVE your playlist, please press 6 " << endl;
		cout << "\tTo QUIT session, please press 0 " << endl;
		cout << "Please type a command followed by the 'Enter' key:\n";

		cin >> command;

		(command == 1)? searchByTitlePhrase():
				(command == 2)? searchByArtist():
						(command == 3)? searchByYear():
								(command == 4)? addSong():
										(command == 5)? removeSong():
												(command == 6)? save(): doNothing();
	}
	cout << "End of session. Thank you!" << endl;
}

void Application::doNothing(){}

void Application::searchByTitlePhrase()
{
	string phrase;
	cout << "Enter a TITLE PHRASE: " << flush;
	cin >> phrase;
	vector<Song> searchResult = pList.searchByTitlePhrase(phrase);
	cout << "Results: \n\n" << flush;
	for (unsigned i = 0; i < searchResult.size(); i++)
	{
		searchResult[i].writeTo(cout);
		cout << "\n" << flush;
	}
}
void Application::searchByArtist()
{
	string artist;
	cout << "Enter ARTIST: " << flush;
	cin >> artist;
	vector<Song> searchResult = pList.searchByArtist(artist);
	cout << "Results: \n\n" << flush;
	for (unsigned i = 0; i < searchResult.size(); i++)
	{
		searchResult[i].writeTo(cout);
	}
}
void Application::searchByYear()
{
	int year;
	cout << "Enter YEAR: " << flush;
	cin >> year;
	vector<Song> searchResult = pList.searchByYear(year);
	cout << "Results: \n\n" << flush;
	for (unsigned i = 0; i < searchResult.size(); i++)
	{
		searchResult[i].writeTo(cout);
		cout << "\n" << flush;
	}
}

void Application::addSong()
{
	string title;
	string artist;
	int year;
	cout << "Add SONG...\n";
	cout << "Enter TITLE: ";
	getline(cin,title);
	getline(cin,title);
	cout << "Enter ARTIST: ";
	getline(cin,artist);
	cout << "Enter YEAR: ";
	string year_str;
	getline(cin,year_str);
	year = atoi( year_str.c_str() );

	Song newSong(title, artist, year);
	pList.addSong(newSong);

	cout << "Song has been added to Playlist." << endl;
}

void Application::removeSong(){
	string title;
	string artist;
	int year;
	cout << "Remove SONG...\n";
	cout << "Enter TITLE: ";
	getline(cin,title);
	getline(cin,title);
	cout << "Enter ARTIST: ";
	getline(cin,artist);
	cout << "Enter YEAR: ";
	string year_str;
	getline(cin,year_str);
	year = atoi( year_str.c_str() );

	Song aSong(title, artist, year);
	pList.removeSong(aSong);

	cout << "Song has been removed from Playlist..." << endl;
}

void Application::save()
{
	pList.save();
	cout << "Playlist SAVED..." << endl;
}

