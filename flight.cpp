#include "stdafx.h"
#include <iostream>
#include <fstream> 
#include <string>
#include <ctime>
using namespace std;

#include "crew.h"
#include "flight.h"
#include "plane.h"

Flight::Flight ()
{
	for (int i=0; i<40; i++)    
		PilotIDs[i] = 0;

	for (int i=0; i<40; i++)    
		CabinCrewIDs[i] = 0;
}

////////////////////////////////////////

Flight::~Flight()
{
}

//////////////////////////////////////////////////////

int Flight::AddFlight (int fID, char pID[], int numPilot, int numCabinCrew, tm sTime, tm eTime, char sAirCode[], char eAirCode[],  int numPassenger, int pStatus)
{
	int Found = 0;
	char planeID[40];
	FlightRec flightRec;
	unsigned int fList;

	fList = FlightList.size();
	//cout << "  Add Flight List Size " << fList+1 << endl;

	if (fList == 0)
	{
		flightRec.SetFlightID (fID);
		flightRec.SetPlaneID (pID);
		flightRec.SetNumPilot (numPilot);
		flightRec.SetNumCabinCrew (numCabinCrew);
		flightRec.SetStartTime (sTime);
		flightRec.SetEndTime (eTime);
		flightRec.SetStartAirportCode (sAirCode);
		flightRec.SetEndAirportCode (eAirCode);
		flightRec.SetNumPassenger (numPassenger);
		flightRec.SetPlaneStatus (pStatus);

		flightRec.SetCabinCrewID (PilotIDs);
		flightRec.SetPilotID (CabinCrewIDs);

		// Add to the list
		FlightList.push_back(flightRec);

		fList = 1;
	}
	else
	{
		for(unsigned int i=0; i<fList; i++)
		{
			FlightList[i].GetPlaneID (planeID);
			//cout << "\t Plane ID on Rec " << planeID << endl;
			//cout << "\t Flight ID on Rec " << FlightList[i].GetFlightID() << endl;

			if (fID == FlightList[i].GetFlightID())
			{
				cout << "\tThis Flight " << fID << " already exists. Cannot add this flight at this time" << endl;
				Found = 1;				
				return Found;
			}
		}

		flightRec.SetFlightID (fID);
		flightRec.SetPlaneID (pID);
		flightRec.SetNumPilot (numPilot);
		flightRec.SetNumCabinCrew (numCabinCrew);
		flightRec.SetStartTime (sTime);
		flightRec.SetEndTime (eTime);
		flightRec.SetStartAirportCode (sAirCode);
		flightRec.SetEndAirportCode (eAirCode);
		flightRec.SetNumPassenger (numPassenger);
		flightRec.SetPlaneStatus (pStatus);

		flightRec.SetCabinCrewID (PilotIDs);
		flightRec.SetPilotID (CabinCrewIDs);

		// Add to the list
		FlightList.push_back(flightRec);
	}

	UpdateFlightRec();
	return Found;
}

//////////////////////////////////////////////////////

int Flight::EditFlight (int fID, char pID[], int numPilot, int numCabinCrew, tm sTime, tm eTime, char sAirCode[], char eAirCode[],  int numPassenger, int pStatus)
{
	int Found = 0;
	char planeID[40];

	//cout << "  Edit Flight List Size " << FlightList.size() + 1 << endl;
	if (FlightList.size() == 0)
	{
		cout << "\tThere is no Flight rec, Nothing to edit" << endl;
		Found = 0;
		return Found;
	}

	for(unsigned int i=0; i<FlightList.size(); i++)
	{
		FlightList[i].GetPlaneID (planeID);
		//cout << "\t  Plane ID on Flight Record " << planeID << endl;
		//cout << "\t  Flight ID on Flight Record " << FlightList[i].GetFlightID() << endl;

        if (fID == FlightList[i].GetFlightID())
		{
			cout << "\tFound the Flight ID " << FlightList[i].GetFlightID() << " and Plane ID " << planeID <<  endl;

			FlightList[i].SetFlightID (fID);
			FlightList[i].SetPlaneID (pID);
			FlightList[i].SetNumPilot (numPilot);
			FlightList[i].SetNumCabinCrew (numCabinCrew);
			FlightList[i].SetStartTime (sTime);
			FlightList[i].SetEndTime (eTime);
			FlightList[i].SetStartAirportCode (sAirCode);
			FlightList[i].SetEndAirportCode (eAirCode);
			FlightList[i].SetNumPassenger (numPassenger);
		    FlightList[i].SetPlaneStatus (pStatus);
			FlightList[i].SetCabinCrewID (PilotIDs);
			FlightList[i].SetPilotID (CabinCrewIDs);
			Found = 1;
			break;
		}
	}

	if (Found)
	{
		UpdateFlightRec();
		return 0;
	}

	cout << "\tThis Flight " << fID << " is not found, we cannot edit the flight at this time" << endl;
	return 0;

}

////////////////////////////////////////////////////

void Flight::DelFlight (int fID)
{
	int flightID;
	int Found = 0;

	//cout << "Del Flight List Size before" << FlightList.size() << endl;

	if (FlightList.size() == 0)
	{
		cout << "\t There is no Flight rec, nothing to delete" << endl;
		return;
	}

	for(unsigned int i=0; i<FlightList.size(); i++)
	{
		flightID = FlightList[i].GetFlightID ();

		//FlightList[i].GetPlaneID (planeID);
		//cout << "\t Available Flight ID " << flightID << endl;

		if (flightID == fID)
		{
			Found = 1;
			cout << "\tFound the Flight ID " << fID << " Delete this Flight record" << endl;

			// Delete this one from Flight list
			FlightList.erase(FlightList.begin() + i);
			break;
		}
	}

	if (!Found)
		cout << "\t This Flight ID " << fID << " is NOT found" << endl;
	else
		UpdateFlightRec();
	//cout << "Del Flight List Size after" << FlightList.size() << endl;
}

////////////////////////////////////////////////////

int Flight::SearchFlight (int fID)
{
	int Found = 0;
	int flightID;

	//cout << "Search: Flight List Size " << FlightList.size() << endl;
	if (FlightList.size() == 0)
	{
		cout << "\t There is no Flight rec, nothing to search" << endl;
		Found = 0;
		return Found;
	}

	for(unsigned int i=0; i<FlightList.size(); i++)
	{
		flightID = FlightList[i].GetFlightID ();
		cout << "\t Available Flight ID " << flightID << endl;

		if (flightID == fID)
		{
			cout << "\t Found the Flight ID " << flightID << endl;
			Found = 1;
			break;
		}
	}

	if (!Found)
	{
		cout << "\t Flight " << fID << " is NOT found" << endl;
		return Found;
	}

	return Found;
}

///////////////////////////////////////////////////
void Flight::PrintAFlight (int fID)
{
	int flightID;
	char planeID[40];
	tm   sTime;
	tm   eTime;
	char sAirportCode[40];   
	char eAirportCode[40];   

	if (FlightList.size() == 0)
	{
		cout << "\tThere is no Flight rec, nothing to print A Flight" << endl;
		return;
	}

	for(unsigned int i=0; i<FlightList.size(); i++)
	{
		flightID = FlightList[i].GetFlightID ();
		if (flightID == fID)
		{
			cout << endl << "\tFlight ID found: " << flightID << endl;

			FlightList[i].GetStartTime (sTime);
			FlightList[i].GetEndTime (eTime);
			FlightList[i].GetStartAirportCode (sAirportCode);
			FlightList[i].GetEndAirportCode (eAirportCode);

			FlightList[i].GetPlaneID (planeID);

			cout << endl << "\tPlane ID " << planeID << endl;
			cout << "\tNum of Pilots " << FlightList[i].GetNumPilot() << endl;
			cout << "\tNum of Cabin Crews " << FlightList[i].GetNumCabinCrew() << endl;

			cout << "\tStart Time: " << sTime.tm_hour << ":" << sTime.tm_min << " " << sTime.tm_mon+1 << "/" << sTime.tm_mday << "/" << sTime.tm_year+1900 << endl;
			cout << "\tEnd Time:   " << eTime.tm_hour << ":" << eTime.tm_min << " " << eTime.tm_mon+1 << "/" << eTime.tm_mday << "/" << eTime.tm_year+1900 << endl;
			cout << "\tStart Airport Code " << sAirportCode << endl;
			cout << "\tEnd   Airport Code " << eAirportCode << endl;
            cout << "\tNum of Passengers " << FlightList[i].GetNumPassenger () << endl;
			int status = FlightList[i].GetPlaneStatus();
			if (status == ACTIVE)
				cout << "\tPlane Status: Active" << endl;
		
			if (status == COMPLETE)
				cout << "\tPlane Status: Completed" << endl;

			if (status == CALCEL)
				cout << "\tPlane Status: Cancelled" << endl;

			break;
		}
	}
}

///////////////////////////////////////////////////

void Flight::PrintAllFlight ()
{
	char planeID[40];
	tm   sTime;
	tm eTime;
	char sAirportCode[40];  
	char eAirportCode[40];   

	if (FlightList.size() == 0)
	{
		cout << "\tThere is no Flight rec, nothing to print ALL Flight" << endl;
		return;
	}

	for(unsigned int i=0; i<FlightList.size(); i++)
	{
		FlightList[i].GetPlaneID (planeID);
		FlightList[i].GetStartTime (sTime);
		FlightList[i].GetEndTime (eTime);
		FlightList[i].GetStartAirportCode (sAirportCode);
		FlightList[i].GetEndAirportCode (eAirportCode);

		cout << endl << "#" << i+1 << "\tFlight ID " << FlightList[i].GetFlightID () << endl;
		cout << "\tPlane ID " << planeID << endl;
		cout << "\tNum of Pilots " << FlightList[i].GetNumPilot() << endl;
		cout << "\tNum of Cabin Crews " << FlightList[i].GetNumCabinCrew() << endl;
	    cout << "\tStart Time: " << sTime.tm_hour << ":" << sTime.tm_min << " " << sTime.tm_mon+1 << "/" << sTime.tm_mday << "/" << sTime.tm_year+1900 << endl;
	    cout << "\tEnd Time:   " << eTime.tm_hour << ":" << eTime.tm_min << " " << eTime.tm_mon+1 << "/" << eTime.tm_mday << "/" << eTime.tm_year+1900 << endl;
		cout << "\tStart Airport Code " << sAirportCode << endl;
		cout << "\tEnd   Airport Code " << eAirportCode << endl;
        cout << "\tNum of Passengers " << FlightList[i].GetNumPassenger () << endl;

		int status = FlightList[i].GetPlaneStatus();
		if (status == ACTIVE)
			cout << "\tPlane Status: Active" << endl;
		
		if (status == COMPLETE)
			cout << "\tPlane Status: Completed" << endl;

		if (status == CALCEL)
			cout << "\tPlane Status: Cancelled" << endl;
	}
}

//////////////////////////////////////////////////

void Flight::UpdateFlightRec ()
{
	// Write Flight List to file
	ofstream ofile;

	// Open the file in write
	ofile.open("FlightRec.txt", ios::out | ios::binary | ios::beg);

	if(!ofile)
	{
		cout << "\tError in UpdateFlightRec opening file !!!"<< endl;
		return;
	}

	for (int i=0; i<(int) FlightList.size(); i++)
	{
		// Write the record to the file
		ofile.write((char *) &FlightList[i], sizeof (FlightRec));
	}

	ofile.close();
}

/////////////////////////////////////////////////////

void Flight::GetFlightRecFile ()
{
	ifstream infile;
	FlightRec FRec;

	infile.open("FlightRec.txt", ios::in | ios::binary);
	if(!infile)
	{
		cout<<"\tError in GetFlightRecFile opening read file !!!"<<endl;
		return;
	}

	while (infile.read((char *) &FRec, sizeof (FlightRec)))
	{
		// Add to the Crew list
		FlightList.push_back(FRec);
	}

	infile.close();
}

////////////////////////////////////////////////////////////
// Print Crew List for all flights

void Flight::PrintfCrewList()
{
	int NumCabinCrew;
	int NumPilot;
	int pID[4];
	int ccID[16];

	if (FlightList.size() == 0)
	{
		cout << "\tThere is no Flight rec, nothing to print ALL Flight" << endl;
		return;
	}

	for(unsigned int i=0; i<FlightList.size(); i++)
	{
		cout << endl << "#" << i+1 << "\tFor Flight ID " << FlightList[i].GetFlightID () << endl;
		NumCabinCrew = FlightList[i].GetNumCabinCrew();
		NumPilot = FlightList[i].GetNumPilot();
		FlightList[i].GetPilotID(pID);
		FlightList[i].GetCabinCrewID(ccID);

		cout << "\t Pilot List:" << endl;
		for (int i=0; i<NumPilot; i++)
			cout << "\t Pilot ID: " << pID[i] << endl;

		cout << "\n\t Cabin Crew List:" << endl;
		for (int i=0; i<NumCabinCrew; i++)
			cout << "\t Cabin Crew ID: " << ccID[i] << endl;
	}
}

///////////////////////////////////////////////////

void Flight::PrintAssignmentScheduleforPlane (char pID[])
{
	char planeID[40];
	tm   sTime;
	tm   eTime;
	char sAirportCode[40];   
	char eAirportCode[40];   
	if (FlightList.size() == 0)
	{
		cout << "\tThere is no Flight rec, no schedule to print" << endl;
		return;
	}

	for(unsigned int i=0; i<FlightList.size(); i++)
	{
		int status = FlightList[i].GetPlaneStatus();
		FlightList[i].GetPlaneID (planeID);
		if (strcmp (pID, planeID) == 0 && (status == ACTIVE))
		{
			cout << endl << "\tPlane ID found: " << pID << endl;

			FlightList[i].GetStartTime (sTime);
			FlightList[i].GetEndTime (eTime);
			FlightList[i].GetStartAirportCode (sAirportCode);
			FlightList[i].GetEndAirportCode (eAirportCode);

			FlightList[i].GetPlaneID (planeID);

			cout << endl << "\tPlane ID " << planeID << endl;
			cout << "\t Fight ID " << FlightList[i].GetFlightID() << endl;
			cout << "\tNum of Pilots " << FlightList[i].GetNumPilot() << endl;
			cout << "\tNum of Cabin Crews " << FlightList[i].GetNumCabinCrew() << endl;

			cout << "\tStart Time: " << sTime.tm_hour << ":" << sTime.tm_min << " " << sTime.tm_mon+1 << "/" << sTime.tm_mday << "/" << sTime.tm_year+1900 << endl;
			cout << "\tEnd Time:   " << eTime.tm_hour << ":" << eTime.tm_min << " " << eTime.tm_mon+1 << "/" << eTime.tm_mday << "/" << eTime.tm_year+1900 << endl;
			cout << "\tStart Airport Code " << sAirportCode << endl;
			cout << "\tEnd   Airport Code " << eAirportCode << endl;
            cout << "\tNum of Passengers " << FlightList[i].GetNumPassenger () << endl;
			int status = FlightList[i].GetPlaneStatus();
			if (status == ACTIVE)
				cout << "\tPlane Status: Active" << endl;
		
			if (status == COMPLETE)
				cout << "\tPlane Status: Completed" << endl;

			if (status == CALCEL)
				cout << "\tPlane Status: Cancelled" << endl;
		}
	}
}

//////////////////////////////////////////////////

void Flight::PrintAssignmentScheduleforCrew (int cID)
{
	char planeID[40];
	tm   sTime;
	tm   eTime;
	char sAirportCode[10];   
	char eAirportCode[10];
	int crewID[16];
	int pID[4];
	int cIDFound = 0;

	if (FlightList.size() == 0)
	{
		cout << "\tThere is no Flight rec, no schedule to print" << endl;
		return;
	}

	for(unsigned int i=0; i<FlightList.size(); i++)
	{
		// Check for cabin crew ID
		FlightList[i].GetCabinCrewID(crewID);
		for (int j=0; j<16; j++)
		{
			if (crewID[j] == cID)
			{
				cIDFound = 1;
				break;
			}
		}

		if (!cIDFound)
		{
			FlightList[i].GetPilotID(pID);
			for (int j=0; j<4; j++)
			{
				if (pID[j] == cID)
				{
					cIDFound = 1;
					break;
				}
			}
		}

		if (!cIDFound)
		{
			cout << "\t There is NO such as crew member " << cID << " found" << endl;
			return;
		}

		int status = FlightList[i].GetPlaneStatus();
		FlightList[i].GetPlaneID (planeID);
		if (status == ACTIVE)
		{
			cout << endl << "\t Crew ID found: " << cID << endl;

			FlightList[i].GetStartTime (sTime);
			FlightList[i].GetEndTime (eTime);
			FlightList[i].GetStartAirportCode (sAirportCode);
			FlightList[i].GetEndAirportCode (eAirportCode);

			FlightList[i].GetPlaneID (planeID);

			cout << endl << "\tPlane ID " << planeID << endl;
			cout << "\t Fight ID " << FlightList[i].GetFlightID() << endl;
			cout << "\tNum of Pilots " << FlightList[i].GetNumPilot() << endl;
			cout << "\tNum of Cabin Crews " << FlightList[i].GetNumCabinCrew() << endl;

			cout << "\tStart Time: " << sTime.tm_hour << ":" << sTime.tm_min << " " << sTime.tm_mon+1 << "/" << sTime.tm_mday << "/" << sTime.tm_year+1900 << endl;
			cout << "\tEnd Time:   " << eTime.tm_hour << ":" << eTime.tm_min << " " << eTime.tm_mon+1 << "/" << eTime.tm_mday << "/" << eTime.tm_year+1900 << endl;
			cout << "\tStart Airport Code " << sAirportCode << endl;
			cout << "\tEnd   Airport Code " << eAirportCode << endl;
            cout << "\tNum of Passengers " << FlightList[i].GetNumPassenger () << endl;
			int status = FlightList[i].GetPlaneStatus();
			if (status == ACTIVE)
				cout << "\tPlane Status: Active" << endl;
		
			if (status == COMPLETE)
				cout << "\tPlane Status: Completed" << endl;

			if (status == CALCEL)
				cout << "\tPlane Status: Cancelled" << endl;
		}
	}
}

///////////////////////////////////////////////////////////////////////////////

void Flight::DeleteCancel_or_Complete_flight ()
{
	int Found = 0;

	if (FlightList.size() == 0)
	{
		cout << "t There is no Flight rec, nothing to delete" << endl;
		return;
	}

	for(unsigned int i=0; i<FlightList.size(); i++)
	{
		int status = FlightList[i].GetPlaneStatus();
		if (status == COMPLETE || status == CALCEL)
		{
			Found = 1;
			cout << "\tFound Completed or Cancelled flight: " <<  "Delete this Flight " << FlightList[i].GetFlightID() << " Record" << endl;

			// Delete this one from Flight list
			FlightList.erase(FlightList.begin() + i);
			break;
		}
	}

	if (!Found)
	{
		cout << "\t No Delete or Completed Plane status found" << endl;
	}
	else
		UpdateFlightRec();
}

//////////////////////////////////////////////////////////

void Flight::PrintFlightOnStatus (int fStatus)
{
	char planeID[40];
	tm   sTime;
	tm   eTime;
	char sAirportCode[10];   
	char eAirportCode[10];
	int Found = 0;

	if (FlightList.size() == 0)
	{
		cout << "\t There is no Flight rec, no assignment to print" << endl;
		return;
	}

	for(unsigned int i=0; i<FlightList.size(); i++)
	{
		int status = FlightList[i].GetPlaneStatus();
        if (status == fStatus)
		{
			Found = 1;
			FlightList[i].GetStartTime (sTime);
			FlightList[i].GetEndTime (eTime);
			FlightList[i].GetStartAirportCode (sAirportCode);
			FlightList[i].GetEndAirportCode (eAirportCode);

			FlightList[i].GetPlaneID (planeID);

			cout << endl << "\tPlane ID " << planeID << endl;
			cout << "\t Fight ID " << FlightList[i].GetFlightID() << endl;
			cout << "\tNum of Pilots " << FlightList[i].GetNumPilot() << endl;
			cout << "\tNum of Cabin Crews " << FlightList[i].GetNumCabinCrew() << endl;

			cout << "\tStart Time: " << sTime.tm_hour << ":" << sTime.tm_min << " " << sTime.tm_mon+1 << "/" << sTime.tm_mday << "/" << sTime.tm_year+1900 << endl;
			cout << "\tEnd Time: " << eTime.tm_hour << ":" << eTime.tm_min << " " << eTime.tm_mon+1 << "/" << eTime.tm_mday << "/" << eTime.tm_year+1900 << endl;
			cout << "\tStart Airport Code " << sAirportCode << endl;
			cout << "\tEnd   Airport Code " << eAirportCode << endl;
            cout << "\tNum of Passengers " << FlightList[i].GetNumPassenger () << endl;
			if (status == ACTIVE)
				cout << "\tPlane Status: Active" << endl;
		
			if (status == COMPLETE)
				cout << "\tPlane Status: Completed" << endl;

			if (status == CALCEL)
				cout << "\tPlane Status: Cancelled" << endl;
		}
	}

	if (!Found)
	{
		cout << "\t Plane Status not found" << endl;
	}
}

///////////////////////////////////////////////////////////

void Flight::UpdateFightActiveToCompletedStatus ()
{
	time_t scheduled_time, curr_time;
	tm NowTime, endTime;

	if (FlightList.size() == 0)
	{
		cout << "\t There is no Flight rec in UpdateFightActiveToCompleted()" << endl;
		return;
	}

	curr_time = time(NULL);
	NowTime = *localtime(&curr_time);

	curr_time = mktime(&NowTime);

	for(unsigned int i=0; i<FlightList.size(); i++)
	{
		FlightList[i].GetEndTime (endTime);
		scheduled_time = mktime(&endTime);
		if (difftime(curr_time, scheduled_time) > 0.0)
		{
			cout << "\t Change Active to Completed status for Flight ID: " << FlightList[i].GetFlightID() << endl;
			FlightList[i].SetPlaneStatus (COMPLETE);
		}
		else
		{
			cout << "\t Flight " << FlightList[i].GetFlightID() << " from active to completed status NOT observed" << endl;
		}
	}

	// Save to file
	UpdateFlightRec();
}

//////////////////////////////////////////////////

int Flight::IsTimeConflictOnPlane (char pID[], tm begTime, tm endTime)
{
	int  Found = 0;
	char planeID[40];
	tm   sTime;

	if (FlightList.size() == 0)
	{
		//cout << "\t There is no Flight rec, Do not need to Check Time Conflict on Plane" << endl;
		// Let go, no need to block.
		Found = 0;
		return Found;
	}


	for(unsigned int i=0; i<FlightList.size(); i++)
	{
		FlightList[i].GetPlaneID (planeID);
		if (strcmp (pID, planeID) == 0)
		{
			FlightList[i].GetStartTime (sTime);

            if (begTime.tm_hour == sTime.tm_hour && begTime.tm_min == sTime.tm_min)
			{
				cout << "\t Time conflict for plane " << pID << " found" << endl;
				Found = 1;
				return Found;
			}

			// input End hour is less than Recorded start hour, this is time overlap
			if (endTime.tm_hour <= sTime.tm_hour)
			{
				cout << "\t Time overlap for plane " << pID << " found" << endl;
				Found = 1;
				return Found;
			}
		}
	}

	return Found;
}

//////////////////////////////////////////////////

int Flight::IsTimeConflictOnCrewMember (int nCabinCrew, int nPilot, tm begTime, tm endTime)
{
	int Found = 0;
	tm  sTime;
	int crewID[16];
	int pID[4];

	if (FlightList.size() == 0)
	{
		//cout << "\t There is no Flight rec, Do not need to Check on Crew Member Time Conflict" << endl;
		Found = 0;
		return Found;
	}

	for(unsigned int i=0; i<FlightList.size(); i++)
	{
		FlightList[i].GetStartTime (sTime);
		FlightList[i].GetCabinCrewID(crewID);
		for (int j=0; j<nCabinCrew; j++)
		{
            if (begTime.tm_hour == sTime.tm_hour && begTime.tm_min == sTime.tm_min)
			{
				cout << "\t Time conflict for cabin crew " << "found" << endl;
				Found = 1;
				return Found;
			}

			if (endTime.tm_hour <= sTime.tm_hour)
			{
				cout << "\t Time overlap for cabin crew " << "found" << endl;
				Found = 1;
				return Found;
			}
		}

		FlightList[i].GetPilotID(pID);
		for (int k=0; k<nPilot; k++)
		{
            if (begTime.tm_hour == sTime.tm_hour && begTime.tm_min == sTime.tm_min)
			{
				cout << "\t Time conflict for Pilot " << "found" << endl;
				Found = 1;
				return Found;
			}

			if (endTime.tm_hour <= sTime.tm_hour)
			{
				cout << "\t Time overlap for Pilot " << "found" << endl;
				Found = 1;
				return Found;
			}
		}
	}

	return Found;
}


