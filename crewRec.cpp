#include "stdafx.h"
#include <iostream>
#include <fstream> 
#include <string>

using namespace std;

#include "crewRec.h"

//////////////////////////////////////////

CrewRec::CrewRec()
{
}

/////////////////////////////////////////

CrewRec::~CrewRec ()
{
}
///////////////////////////////////////

int CrewRec::GetCrewID ()
{
	return CrewID;
}

///////////////////////////////////////

void CrewRec::SetCrewID (int cID)
{
	CrewID = cID;
}

///////////////////////////////////////

void CrewRec::GetCrewName (char *cName)
{
   //cName = CrewName;
	strcpy (cName, CrewName);
}

///////////////////////////////////////

void CrewRec::SetCrewName (char cName[40])
{
	//CrewName = cName;
	strcpy (CrewName, cName);
}

///////////////////////////////////////

char CrewRec::GetCrewType ()
{
	return CrewType;
}

///////////////////////////////////////

void CrewRec::SetCrewType (char cType)
{
	CrewType = cType;
}


