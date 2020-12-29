#include <string>
#include <vector>
using namespace std;

class PlaneRec
{
private:
	char  PlaneID[40];
	char  Make[40];
	char  Model[40];
	int   NumSeats;
	int   Range;
	int   MinCabinCrew;

public:
	PlaneRec();
	~PlaneRec();

	void GetPlaneID (char pID[]);
	void SetPlaneID (char pID[]);

	void GetPlaneMake (char pMake[]);
	void SetPlaneMake (char pMake[]);

	void GetPlaneModel (char pModel[]);
	void SetPlaneModel (char pModel[]);

	int GetPlaneSeats ();
	void SetPlaneSeats (int NumSeat);

	int GetPlaneRange ();
	void SetPlaneRange (int Distance);

	int GetMinCabinCrew ();
	void SetMinCabinCrew (int MinCrewNum);
};