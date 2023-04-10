#pragma once

class Military {
public:
	int reserveCount;
	int mobalizingCount;
	int activeCount;
	int money;

public:
	//these are the 2 overloads for the constructor
	Military(int troops, int money);
	Military();

	// define the function return as const because it does not
	// actually modify any variable of the class, only returns values
	int GetTroopCount() const { return reserveCount + mobalizingCount + activeCount; }
	
	// functions are declared in, but defined in a cpp file
	void Mobalize(int count);
};

// this class inherites all the functions and vars of the Military
// class, except the constructor
class ArmorDivision : public Military {
public:
	//constructor for this subclass
	ArmorDivision();

	//add subclass specific functons, and overloads for references and pointers
	bool Attack(Military& attackedForce);
	bool Attack(Military* attackedForce);
};
