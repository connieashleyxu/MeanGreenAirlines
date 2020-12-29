// FlightSystem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

#include "flight.h"
#include "plane.h"
#include "crew.h"

// FlightMenuClass : Defines the entry point for the console application.
//

//////////////////////////////////////////////////

class FlightControlMenu
{
	private:
	public: 
		void MainMenu(void);
        void GetAirportCode (char airCode[], int AirCodeChoice);
};

//////////////////////////////////////////////////////////////////

void FlightControlMenu::GetAirportCode (char AirCode[], int AirCodeChoice)
{
	switch (AirCodeChoice)
	{
		case 1:
			strcpy (AirCode, "SFO");
			break;
	    case 2:
			strcpy (AirCode, "DFW");
			break;
		case 3:
			strcpy (AirCode, "ORD");
			break;
		case 4:
			strcpy (AirCode, "LAX");
			break;
		case 5:
			strcpy (AirCode, "SAN");
			break;
		case 6:
			strcpy (AirCode, "JFK");
			break;
		case 7:
			strcpy (AirCode, "EWR");
			break;
		case 8:
			strcpy (AirCode, "ATL");
			break;
		case 10:
			strcpy (AirCode, "PVG");					  
			break;
		case 11:
			strcpy (AirCode, "FRA");					  
			break;
		case 12:
			strcpy (AirCode, "NRT");					  
			break;
		case 13:
			strcpy (AirCode, "CDG");					  
			break;
		case 14:
			strcpy (AirCode, "LHR");	 
			break;
		case 15:
			strcpy (AirCode, "MOW");
            break;
		case 16:
			strcpy (AirCode, "YYZ");
			break;
		case 17:
			strcpy (AirCode, "DXB");
			break;
		case 18:
			strcpy (AirCode, "SYD");
			break;
		default:
			cout << "\t Invalid choice for Airport Code: " << AirCodeChoice << endl;
			break;
	}
}

//////////////////////////////////////////////////////////

void FlightControlMenu::MainMenu(void)
{
	Flight flight;
	Crew   crew;
	Plane  plane;

	char input;
	int  choiceMain, choiceCrew, choicePlane, choiceFlight;
    int cID;
	char cName[40];
    char cType;

	char  pID[40];
	char  pMake[40];
	char  pModel[40];
	int   pNumSeats;
	int   pRange;
	int   pMinCabinCrewNum;

	int nPilots;
	int nCabinCrews;
	int sTimeChoice;

	char sAirCode[40];
	int  sAirCodeChoice;
	int  IntFlight = 0;

	char eAirCode[40];
	int  eAirCodeChoice;

	int nPassengers;
	int pStatus;
	int fID;

	crew.GetCrewRecFile ();
	plane.GetPlaneRecFile ();
	flight.GetFlightRecFile ();

	// Get Cabin and pilot ID  from Crew List to flight
	crew.GetCrewID(flight.CabinCrewIDs, flight.PilotIDs);

	//crew.PrintCrewList ();
	//flight.PrintfCrewList();

    time_t curr_time;
	tm *dTime;
	tm startTm;
	tm endTm;

	do //do while loop
    {
		system("CLS");
		cout << endl << "  C++ project for Flight Schedule Main Manu" << endl << endl;
		cout << "\t 1.Schedule Flight(1) \n\t 2.Schedule Crew(2) \n\t 3.Schedule Plane(3) \n\t 4.Exit(4)" << endl;
		cout << "\n\t Please enter your choice:";
		cin >> choiceMain;

		switch(choiceMain)
		{
          case 1: // Schedule flight
			  do
			  {
			  system("CLS");
	  		  cout << "\n\n\t 1.Add Flight(1) \n\t 2.Edit Flight(2) \n\t 3.Delete Flight(3) \n\t 4.Search Flight(4)\n\t 5.Print All Flight(5)\n\t 6.Print a Flight(6)\n\t 7.Print Crew List(7)\n\t 8.Print Active Assignment Schedule for a Plane(8)\n\t 9.Print Active Assignment Schedule on Crew ID(9)\n\t 10.Print Active Assignment Schedule on status(10)\n\t 11.Delelte all Cancelled or Completed Flights(11)\n\t 12.Check Flight Schedule Active to Completed(12)" << endl;
		      cout << "\n\t Please enter your choice:";
		      cin >> choiceFlight;
			  switch (choiceFlight)
			  {
			  case 1:  // Add flight
			  case 2:  // Edit flight
                  cout << "\t Enter Flight ID: ";
				  cin >> fID;
                  cout << "\t Enter Flight Plane ID: ";
				  cin >> pID;
				  if (!plane.SearchPlane (pID, pNumSeats))
				  {
					  cout << "\t Plane not found: " << pID << endl;
					  break;
				  }
				  cout << "\t Enter number of Pilots (Max 4): ";
				  cin >> nPilots;
				  if (nPilots > 4)
				  {
					  cout << nPilots <<" exceed max number of pilots." << endl; 
					  nPilots = 2;
					  break;
				  }

				  cout << "\t Enter number of cabin crews (Max 8): ";
				  cin >> nCabinCrews;
				  if (nPilots > 8)
				  {
					  cout << nCabinCrews <<" Exceed max number 8 of cabin crews." << endl; 
					  break;
				  }

				  cout << "\t Domestic Airport Code:" << endl;
				  cout << "\t SFO(1) DFW(2) ORD(3) LAX(4) SAN(5) JFK(6) EWR(7) ATL(8)" << endl;
				  cout << "\n\n\t International Aiport Code:" << endl;
				  cout << "\t PVG(10) FRA(11) NRT(12) CDG(13) LHR(14) MOW(15) YYZ(16) DXB(17) SYD(18)" << endl;

				  cout << "\t Please enter your Depearture airport code number:";
                  cin >> sAirCodeChoice;
				  GetAirportCode (sAirCode, sAirCodeChoice);
				  if (sAirCodeChoice < 1 || sAirCodeChoice > 18)
				  {
					  cout << "\tInvalid choice of Airport code " << endl;
					  break;
				  }

				  cout << "\t Please enter your Arrival airport code number:";
				  cin >> eAirCodeChoice;
				  if (eAirCodeChoice < 1 || eAirCodeChoice > 18)
				  {
					  cout << "\tInvalid choice of Air port code " << endl;
					  break;
				  }

				  // If fly from to the same airport, this is an error
				  if (sAirCodeChoice == eAirCodeChoice)
				  {
					  cout << "\t Cannot fly in the same airport" << endl;
					  break;
				  }

				  GetAirportCode (eAirCode, eAirCodeChoice);

				  IntFlight = 0;
				  if (sAirCodeChoice >= 10 || eAirCodeChoice >= 10)
				  {
					  cout << "\t   International flight selected" << endl;
					  IntFlight = 1;
				  }
	              curr_time = time(NULL);
				  dTime = localtime(&curr_time);
				  // schedule for tomorrow by add 1 day
				  dTime->tm_mday += 1;
                  if (dTime->tm_mday > 32)
					  dTime->tm_mday = 31;

				  cout << "\n\t Flight "<< pID << " departure time on " << dTime->tm_mon+1 << "/" << dTime->tm_mday << "/" << dTime->tm_year+1900 << endl;
				  cout << "\t 1) Departure at 07:30 (1)" << endl;
				  cout << "\t 2) Departure at 10:30 (2)" << endl;
				  cout << "\t 3) Departure at 13:30 (3)" << endl;
				  cout << "\t 4) Departure at 15:00 (4)" << endl;
				  cout << "\t Please select your departure time: ";
				  // Init time structure
				  memcpy ((tm *)&startTm, dTime, sizeof(tm));
				  memcpy ((tm *)&endTm, dTime, sizeof(tm));

				  cin >> sTimeChoice;
				  switch (sTimeChoice)
				  {
				  case 1:
					  startTm.tm_hour = 7;
					  startTm.tm_min = 30;

					  endTm.tm_hour = startTm.tm_hour + 3;
					  endTm.tm_min = startTm.tm_min;

					  // Is this international flight, add 8 hours to end time
                      if (IntFlight)
					  {
						  endTm.tm_hour = startTm.tm_hour + 8;
						  nPilots = 4;
						  pMinCabinCrewNum = plane.SearchMinNumCabinCrew (pID);
						  nCabinCrews = pMinCabinCrewNum * 2;
					  }
					  break;
				  case 2:
					  startTm.tm_hour = 10;
					  startTm.tm_min = 30;

					  endTm.tm_hour = startTm.tm_hour + 4;
					  endTm.tm_min = startTm.tm_min;

					  // Is this internlation flight, add 8 hours to end time
                      if (IntFlight)
					  {
						  nPilots = 4;
						  endTm.tm_hour = startTm.tm_hour + 8;
						  pMinCabinCrewNum = plane.SearchMinNumCabinCrew (pID);
						  nCabinCrews = pMinCabinCrewNum * 2;
					  }
					  break;
				  case 3:
					  startTm.tm_hour = 13;
					  startTm.tm_min = 30;

					  endTm.tm_hour = startTm.tm_hour + 4;
					  endTm.tm_min = startTm.tm_min;

					  // Is this internlation flight, add 8 hours to end time
                      if (IntFlight)
					  {
						  endTm.tm_hour = startTm.tm_hour + 8;
						  nPilots = 4;
						  pMinCabinCrewNum = plane.SearchMinNumCabinCrew (pID);
						  nCabinCrews = pMinCabinCrewNum * 2;
					  }
					  break;

				  case 4:
					  startTm.tm_hour = 15;
					  startTm.tm_min = 30;

					  endTm.tm_hour = startTm.tm_hour + 5;
					  endTm.tm_min = startTm.tm_min;

					  // Is this internlation flight, add 8 hours to end time
                      if (IntFlight)
					  {
						  //cout << " International flight" << endl;
						  endTm.tm_hour = startTm.tm_hour + 8;
						  nPilots = 4;
						  pMinCabinCrewNum = plane.SearchMinNumCabinCrew (pID);
						  nCabinCrews = pMinCabinCrewNum * 2;
					  }
					 break;
				  default:
					  cout << "\t Invalid choice for Departure time" << endl;
					  break;
				  }

				  if (flight.IsTimeConflictOnPlane (pID, startTm, endTm))
				  {
					  cout << "\t Plane assignment time conflict is TRUE" << endl;
                      break;
				  }

			      if (flight.IsTimeConflictOnCrewMember (nCabinCrews, nPilots, startTm, endTm))
				  {
					  cout << "\t Crew assignment time conflict is TRUE" << endl;
					  break;
				  }
				  cout << "\t Please enter number of passegners ";
				  cin >> nPassengers;
				  if (nPassengers > 400)
				  {
					nPassengers = 400;
					cout << "\t Plane max capacity is 400 seats" << endl;
				  }

				  if (plane.SearchPlane (pID, pNumSeats))
				  {
					if (nPassengers > pNumSeats)
					{
						cout << "\t Invalid: Num of Seats " << pNumSeats << " less than " << nPassengers << " passengers" << endl;
						break;
					}
				  }

				  cout << "\n\t 1. Active(1)" << endl;
				  cout << "\t 2. Completed(2)" << endl;
				  cout << "\t 3. Cancelled(3)" << endl;
				  cout << "\t Please enter plane status ";
				  cin >> pStatus;
				  if (pStatus > 3 || pStatus < 1)
				  {
					  cout << "\t Invalid plane status " << endl;
					  pStatus = 3;
					  break;
				  }

				  if (choiceFlight == 1)
					  flight.AddFlight (fID, pID, nPilots, nCabinCrews, startTm, endTm, sAirCode, eAirCode, nPassengers, pStatus);
				  else
					  flight.EditFlight (fID, pID, nPilots, nCabinCrews, startTm, endTm, sAirCode, eAirCode, nPassengers, pStatus);
				  break;

			  case 3:  // Del Flight
                  cout << "\t Enter Flight ID to delete: ";
				  cin >> fID;
				  flight.DelFlight (fID);
				  break;

			  case 4:  // Search Flight
                  cout << "\t Enter Flight ID to search: ";
				  cin >> fID;
				  flight.SearchFlight (fID);
				  break;

			  case 5:  // Print all
				  flight.PrintAllFlight ();
				  break;

			  case 6:  // Print one
                  cout << "\t Enter Flight ID to display: ";
				  cin >> fID;
				  flight.PrintAFlight (fID);
				  break;
			  case 7: // Print Crew List
			   	  //crew.PrintCrewList ();
				  flight.PrintfCrewList();
				  break;
			  case 8:
                  cout << "\t Enter Flight Plane ID: ";
				  cin >> pID;
				  if (!plane.SearchPlane (pID, pNumSeats))
				  {
					  cout << "\t Plane not found: " << pID << endl;
					  break;
				  }
				  flight.PrintAssignmentScheduleforPlane (pID);
				  break;

			  case 9:
				  cout << "\t Enter Crew member ID: ";
				  cin >> cID;
				  flight.PrintAssignmentScheduleforCrew (cID);
				  break;

			  case 10:
				  cout << "\n\t 1. Active(1)" << endl;
				  cout << "\t 2. Completed(2)" << endl;
				  cout << "\t 3. Cancelled(3)" << endl;
				  cout << "\t Please enter plane status ";
				  cin >> pStatus;
				  if (pStatus > 3 || pStatus < 1)
				  {
					  cout << "\t Invalid plane status: " << pStatus << endl;
					  break;
				  }
				  flight.PrintFlightOnStatus (pStatus);
				  break;

			  case 11:
				  flight.DeleteCancel_or_Complete_flight ();
				  break;

			  case 12:
				  flight.UpdateFightActiveToCompletedStatus ();
				  break;

			  default:
				  cout << endl << " Invalid Choice. Please enter Flight schedule choice between 1 and 12" << endl;
				  break;
			  }

			  cout<<"\n\nDo you wish to do another flight: (y/n)" << endl;
			  cin >> input;

			  } while(input == 'Y' || input == 'y');

			  break;  // Schedule Flight break;

		  case 2:  // Schedule Crew
			  do
			  {
			  // Clear the screen
		      system("CLS");
	  		  cout << "\n\n\t 1.Add Crew(1) \n\t 2.Edit Crew(2) \n\t 3.Delete Crew(3) \n\t 4.Search Crew(4)\n\t 5.Print All Crew(5)\n\t 6.Print a Crew(6)" << endl;
		      cout << "\n\t Please enter your choice:";
		      cin >> choiceCrew;
			  switch (choiceCrew)
			  {
			  case 1:  // Add Crew
				  {
                    cout << "\t Enter Crew ID: ";
					cin >> cID;
					cout << "\t Enter Crew Name: ";
					cin >> cName;

					while (1)
					{
						cout << "\t Enter Crew Type: p for Pilot, c for Cabin crew (p/c) ";
						cin >> cType;
						if (cType == 'c' || cType == 'p')
						{
							crew.AddCrew (cID, cName, cType);
							break;
						}
						else
						{
						   cType = 0;
						   cout << endl << "\n\t Wrong input. Valid choice is p or c" << endl;
						   continue;
						}
					}
				  }			      
				  break;
			  case 2:  // Edit Crew
                   cout << "\t Enter Crew ID: ";
				   cin >> cID;
				   cout << "\t Enter Crew Name: ";
				   cin >> cName;
				   cout << "\t Enter Crew Type: p for Pilot, c for Cabin crew (p/c) ";
				   cin >> cType;
				   if (cType == 'c' || cType == 'p')
				   {
						crew.EditCrew (cID, cName, cType);
				   }
				   else
				   {
						cType = 0;
						cout << endl << "\nValid choice is p or c" << endl;
				   }
				  break;

			  case 3:  // Delete Crew
                  cout << "\t Enter Crew ID to delete: ";
				  cin >> cID;
				  crew.DelCrew (cID);
				  break;

			  case 4:  // Search Crew
                  cout << "\t Enter Crew ID to search: ";
				  cin >> cID;
				  crew.SearchCrew (cID);
				  break;

			  case 5:  // Print all Crew
				  crew.PrintAllCrew ();
				  break;

			  case 6:  // Print A Crew
                  cout << "\t Enter Crew ID to display: ";
				  cin >> cID;
				  crew.PrintACrew (cID);
				  break;
			  default:
				  cout << endl << " Invalid Choice. Please enter Crew schedule choice between 1 and 6" << endl;
				  break;
			  }

			    cout<<"\n\nDo you wish to assign another crew: (y/n)" << endl;
			    cin >> input;

			  } while(input == 'Y' || input == 'y');

			  break;  // Schedule Crew break

		  case 3:  // Schedule Plane
			  do
			  {
			  // Clear the screen
		      system("CLS");
	  		  cout << "\n\n\t 1.Add Plane(1) \n\t 2.Edit Plane(2) \n\t 3.Delete Plane(3) \n\t 4.Search Plane(4)\n\t 5.Print All Plane(5)\n\t 6.Print a Plane(6)" << endl;
		      cout << "\n\t Please enter your choice:";
		      cin >> choicePlane;
			  switch (choicePlane)
			  {
			  case 1:  // Add Plane
				{
                    cout << "\t Enter Plane ID: ";
					cin >> pID;
					cout << "\t Enter Plane Make: ";
					cin >> pMake;
					cout << "\t Enter Plane Model: ";
					cin >> pModel;

				    cout << "\t Enter Plane num of seats: ";
					cin >> pNumSeats;	
					if (pNumSeats > 400)
					{
						cout << "\t Plane number of seats cannot be > 400" << endl;
						break;
					}

					cout << "\t Enter Plane range (miles): ";
					cin >> pRange;
					if (pRange > 30000)
					{
						cout << "\t Plane range cannot be > 30000 miles" << endl;
						break;
					}
					cout << "\t Enter Plane Minimum cabin crew num (Min=1, not exceed 4): ";
					cin >> pMinCabinCrewNum;
					if (pMinCabinCrewNum < 1 || pMinCabinCrewNum > 4)
					{
						pMinCabinCrewNum = 1;
  					    cout << "\t Min Cabin Crew number cannot be < 1 or > 4: " << pMinCabinCrewNum << endl;
						break;
					}
					plane.AddPlane (pID, pMake, pModel, pNumSeats, pRange, pMinCabinCrewNum);
				 }
				 break;
			  case 2:  // Edit Plane
                    cout << "\t Enter Plane ID: ";
					cin >> pID;
					cout << "\t Enter Plane Make: ";
					cin >> pMake;
					cout << "\t Enter Plane Model: ";
					cin >> pModel;

				    cout << "\t Enter Plane num of seats: ";
					cin >> pNumSeats;	

					cout << "\t Enter Plane range: ";
					cin >> pRange;

					cout << "\t Enter Plane Minimum cabin crew num: ";
					cin >> pMinCabinCrewNum;
					plane.EditPlane (pID, pMake, pModel, pNumSeats, pRange, pMinCabinCrewNum);
				  break;
			  case 3:  // Delete Plane
                  cout << "\t Enter Plane ID to delete: ";
				  cin >> pID;
				  plane.DelPlane (pID);
				  break;

			  case 4:  // Search Plane
                  cout << "\t Enter Plane ID to search: ";
				  cin >> pID;
				  plane.SearchPlane (pID, pNumSeats);
				  break;
			  case 5:  // Print All Plane
				  plane.PrintAllPlane ();
				  break;
			  case 6:  // Print A Plane
                  cout << "\t Enter Plane ID to display: ";
				  cin >> pID;
				  plane.PrintAPlane (pID);
				  break;
			  default:
				  cout << endl << " Invalid Choice. Please enter Plane schedule choice between 1 and 6" << endl;
				  break;
			  }

			    cout<<"\n\nDo you wish to assign another plane: (y/n)" << endl;
			    cin >> input;

		      } while(input == 'Y' || input == 'y');

			  break;  // Schedule Plane break;

		  case 4:  // Quit
			  break;

		  default:
			cout << endl << " Invalid Choice. Please enter Main Menu choice between 1 and 4" << endl;
			break;
		}

		cout<<"\n\nDo you wish to continue: (y/n)" << endl;
		cin >> input;
	} while(input=='Y' || input=='y'); //condition for do while loop
}

//////////////////////////////////////////////////

int _tmain(int argc, _TCHAR* argv[])
{
	FlightControlMenu menu;
	menu.MainMenu();
    return 0;
}
