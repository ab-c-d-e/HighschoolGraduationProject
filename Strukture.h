#pragma once


struct Deo
{
	int tip;
	int xPos, yPos;
	int staza;
	int preostalo;

public:
	Deo(int tip, int xPos, int yPos, int staza, int preostalo = 10)
	{
		this->tip = tip;
		this->xPos = xPos;
		this->yPos = yPos;
		this->staza = staza;
		this->preostalo = preostalo;

	}



};

