#include "planeRec.h"

//////////////////////////////////////////////////

class Plane
{
  private:
  public:    
    Plane ();
	~Plane ();

	vector<PlaneRec> PlaneList;

	int AddPlane (char pID[], char pMake[], char pModel[], int pSeats, int pRange, int pMinCrewNum);
	int EditPlane (char pID[], char pMake[], char pModel[], int pSeats, int pRange, int pMinCrewNum);
	void DelPlane (char pID[]);
	int SearchPlane (char pID[], int& Seats);
	void PrintAPlane (char pID[]);
	void PrintAllPlane ();

    void GetPlaneRecFile ();
	void UpdatePlaneRec ();
	int  SearchMinNumCabinCrew (char pID[]);
};
