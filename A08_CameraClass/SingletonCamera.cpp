#include "SingletonCamera.h"


SingletonCamera* SingletonCamera::m_camera = nullptr;

SingletonCamera::SingletonCamera()
{
	m_viewMatrix = glm::lookAt(m_position, m_target, m_up);
	m_projectionMatrix = glm::perspective(45.0f, 1080.0f / 768.0f, 0.01f, 1000.0f);
	m_qRotation = glm::quat(vector3(0.0f));
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
	m_position = glm::normalize(v3Position);
}

void SingletonCamera::SetTarget(vector3 v3Target)
{
	m_target = glm::normalize(v3Target);
}

void SingletonCamera::SetUp(vector3 v3Up)
{
	m_up = glm::normalize(v3Up);
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

	//m_qRotation = glm::rotate(m_qRotation, fIncrement, REAXISZ); // Although this is rotation on X axis
	//m_up = glm::eulerAngles(m_qRotation);
	//m_target = glm::eulerAngles(m_qRotation);

	m_v3PitchYawRoll.x += fIncrement;

	vector3 fwd = glm::normalize(m_target - m_position);
	vector3 right = glm::normalize(glm::cross(fwd, m_up));

	m_qRotation = glm::cross(m_qRotation, glm::angleAxis(m_v3PitchYawRoll.x, right));
	m_up = glm::rotate(m_qRotation, m_up);
	m_target = glm::rotate(m_qRotation, m_target);
}

void SingletonCamera::ChangeRoll(float fIncrement)
{
	//m_pitchYawRoll = glm::rotate(m_pitchYawRoll, fIncrement, REAXISZ);
	//glm::rotate(m_target, m_pitchYawRoll.z, REAXISY);
	//m_up = vector3(0.0f, m_pitchYawRoll.y, 0.0f);
	//m_up = vector3(m_up.x + fIncrement, m_up.y + fIncrement, m_up.z);

	//m_qRotation = glm::rotate(m_qRotation, fIncrement, REAXISY); // Although this is rotation on Z axis
	//m_up = glm::eulerAngles(m_qRotation);

	m_v3PitchYawRoll.z += fIncrement;

	vector3 fwd = glm::normalize(m_target - m_position);
	m_qRotation = glm::cross(m_qRotation, glm::angleAxis(m_v3PitchYawRoll.z, fwd));
	m_up = glm::rotate(m_qRotation, m_up);
	m_target = glm::rotate(m_qRotation, m_target);

}

void SingletonCamera::ChangeYaw(float fIncrement)
{
	//m_pitchYawRoll = glm::rotate(m_pitchYawRoll, fIncrement, REAXISY);
	//glm::rotate(m_target, m_pitchYawRoll.y, REAXISY);
	//m_up = vector3(0.0f, m_pitchYawRoll.y, 0.0f);
	//m_target = glm::rotate(m_target, fIncrement, REAXISY);
	//m_target = vector3(m_target.x + fIncrement, m_target.y, m_target.z + fIncrement);

	//m_qRotation = glm::rotate(m_qRotation, fIncrement, REAXISX); // Although this is rotation on Y axis
	//m_target = glm::eulerAngles(m_qRotation);
	//std::cout << m_target.x << m_target.y << m_target.z << std::endl;

	m_v3PitchYawRoll.y += fIncrement;

	m_qRotation = glm::cross(m_qRotation, glm::angleAxis(m_v3PitchYawRoll.y, m_up));
	m_target = glm::rotate(m_qRotation, m_target);
	//m_target = REAXISZ * m_qRotation + m_position;
}
