#include "stdafx.h"
#include <iostream>
#include <fstream> 
#include <string>

using namespace std;

#include "flightRec.h"

FlightRec::FlightRec ()
{
	for (int i=0; i<4; i++)
		pilotID[i] = 0;

	for (int i=0; i<16; i++)
		CabinCrewID[0] = 0;
}

////////////////////////////////////////

FlightRec::~FlightRec()
{
}

////////////////////////////////////////
int FlightRec::GetFlightID ()
{
	return FlightID;
}

///////////////////////////////////////////

void FlightRec::SetFlightID (int fID)
{
	FlightID = fID;
}

////////////////////////////////////////////

void FlightRec::GetPlaneID (char pID[])
{
	strcpy (pID, PlaneID);
}

///////////////////////////////////////

void FlightRec::SetPlaneID (char pID[])
{
	strcpy (PlaneID, pID);
}

///////////////////////////////////////

int FlightRec::GetNumPilot ()
{
	return numPilots;
}

////////////////////////////////////////

void FlightRec::SetNumPilot (int NumPilot)
{
	numPilots = NumPilot;
}

///////////////////////////////////////

int FlightRec::GetNumCabinCrew ()
{
	return numCabinCrews;
}

///////////////////////////////////////

void FlightRec::SetNumCabinCrew (int NumCrew)
{
	numCabinCrews = NumCrew;
}

/////////////////////////////////////////
void FlightRec::GetStartTime (tm& sTime)
{
	memcpy ((tm *)&sTime, (tm *)&StartTime, sizeof (tm));
	//cout << "FlightRec::GetStartTime: " << sTime.tm_hour << ":" << sTime.tm_min << endl;
}

//////////////////////////////////////////
void FlightRec::SetStartTime (tm sTime)
{
	memcpy ((tm *)&StartTime, (tm *)&sTime, sizeof (tm));
	//cout << "FlightRec::SetStartTime: " << sTime.tm_hour << ":" << sTime.tm_min << endl;
}

///////////////////////////////////////////

void FlightRec::GetEndTime (tm& eTime)
{
	memcpy ((tm *)&eTime, (tm *)&EndTime, sizeof (tm));
	//cout << "FlightRec::GetEndTime: " << eTime.tm_hour << ":" << eTime.tm_min << endl;
}

///////////////////////////////////////////

void FlightRec::SetEndTime (tm eTime)
{
	memcpy ((tm *)&EndTime, (tm *)&eTime, sizeof (tm));
	//cout << "FlightRec::SetEndTime: " << EndTime.tm_hour << ":" << EndTime.tm_min << endl;
}

////////////////////////////////////////////////

void FlightRec::GetStartAirportCode (char sCode[])
{
	strcpy (sCode, StartAirportCode);
}

/////////////////////////////////////////
void FlightRec::SetStartAirportCode (char sCode[])
{
	strcpy (StartAirportCode, sCode);
}

///////////////////////////////////////////
void FlightRec::GetEndAirportCode (char eCode[])
{
	strcpy (eCode, EndAirportCode);
}

////////////////////////////////////////////////
void FlightRec::SetEndAirportCode (char eCode[])
{
	strcpy (EndAirportCode, eCode);
}

///////////////////////////////////////////////
int FlightRec::GetNumPassenger ()
{
	return numOfPassenger;
}

/////////////////////////////////////////////////
void FlightRec::SetNumPassenger (int PassengerNum)
{
	numOfPassenger = PassengerNum;
}

////////////////////////////////////////////////
int FlightRec::GetPlaneStatus ()
{
	return PlaneStatus;
}

/////////////////////////////////////////////////
void FlightRec::SetPlaneStatus (int pStatus)
{
	PlaneStatus = pStatus;
}

///////////////////////////////////////////////

void FlightRec::GetPilotID (int *pID)
{
	for (int i=0; i<4; i++)
	{
	   pID[i] = pilotID[i];
	}
}

////////////////////////////////////////////////

void FlightRec::SetPilotID (int *pID)
{
	for (int i=0; i<4; i++)
	{
	   pilotID[i] = pID[i];
	}
}

///////////////////////////////////////////////
void FlightRec::GetCabinCrewID (int *cID)
{
	for (int i=0; i<16; i++)
	{
	   cID[i] = CabinCrewID[i];
	}
}

///////////////////////////////////////////////
void FlightRec::SetCabinCrewID (int *cID)
{
	for (int i=0; i<16; i++)
	{
	   CabinCrewID[i] = cID[i];
	}
}

