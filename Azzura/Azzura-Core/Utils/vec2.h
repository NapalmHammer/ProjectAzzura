//#pragma once
#ifndef VEC2_H
#define VEC2_H


namespace azzure
{
	class Vec2
	{
	public:
		Vec2();
		Vec2(float x, float y);
		~Vec2();
		static Vec2 twoDToIso(Vec2 &xy);
		static Vec2 isoToTwoD(Vec2 &xy);
		static void modVec(Vec2 &mod, float x, float y);
		float m_X;
		float m_Y;
	};
}
#endif // !VEC2_H