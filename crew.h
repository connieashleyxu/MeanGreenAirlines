#include "crewRec.h"

////////////////////////////////////////////////

class Crew
{
  private:
  public:    
		Crew ();
		~Crew ();

		vector<CrewRec> CrewList;

		vector <int> ListPilotID;
	    vector <int> ListCabinCrewID;

		int AddCrew (int cID, char cName[], char cType);
		int EditCrew (int cID, char cName[], char cType);
		void DelCrew (int cID);
		int SearchCrew (int cID);
		void PrintACrew (int cID);
		void PrintAllCrew ();

		void GetCrewRecFile ();
		void UpdateCrewRec ();
		void GetCrewID (int CabinCrewID[16], int PilotID[4]);
		void PrintCrewList ();
};
