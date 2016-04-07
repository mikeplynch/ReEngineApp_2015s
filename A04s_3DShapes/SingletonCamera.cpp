#include "SingletonCamera.h"


SingletonCamera* SingletonCamera::m_camera = nullptr;

SingletonCamera::SingletonCamera()
{
	m_viewMatrix = glm::lookAt(m_position, m_target, m_up);
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
		return glm::ortho(-384.0f, 384.0f, -540.0f, 540.0f);
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
	m_target.z += fIncrement;
	Update();
}

void SingletonCamera::MoveSideways(float fIncrement)
{
	m_position.x += fIncrement;
	m_target.x += fIncrement;
	Update();
}

void SingletonCamera::MoveVertical(float fIncrement)
{
	m_position.y += fIncrement;
	m_target.y += fIncrement;
	Update();
}

void SingletonCamera::ChangePitch(float fIncrement)
{
	//m_viewMatrix *= glm::mat4_cast(glm::rotate(m_pitchYawRoll, fIncrement, REAXISX));
	m_pitchYawRoll = glm::rotate(m_pitchYawRoll, fIncrement, REAXISX);
	glm::rotate(m_target,m_pitchYawRoll.x,REAXISX);
	//m_up = glm::cross(m_pitchYawRoll, m_target);
	Update();
}

void SingletonCamera::ChangeRoll(float fIncrement)
{
	m_pitchYawRoll = glm::rotate(m_pitchYawRoll, fIncrement, REAXISZ);
	glm::rotate(m_target, m_pitchYawRoll.z, REAXISY);
	//m_up = vector3(0.0f, m_pitchYawRoll.y, 0.0f);
	Update();
}

void SingletonCamera::ChangeYaw(float fIncrement)
{
	m_pitchYawRoll = glm::rotate(m_pitchYawRoll, fIncrement, REAXISY);
	glm::rotate(m_target, m_pitchYawRoll.y, REAXISY);
	//m_up = vector3(0.0f, m_pitchYawRoll.y, 0.0f);
	Update();
}

void SingletonCamera::Update()
{
	m_viewMatrix = glm::lookAt(m_position, m_target, m_up);
}
