#pragma once

class Military {
public:
	int reserveCount;
	int mobalizingCount;
	int activeCount;
	int money;

public:
	Military(int troops, int money);
	Military();
	int GetTroopCount() const { return reserveCount + mobalizingCount + activeCount; }
	void Mobalize(int count);
};

class ArmorDivision : public Military {
public:
	ArmorDivision();
	bool Attack(Military& attackedForce);
	bool Attack(Military* attackedForce);
};
