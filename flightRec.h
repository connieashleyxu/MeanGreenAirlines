#include <string>
#include <vector>
#include <ctime>
using namespace std;

class FlightRec
{
private:
	int    FlightID;
	char   PlaneID[40];
	int    numPilots;
	int    numCabinCrews;
	int    pilotID[4];
	int    CabinCrewID[16];
	tm     StartTime;
	tm     EndTime;    
	char   StartAirportCode[40];    
	char   EndAirportCode[40];     
	int    numOfPassenger;
	int    PlaneStatus;        // 1=Active, 2=Completed, 3=Cancelled

public:

	FlightRec ();
	~FlightRec ();

	int GetFlightID ();
	void SetFlightID (int fID);


	void   GetPilotID (int pID[]);
	void   SetPilotID (int pID[]);

	void   GetCabinCrewID (int cID[]);
	void   SetCabinCrewID (int cID[]);

	void  GetPlaneID (char pID[]);
	void  SetPlaneID (char pID[]);

	int GetNumPilot ();
	void SetNumPilot (int NumPilot);

	int GetNumCabinCrew ();
	void SetNumCabinCrew (int NumCrew);

	void GetStartTime (tm& sTime);
	void SetStartTime (tm sTime);

    void GetEndTime (tm& eTime);
	void SetEndTime (tm eTime);

	void GetStartAirportCode (char sCode[]);
	void SetStartAirportCode (char sCode[]);

	void GetEndAirportCode (char eCode[]);
	void SetEndAirportCode (char eCode[]);

    int GetNumPassenger ();
	void SetNumPassenger (int PassengerNum);

    int GetPlaneStatus ();
	void SetPlaneStatus (int Status);
};
