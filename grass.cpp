
#include "grass.h"

string Grass::serialize() const
{
	ostringstream oss;
	oss << "Grass" << " " << this->vitality << " " << this->x << " " << this->y;
	return oss.str();
}

void Grass::print() {
	
}

void Grass::move()
{
}

bool Grass::Isdie()
{
	return false;
}
