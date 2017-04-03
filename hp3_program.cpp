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
	
	locationList = new Location[6];

	//Rooms description.
	locationList[0].name = "Treasure Room";
	locationList[0].description = "There is a lot of gold here!";
	locationList[1].name = "Court Yard";
	locationList[1].description = "Many people were hanged here in the past. There are bones here.";
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

	

	ptrCurrentLocation = &locationList[1];
	ptrEndLocation = &locationList[0];

	

}



/* Cleanup() - 	Clean up memory allocated
* */
void Program::Cleanup()
{
	// This is called automatically when the program ends
	if (locationList != nullptr)
	{
		delete[]locationList;
	}
}



/* Main() - Main program loop
* */
void Program::Main()
{
	bool done = false;
	while (!done)
	{
		// Display Current Location
		DisplayCurrentLocation();

		// Check if a user have reached the end
		if (ptrCurrentLocation == ptrEndLocation)
		{
			cout << "You have reached your destination! Congratulations!";

			// Break the loop
			break;
		}

		// Get the user choice
		string userChoice;
		userChoice = GetUserInput();

		// If user's choice is North check if he can move that way.
		if (userChoice == "n" && ptrCurrentLocation->ptrToNorth != nullptr)
		{
			ptrCurrentLocation = ptrCurrentLocation->ptrToNorth;
		}

		// If user's choice is East check if he can move that way.
		else if (userChoice == "e" && ptrCurrentLocation->ptrToEast != nullptr)
		{
			ptrCurrentLocation = ptrCurrentLocation->ptrToEast;
		}

		// If user's choice is South check if he can move that way.
		else if (userChoice == "s" && ptrCurrentLocation->ptrToSouth != nullptr)
		{
			ptrCurrentLocation = ptrCurrentLocation->ptrToSouth;
		}

		// If user's choice is West check if he can move that way.
		else if (userChoice == "w" && ptrCurrentLocation->ptrToWest != nullptr)
		{
			ptrCurrentLocation = ptrCurrentLocation->ptrToWest;
		}

		// Check if user wants to leave the game
		else if (userChoice == "q")
		{
			done = true;
		}

		// If none of the above is true inform user that he is doing something wrong
		else
		{
			cout << "Invalid Choice!" << endl;
		}
	}
	cout << endl << "GOOD BYE!" << endl;
	char quit='a';
	while(quit !='q' && quit !='Q') 
		{
		cout << "Press q to quit" << endl;
		cin >> quit;
		}
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
	move = "You can move: \t";

	// Check which directions are null
	if (ptrCurrentLocation->ptrToNorth != nullptr)
	{
		move = move + "*North ";
	}
	if (ptrCurrentLocation->ptrToEast != nullptr)
	{
		move = move + "*East ";
	}

	if (ptrCurrentLocation->ptrToSouth != nullptr)
	{
		move = move + "*South ";
	}

	if (ptrCurrentLocation->ptrToWest != nullptr)
	{
		move = move + "*West ";
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

	cout << endl << "Options to move: n to North, e to East, s to South, w to West. q to quit ";
	cin >> option;
	cout << endl;
	
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
