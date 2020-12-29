#include "flightRec.h"

typedef enum FLIGHT_STATUS
{
	ACTIVE = 1,
	COMPLETE,
	CALCEL
} Flight_Status;

//////////////////////////////////////////////////

class Flight
{
public:
	Flight ();
	~Flight();

	vector<FlightRec> FlightList;

	int  PilotIDs[40];
	int  CabinCrewIDs[40];

	int AddFlight (int fID, char pID[], int numPilot, int numCabinCrew, tm sTime, tm eTime, char sAirCode[], char eAirCode[],  int numPassenger, int pStatus);
	int EditFlight (int fID, char pID[], int numPilot, int numCabinCrew, tm sTime, tm eTime, char sAirCode[], char eAirCode[],  int numPassenger, int pStatus);
	void DelFlight (int fID);
	int SearchFlight (int fID);
	void PrintAFlight (int fID);
	void PrintAllFlight ();

	void PrintAssignmentScheduleforPlane (char pID[]);
	void PrintAssignmentScheduleforCrew (int cID);
	void DeleteCancel_or_Complete_flight ();
	void GetFlightRecFile ();
	void UpdateFlightRec ();
	void PrintfCrewList();
	void PrintFlightOnStatus (int fStatus);
	void UpdateFightActiveToCompletedStatus ();
	int  IsTimeConflictOnPlane (char pID[], tm begTime, tm endTime);
	int  IsTimeConflictOnCrewMember (int nCabinCrew, int nPilot, tm begTime, tm endTime);
};