#include "stdafx.h"
#include <iostream>
#include <fstream> 
#include <string>
using namespace std;

#include "plane.h"
#include "flight.h"

///////////////////////////////////

Plane::Plane ()
{

}

///////////////////////////////////////

Plane::~Plane ()
{

}

/////////////////////////////////////

int Plane::AddPlane (char pID[], char pMake[], char pModel[], int pSeats, int pRange, int pMinCrewNum)
{
	int Found = 0;
	char planeID[40];
	PlaneRec pRec;
    unsigned int pList;

	pList = PlaneList.size();
	//cout << "Add Plane List Size " << pList << endl;

	// First time to add to the crew vector
	if (pList == 0)
	{
		pRec.SetPlaneID (pID);
		pRec.SetPlaneMake (pMake);
		pRec.SetPlaneModel (pModel);
		pRec.SetPlaneSeats (pSeats);
		pRec.SetPlaneRange (pRange);
		pRec.SetMinCabinCrew (pMinCrewNum);
		// Add to the list
		PlaneList.push_back(pRec);

		pList = 1;
	}
	else
	{
		for(unsigned int i=0; i<pList; i++)
		{
			PlaneList[i].GetPlaneID (planeID);
			//cout << "\t Plane ID " << planeID << endl;

		    if (strcmp (pID, planeID) == 0)
			{
				cout << "\t This Plane already exists. Do not add to the record" << endl;
				Found = 1;
				return Found;
			}
		}

		// Add this to the Plane record
		pRec.SetPlaneID (pID);
		pRec.SetPlaneMake (pMake);
		pRec.SetPlaneModel (pModel);
		pRec.SetPlaneSeats (pSeats);
		pRec.SetPlaneRange (pRange);
		pRec.SetMinCabinCrew (pMinCrewNum);
		// Add to the list
		PlaneList.push_back(pRec);
		cout << "\t Plane ID " << pID << " added to the Plane list" << endl;
	}

    UpdatePlaneRec();
	return Found;
}

//////////////////////////////////////////////////////////////////

int Plane::EditPlane (char pID[], char pMake[], char pModel[], int pSeats, int pRange, int pMinCrewNum)
{
	int Found = 0;
	char planeID[40];

	//cout << "Edit Plane List Size " << PlaneList.size() << endl;
	if (PlaneList.size() == 0)
	{
		cout << "\t There is no Plane rec, Nothing to edit" << endl;
		Found = 0;
		return Found;
	}

	for(unsigned int i=0; i<PlaneList.size(); i++)
	{
		PlaneList[i].GetPlaneID (planeID);
		cout << "\t Plane ID " << planeID << endl;

		if (strcmp (pID, planeID) == 0)
		{
			cout << "\t Found the Plane record" << endl;

			PlaneList[i].SetPlaneID (pID);
			PlaneList[i].SetPlaneMake (pMake);
			PlaneList[i].SetPlaneModel (pModel);
			PlaneList[i].SetPlaneSeats (pSeats);
			PlaneList[i].SetPlaneRange (pRange);
			PlaneList[i].SetMinCabinCrew (pMinCrewNum);
			Found = 1;
			break;
		}
	}

	if (Found)
	{
		UpdatePlaneRec();
		return 0;
	}

	cout << "\t This Plane is not found, we cannot edit Plane at this time" << endl;
	return 0;
}

/////////////////////////////////////

void Plane::DelPlane (char pID[])
{
	char planeID[40];
	int Found = 0;
	//cout << "Del Plane List Size before" << PlaneList.size() << endl;

	if (PlaneList.size() == 0)
	{
		cout << "\t There is no Plane rec, nothing to delete" << endl;
		return;
	}

	for(unsigned int i=0; i<PlaneList.size(); i++)
	{

		PlaneList[i].GetPlaneID (planeID);
		cout << "\t Plane ID " << planeID << endl;

		//if(pID.compare(planeID))
		if (strcmp (pID, planeID) == 0)
		{
			Found = 1;
			cout << "\tFound the Plane ID " << planeID << ", Delete this Plane record" << endl;

			// Delete this one from Plane list
			PlaneList.erase(PlaneList.begin() + i);
			break;
		}
	}

	if (!Found)
		cout << "\t Plane ID is not FOUND" << endl;
	else
		UpdatePlaneRec();
	//cout << "Del Plane List Size after" << PlaneList.size() << endl;
}

/////////////////////////////////////

int Plane::SearchPlane (char pID[], int& Seats)
{
	int Found = 0;
	char planeID[40];

	//cout << "Search: Plane List Size " << PlaneList.size() << endl;
	if (PlaneList.size() == 0)
	{
		cout << "\t There is no Plane rec, nothing to search" << endl;
		Seats = 0;
		return Found;
	}

	for(unsigned int i=0; i<PlaneList.size(); i++)
	{
		PlaneList[i].GetPlaneID (planeID);
		cout << "\tPlane ID " << planeID << endl;

		//if(pID.compare(planeID))
		if (strcmp (pID, planeID) == 0)
		{
			Seats = PlaneList[i].GetPlaneSeats ();
			cout << "\t Found the Plane ID " << pID << ",  Seats available " << Seats << endl;
			Found = 1;
			break;
		}
	}

	if (!Found)
	{
		cout << "\t Plane is NOT found" << endl;
		Seats = 0;
	}

	return Found;
}

/////////////////////////////////////

void Plane::PrintAPlane (char pID[])
{
	char pMake[40];
	char pModel[40];
	char planeID[40];

	if (PlaneList.size() == 0)
	{
		cout << "\t There is no Plane rec, nothing to print A Plane" << endl;
		return;
	}

	for(unsigned int i=0; i<PlaneList.size(); i++)
	{
		PlaneList[i].GetPlaneID (planeID);
		if (strcmp (pID, planeID) == 0)
		{
			cout << endl << "\tPlane ID " << planeID << endl;

			PlaneList[i].GetPlaneMake (pMake);
			PlaneList[i].GetPlaneModel (pModel);

			cout << "\tPlane Make " << pMake << endl;
			cout << "\tPlane Model " << pModel << endl;
			cout << "\tPlane num of seats " << PlaneList[i].GetPlaneSeats() << endl;
			cout << "\tPlane flight range " << PlaneList[i].GetPlaneRange() << endl;
			cout << "\tPlane min number of cabin crew " << PlaneList[i].GetMinCabinCrew() << endl;
			break;
		}
	}
}

/////////////////////////////////////

void Plane::PrintAllPlane ()
{
	char pMake[40];
	char pModel[40];
	char planeID[40];

	if (PlaneList.size() == 0)
	{
		cout << " There is no Plane rec, nothing to print ALL plane" << endl;
		return;
	}

	for(unsigned int i=0; i<PlaneList.size(); i++)
	{
		PlaneList[i].GetPlaneID (planeID);
		PlaneList[i].GetPlaneMake (pMake);
		PlaneList[i].GetPlaneModel (pModel);

		cout << endl << "#" << i+1 << "\tPlane ID " << planeID << endl;
		cout << "\tPlane Make " << pMake << endl;
		cout << "\tPlane Model " << pModel << endl;
		cout << "\tPlane num of seats " << PlaneList[i].GetPlaneSeats() << endl;
		cout << "\tPlane flight range " << PlaneList[i].GetPlaneRange() << endl;
		cout << "\tPlane min number of cabin crew " << PlaneList[i].GetMinCabinCrew() << endl;
	}
}

/////////////////////////////////////

void Plane::UpdatePlaneRec ()
{
	// Write Crew List to file
	ofstream ofile;

	// Open the file in write
	ofile.open("PlaneRec.txt", ios::out | ios::binary | ios::beg);
	if(!ofile)
	{
		cout << "\tError in UpdatePlaneRec opening write file !!!"<< endl;
		return;
	}

	for (unsigned int i=0; i<PlaneList.size(); i++)
	{
		// Write the record to the file
		ofile.write((char *) &PlaneList[i], sizeof (PlaneRec));
	}

	ofile.close();
}

////////////////////////////////////////////////////////////////////

void Plane::GetPlaneRecFile ()
{
	ifstream infile;
	PlaneRec pRec;

	infile.open("PlaneRec.txt", ios::in | ios::binary);
	if(!infile)
	{
		cout<<"\tError in GetPlaneRec File opening read file !!!"<<endl;
		return;
	}

	while (infile.read((char *) &pRec, sizeof (PlaneRec)))
	{
		// Add to the list
		PlaneList.push_back(pRec);
	}

	infile.close();
}

////////////////////////////////////////////////////////////

int  Plane::SearchMinNumCabinCrew (char pID[])
{
	int Found = 0;
	char planeID[40];

	//cout << "Search: Plane List Size " << PlaneList.size() << endl;
	if (PlaneList.size() == 0)
	{
		cout << "\t There is no Plane rec, nothing to search" << endl;
		return Found;
	}

	for(unsigned int i=0; i<PlaneList.size(); i++)
	{
		PlaneList[i].GetPlaneID (planeID);
		//cout << "\tPlane ID " << planeID << endl;

		//if(pID.compare(planeID))
		if (strcmp (pID, planeID) == 0)
		{
			cout << "\t Found the Plane ID " << pID << ",  Min Num of Crew " <<  PlaneList[i].GetMinCabinCrew() << endl;
			return PlaneList[i].GetMinCabinCrew();
		}
	}

	if (!Found)
	{
		cout << "\t Plane is NOT found" << endl;
	}

	return Found;
}
