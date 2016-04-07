#include "SingletonCamera.h"


SingletonCamera* SingletonCamera::m_camera = nullptr;

SingletonCamera::SingletonCamera()
{
	m_viewMatrix = glm::lookAt(m_position, m_target, m_up);
	m_projectionMatrix = glm::perspective(45.0f, 1080.0f / 768.0f, 0.01f, 1000.0f);
	m_pitchYawRoll = glm::quat(vector3(0.0f));
}

matrix4 SingletonCamera::GetView(void)
{
	return m_viewMatrix = glm::lookAt(m_position, m_target, m_up);
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
}

void SingletonCamera::MoveSideways(float fIncrement)
{
	m_position.x += fIncrement;
	m_target.x += fIncrement;
}

void SingletonCamera::MoveVertical(float fIncrement)
{
	m_position.y += fIncrement;
	m_target.y += fIncrement;
}

void SingletonCamera::ChangePitch(float fIncrement)
{
	//m_viewMatrix *= glm::mat4_cast(glm::rotate(m_pitchYawRoll, fIncrement, REAXISX));
	//m_pitchYawRoll = glm::rotate(m_pitchYawRoll, fIncrement, REAXISX);
	//m_target = glm::rotate(m_target,fIncrement,REAXISX);
	////m_up = glm::cross(m_pitchYawRoll, m_target);
	//m_up = glm::rotate(m_up, fIncrement, REAXISX);
	//std::cout << m_up.x << std::endl;
	//m_target = vector3(m_target.x, m_target.y + fIncrement, m_target.z + fIncrement);
	//m_up = vector3(m_up.x, m_up.y + fIncrement, m_up.z + fIncrement);
	m_pitchYawRoll = glm::rotate(m_pitchYawRoll, fIncrement, REAXISZ); // Although this is rotation on X axis
	m_up = glm::eulerAngles(m_pitchYawRoll);
	m_target = glm::eulerAngles(m_pitchYawRoll);
	
}

void SingletonCamera::ChangeRoll(float fIncrement)
{
	//m_pitchYawRoll = glm::rotate(m_pitchYawRoll, fIncrement, REAXISZ);
	//glm::rotate(m_target, m_pitchYawRoll.z, REAXISY);
	//m_up = vector3(0.0f, m_pitchYawRoll.y, 0.0f);
	//m_up = vector3(m_up.x + fIncrement, m_up.y + fIncrement, m_up.z);
	m_pitchYawRoll = glm::rotate(m_pitchYawRoll, fIncrement, REAXISY); // Although this is rotation on Z axis
	m_up = glm::eulerAngles(m_pitchYawRoll);
}

void SingletonCamera::ChangeYaw(float fIncrement)
{
	//m_pitchYawRoll = glm::rotate(m_pitchYawRoll, fIncrement, REAXISY);
	//glm::rotate(m_target, m_pitchYawRoll.y, REAXISY);
	//m_up = vector3(0.0f, m_pitchYawRoll.y, 0.0f);
	//m_target = glm::rotate(m_target, fIncrement, REAXISY);
	//m_target = vector3(m_target.x + fIncrement, m_target.y, m_target.z + fIncrement);
	m_pitchYawRoll = glm::rotate(m_pitchYawRoll, fIncrement, REAXISX); // Although this is rotation on Y axis
	//m_target = glm::cross(m_target, m_pitchYawRoll);
	m_target = glm::eulerAngles(m_pitchYawRoll);
	//std::cout << m_target.x << m_target.y << m_target.z << std::endl;
}
