#include <string>
#include <vector>
using namespace std;

class CrewRec
{
  private:
      //string   CrewName;
	  char     CrewName[40];
      int      CrewID;
	  char     CrewType;
  public:
    CrewRec ();
	~CrewRec ();

	void GetCrewName (char cName[]);
	void SetCrewName (char cName[]);

	int GetCrewID ();
	void SetCrewID (int cId);

	char GetCrewType ();
	void SetCrewType (char cType);
};
