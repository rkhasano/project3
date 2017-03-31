/*
MODIFY THIS FILE
*/

#include "hp3_program.hpp"

#include <iostream>
using namespace std;


/* Setup() - 	Create the list of locations
 *              Allocate needed memory
 * */
void Program::Setup()
{
    // This is called automatically when the program begins
	
	// Creating dynamic array with size 6 for room locations.
	Location* locationList;
	locationList = new Location[6];

	//Rooms description.
	locationList[0].name = "Treasure Room";
	locationList[0].description = "There is a lot of gold here!";
	locationList[1].name = "Court Yard";
	locationList[1].description = "Many people we hanged here in the past. There are bones here.";
	locationList[2].name = "The hall";
	locationList[2].description = "Very big room. There are arm-chair and sofa to rest.";
	locationList[3].name = "Kitchen.";
	locationList[3].description = "There are plenty of food here!";
	locationList[4].name = "The bedroom of the princess";
	locationList[4].description = "Nice room. There are different kind of clothes here.";
	locationList[5].name = "The security corner!";
	locationList[5].description = "There are big windows in this room to monitor what happens outside.";

	// Location 1. Starting point. Possible to move only to  right(east).
	locationList[1].ptrToEast = &locationList[2]; 
	
	// From Location 2 back to west to 1, or south to location 4.
	locationList[2].ptrToWest = &locationList[1]; 
	locationList[2].ptrToSouth = &locationList[4];

	// From 4 back to North tp location 2, or east to 5.
	locationList[4].ptrToNorth = &locationList[2];
	locationList[4].ptrToEast = &locationList[5];

	//From 5 west to 4, or north to 3.
	locationList[5].ptrToWest = &locationList[4];
	locationList[5].ptrToNorth = &locationList[3];

	//From 3 south to 5, west to 2, north to 0(winning move!)
	locationList[3].ptrToSouth = &locationList[5];
	locationList[3].ptrToWest = &locationList[2];
	locationList[3].ptrToNorth = &locationList[0];

	Location* ptrCurrentLocation;
	Location* ptrEndLocation;

	ptrCurrentLocation = &locationList[1];
	ptrEndLocation = &locationList[0];
}



/* Cleanup() - 	Clean up memory allocated
 * */
void Program::Cleanup()
{
    // This is called automatically when the program ends
	if (locationList!= nullptr) 
	{
		delete []locationList;
	}
}



/* Main() - Main program loop
 * */
void Program::Main()
{
}



/* DisplayCurrentLocation() - Use the current location
 *              pointer to display the location's name
 *              and description, as well as which
 *              directions the player can move next.
 * */
void Program::DisplayCurrentLocation()
{
	cout << ptrCurrentLocation->name << endl; //Display name of the room.
	cout << ptrCurrentLocation->description << endl; //Display description of the rooom.

	string move;
	move = "You can move *";

	// Check which directions are null
	if (ptrCurrentLocation->ptrToNorth != nullptr)  
	 {
		move = move + "North ";
	 }
	if (ptrCurrentLocation->ptrToEast != nullptr)
	{
		move = move + "East ";
	}

	if (ptrCurrentLocation->ptrToSouth != nullptr)
	{
		move = move + "South ";
	}

	else if (ptrCurrentLocation->ptrToWest != nullptr)
	{
		move = move + "West ";
	}

	cout << move;

}



/* GetUserInput() - Display the list of options to the
 *                  user, then get their input and return
 *                  their choice.
 * */
string Program::GetUserInput()
{
	string option;

	cout << "Options to move: n to North, e to East, s to South, w to West. q to quit ";
	cin >> option;
	
	return option; 
}



/************************************/
/* Don't modify *********************/
/************************************/

Program::Program()
{
    locationList = nullptr;
    ptrCurrentLocation = nullptr;
    Setup();
}

Program::~Program()
{
    Cleanup();
}
