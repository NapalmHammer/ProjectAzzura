#pragma once
#include "../Utils/vec2.h"


namespace azzure
{
	class Camera
	{
	public:
		float m_CamX;
		float m_CamY;

		Camera(float X, float Y);
		Camera(Vec2 camXY);
		~Camera();

		void modXY(float X, float Y);


	};

}