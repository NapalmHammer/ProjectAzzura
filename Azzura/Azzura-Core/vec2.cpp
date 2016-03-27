#include "vec2.h"

namespace azzure
{
	Vec2::Vec2()
		:m_X(0), m_Y(0)
	{

	}
	Vec2::Vec2(float x, float y)
	{
		m_X = x, m_Y = y;
	}
	Vec2::~Vec2()
	{

	}
	Vec2 Vec2::twoDToIso(Vec2 &xy)
	{
		Vec2 tempVec;
		tempVec.m_X = (xy.m_X - xy.m_Y);
		tempVec.m_Y = ((xy.m_X + xy.m_Y) / 2);
		return(tempVec);
	}
	Vec2 Vec2::isoToTwoD(Vec2 &xy)
	{
		Vec2 tempVec;
		tempVec.m_X = ((2 * xy.m_Y + xy.m_X) / 2);
		tempVec.m_Y = ((2 * xy.m_Y - xy.m_X) / 2);
		return(tempVec);
	}

	void Vec2::modVec(Vec2 &mod, float x, float y)
	{
		mod.m_X += x;
		mod.m_Y += y;
	}
}