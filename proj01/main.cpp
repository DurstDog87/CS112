/* main.cpp
 * Student name: Michael Sisko
 * Date: 09/14/2019
 * Author: Prof. Joel Adams
 * For: CS 112, Lab 01 at Calvin University.
 */

#include "SongTester.h"
#include "PlayListTester.h"
#include "Application.h"

int main() {
	SongTester sTester;
	sTester.runTests();
	PlayListTester plTester;
	plTester.runTests();
	Application app;
}
