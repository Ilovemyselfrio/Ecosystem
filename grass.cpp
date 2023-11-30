
#include "grass.h"

string Grass::serialize() const
{
	ostringstream oss;
	oss << "Grass" << " " << this->vitality << " " << this->x << " " << this->y;
	return oss.str();
}

void Grass::print() {
	cout << "草的信息：" << "活力值:" << vitality;
	cout  << "，位置:" << *this << endl;
}

void Grass::move()
{
}

bool Grass::Isdie()
{
	return false;
}
