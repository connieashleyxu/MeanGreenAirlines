#include "stdafx.h"
#include <iostream>
#include <fstream> 
#include <string>

using namespace std;

#include "planeRec.h"

//////////////////////////////////////////
PlaneRec::PlaneRec ()
{
	NumSeats = 0;
	Range = 0;
	MinCabinCrew = 0;
}

/////////////////////////////////////////
PlaneRec::~PlaneRec ()
{
}

/////////////////////////////////////////
void PlaneRec::GetPlaneID (char pID[])
{
	strcpy (pID, PlaneID);
}

/////////////////////////////////////////
void PlaneRec::SetPlaneID (char pID[])
{
	strcpy (PlaneID, pID);
}

/////////////////////////////////////////
void PlaneRec::GetPlaneMake (char pMake[])
{
	strcpy (pMake, Make);
}

/////////////////////////////////////////
void PlaneRec::SetPlaneMake (char pMake[])
{
	strcpy (Make, pMake);
}

/////////////////////////////////////////
void PlaneRec::GetPlaneModel (char pModel[])
{
	strcpy (pModel, Model);
}

/////////////////////////////////////////
void PlaneRec::SetPlaneModel (char pModel[])
{
	strcpy (Model, pModel);
}

/////////////////////////////////////////
int PlaneRec::GetPlaneSeats ()
{
	return NumSeats;
}

/////////////////////////////////////////
void PlaneRec::SetPlaneSeats (int NumSeat)
{
	NumSeats = NumSeat;
}

/////////////////////////////////////////
int PlaneRec::GetPlaneRange ()
{
	return Range;
}

/////////////////////////////////////////
void PlaneRec::SetPlaneRange (int Distance)
{
	Range = Distance;
}

/////////////////////////////////////////
int PlaneRec::GetMinCabinCrew ()
{
	return MinCabinCrew;
}

/////////////////////////////////////////
void PlaneRec::SetMinCabinCrew (int MinCrewNum)
{
	MinCabinCrew = MinCrewNum;
}
