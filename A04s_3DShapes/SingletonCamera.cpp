#include "SingletonCamera.h"

SingletonCamera* SingletonCamera::m_camera = nullptr;

SingletonCamera::SingletonCamera()
{
	m_viewMatrix = glm::lookAt(m_position, vector3(0.0f), m_up);
	m_projectionMatrix = glm::perspective(45.0f, 1080.0f / 768.0f, 0.01f, 1000.0f);
}

matrix4 SingletonCamera::GetView(void)
{
	return m_viewMatrix;
}

matrix4 SingletonCamera::GetProjection(bool bOrtographic)
{
	if (bOrtographic)
	{
		return glm::ortho(-20.0f, 20.0f, -20.0f, 20.0f);

	}

	return m_projectionMatrix;
}

void SingletonCamera::SetPosition(vector3 v3Position)
{
	m_position = v3Position;
}

void SingletonCamera::SetTarget(vector3 v3Target)
{
	m_target = v3Target;
}

void SingletonCamera::SetUp(vector3 v3Up)
{
	m_up = v3Up;
}

void SingletonCamera::MoveForward(float fIncrement)
{
	m_position.z += fIncrement;
}

void SingletonCamera::MoveSideways(float fIncrement)
{
	m_position.x += fIncrement;
}

void SingletonCamera::MoveVertical(float fIncrement)
{
	m_position.y += fIncrement;
}

void SingletonCamera::ChangePitch(float fIncrement)
{
	//m_viewMatrix *= glm::mat4_cast(glm::rotate(m_pitchYawRoll, fIncrement, REAXISX));
	//Update();
}

void SingletonCamera::ChangeRoll(float fIncrement)
{
	//m_pitchYawRoll = glm::rotate(m_pitchYawRoll, fIncrement, REAXISZ);
	//Update();
}

void SingletonCamera::ChangeYaw(float fIncrement)
{
	//m_pitchYawRoll = glm::rotate(m_pitchYawRoll, fIncrement, REAXISY);
	//Update();
}

void SingletonCamera::Update()
{
	//m_viewMatrix = glm::lookAt(m_position, vector3(m_pitchYawRoll.x, m_pitchYawRoll.y, m_pitchYawRoll.z), m_up);
}
