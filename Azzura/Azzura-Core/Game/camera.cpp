#include "camera.h"

namespace azzure
{

	Camera::Camera(float X, float Y)
	{
		m_CamX = X;
		m_CamY = Y;
	}
	Camera::Camera(Vec2 camXY)
	{
		m_CamX = camXY.m_X;
		m_CamY = camXY.m_Y;
	}

	Camera::~Camera()
	{

	}

	void Camera::modXY(float X, float Y)
	{
		m_CamX = m_CamX + X;
		m_CamY = m_CamY + Y;
	}
}