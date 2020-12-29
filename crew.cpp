#include "stdafx.h"
#include <iostream>
#include <fstream> 
#include <string>
using namespace std;

//#include "flight.h"
#include "crew.h"

///////////////////////////////////

Crew::Crew ()
{
}

///////////////////////////////////////

Crew::~Crew ()
{

}

///////////////////////////////////////////////////////

int Crew::AddCrew (int cID, char cName[40], char cType) 
{
	int Found = 0;
	CrewRec CRec;
    unsigned int cList;

	// go through crew list to check crew ID and make sure crew member does not exist
    // otherwise, add object to crew list

	cList = CrewList.size();
	//cout << "Add Crew List Size " << cList << endl;

	// First time to add to the crew vector
	if (cList == 0)
	{
		// init the crew list
		CRec.SetCrewID (cID);
		CRec.SetCrewName (cName);
		CRec.SetCrewType (cType);
		// Add to the Crew list
		CrewList.push_back(CRec);
		cList = 1;
	}
	else
	{
		for(unsigned int i=0; i<cList; i++)
		{
			if ((cID == CrewList[i].GetCrewID()) && (cType == CrewList[i].GetCrewType()))
			{
				cout << "\t This Crew member already exists." << endl;
				Found = 1;
				return Found;
			}
		}

		cout << "\t Crew ID " << cID << " added to the Crew list" << endl;

		// No duplicate, add this to crew list
		CRec.SetCrewID (cID);
		CRec.SetCrewName (cName);
		CRec.SetCrewType (cType);
		// Add to the Crew list
		CrewList.push_back(CRec);
	}

	UpdateCrewRec();

	return Found;
}

/////////////////////////////////////////////////

int Crew::EditCrew (int cID, char cName[40], char cType) 
{
	int Found = 0;

	//cout << "Edit Crew List Size " << CrewList.size() << endl;
	if (CrewList.size() == 0)
	{
		cout << "\t There is no crew rec, Nothing to edit" << endl;
		Found = 0;
		return Found;
	}

	for (unsigned int i=0; i<CrewList.size(); i++)
	{
		if (cID == CrewList[i].GetCrewID())
		{
			cout << "\t Found the Crew: edit the Crew record" << endl;

			CrewList[i].SetCrewName (cName);
			CrewList[i].SetCrewType (cType);
			Found = 1;
			break;
		}
	}

	if (Found)
	{
		UpdateCrewRec();
		return 0;
	}

	cout << "\t This crew is not found, we cannot do edit at this time" << endl;
	return 0;
}

/////////////////////////////////////////////////

void Crew::DelCrew (int cID)
{
	int Found = 0;

	//cout << "Crew List Size " << CrewList.size() << endl;
	if (CrewList.size() == 0)
	{
		cout << "\t There is no crew rec, nothing to delete" << endl;
		return;
	}

	for (unsigned int i=0; i<CrewList.size(); i++)
	{
		if (cID == CrewList[i].GetCrewID())
		{
			cout << "\t Found the Crew and delete this crew record" << endl;
			Found = 1;
			// Delete this one from crew list
			CrewList.erase(CrewList.begin() + i);
			break;
		}
	}

	if (!Found)
		cout << "\t The Crew ID " << cID << " is not Found" << endl;
	else
		UpdateCrewRec();
}

/////////////////////////////////////////////////

int Crew::SearchCrew (int cID)
{
	int Found = 0;

	//cout << "Search: Crew List Size " << CrewList.size() << endl;
	if (CrewList.size() == 0)
	{
		cout << "\t There is no crew rec, nothing to search" << endl;
		return Found;
	}

	for(unsigned int i=0; i<CrewList.size(); i++)
	{
		if (cID == CrewList[i].GetCrewID())
		{
			cout << "\t Found the Crew ID " << cID << endl;
			Found = 1;
			break;
		}
	}

	return Found;
}

/////////////////////////////////////////////////

void Crew::PrintACrew (int cID)
{
	char cName[40];
	int Found = 0;

	if (CrewList.size() == 0)
	{
		cout << "\t There is no crew rec, nothing to print A crew" << endl;
		return;
	}

	for(unsigned int i=0; i<CrewList.size(); i++)
	{
		if (cID == CrewList[i].GetCrewID())
		{
			cout << endl << "\t Crew ID " << CrewList[i].GetCrewID() << endl;
			CrewList[i].GetCrewName (cName);
			cout << "\t Crew name " << cName << endl;
			cout << "\t Crew type " << CrewList[i].GetCrewType() << endl;
			Found = 1;
			break;
		}
	}

	if (Found == 0)
	{
	  cout << "\t Crew ID " << cID << "NOT found" << endl;
	}
}

/////////////////////////////////////////////////

void Crew::PrintAllCrew ()
{
	char cName[40];

	if (CrewList.size() == 0)
	{
		cout << "\t There is no crew rec, nothing to print ALL" << endl;
		return;
	}

	for(unsigned int i=0; i<CrewList.size(); i++)
	{
		cout << endl << "#" << i+1 << "\tCrew ID " << CrewList[i].GetCrewID() << endl;
		CrewList[i].GetCrewName (cName);
		cout << "\t Crew name " << cName << endl;
		cout << "\t Crew type " << CrewList[i].GetCrewType() << endl;
	}
}

//////////////////////////////////////////////////////////////////

void Crew::UpdateCrewRec ()
{
	// Write Crew List to file
	ofstream ofile;

	// Open the file in write
	ofile.open("CrewRec.txt", ios::out | ios::binary | ios::beg);
	if(!ofile)
	{
		cout << "\tError in UpdateCrewRec opening write file !!!"<< endl;
		return;
	}

	for (int i=0; i<(int) CrewList.size(); i++)
	{
		// Write the record to the file
		ofile.write((char *) &CrewList[i], sizeof (CrewRec));
	}

	ofile.close();
}

//////////////////////////////////////////////////////

void Crew::GetCrewRecFile ()
{
	ifstream infile;
	CrewRec CRec;

	infile.open("CrewRec.txt", ios::in | ios::binary);
	if(!infile)
	{
		cout<<"\tError in GetCrewRecFile opening read file !!!"<<endl;
		return;
	}

	while (infile.read((char *) &CRec, sizeof (CrewRec)))
	{
		// Add to the Crew list
		CrewList.push_back(CRec);
	}

	infile.close();
}

////////////////////////////////////////////////////

void Crew::GetCrewID (int CabinCrewID[16], int PilotID[4])
{
	int k=0, p=0;

	if (CrewList.size() == 0)
	{
		cout << "\t There is no crew rec in GetCrewID" << endl;
		return;
	}

	k=0;
	p=0;
	// Get from Crew list to add to pilot and cabin crew lists
	for(unsigned int i=0; i<CrewList.size(); i++)
	{
		cout << endl << "#" << i+1 << " Crew ID " << CrewList[i].GetCrewID() << endl;
		cout << "\t Crew type " << CrewList[i].GetCrewType() << endl;

		// If cabin crew, add to Cabin crew list
		if (CrewList[i].GetCrewType() == 'c')
		{
			cout << "\t Pilot ID added to the list" << endl;
			PilotID[k++] = CrewList[i].GetCrewID();
			ListPilotID.push_back(CrewList[i].GetCrewID());
		}

		// If Pilot, add to polot crew list
		if (CrewList[i].GetCrewType() == 'p')
		{
			cout << "\t Cabin crew ID Added to the list" << endl;
			CabinCrewID[p++] = CrewList[i].GetCrewID();
			ListCabinCrewID.push_back(CrewList[i].GetCrewID());
		}
	}
	cout << endl;
}

//////////////////////////////////////////////////////////////

void Crew::PrintCrewList ()
{
	if (ListPilotID.size() == 0)
	{
		cout << "\t There is no ListPilotID rec in PrintCrewList" << endl;
		return;
	}

	if (ListCabinCrewID.size() == 0)
	{
		cout << "\t There is no ListCabinCrewID rec in PrintCrewList" << endl;
		return;
	}

	cout << "\t Pilot ID List: " << endl;
	for (unsigned int i=0; i<ListPilotID.size(); i++)
	{
		cout << "\t " << ListPilotID[i] << endl;
	}

	cout << "\n\t Cabin Crew ID list: " << endl;
	for (unsigned int i=0; i<ListCabinCrewID.size(); i++)
	{
		cout << "\t " << ListCabinCrewID[i] << endl;
	}
}
