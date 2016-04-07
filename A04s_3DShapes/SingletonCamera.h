#ifndef __SingletonCamera_H_
#define __SingletonCamera_H_

#include "RE\ReEngAppClass.h"

using namespace ReEng;

#include <SFML\Graphics.hpp>

class SingletonCamera
{
public:
	static SingletonCamera* m_camera;

	static SingletonCamera* GetInstance()
	{
		if (m_camera == nullptr)
		{
			m_camera = new SingletonCamera();
		}

		return m_camera;
	}

	static void ReleaseInstance()
	{
		if (m_camera != nullptr)
		{
			delete m_camera;
			m_camera = nullptr;
		}
	}

	matrix4 GetView(void)
	{
		return m_viewMatrix = glm::lookAt(m_position, m_target, m_up);
	} //Should get the View Matrix from your singleton
	matrix4 GetProjection(bool bOrtographic); //Should get the Projection Matrix from your singleton, this function should let me choose between a Perspective or an Orthographic projection depending on the bool argument.
	void SetPosition(vector3 v3Position);//Sets the position of the camera
	void SetTarget(vector3 v3Target);//Sets the target of the camera
	void SetUp(vector3 v3Up);//Sets the up vector of the camera
	void MoveForward(float fIncrement);//Move the camera forward (or backwards) depending on the “view vector”
	void MoveSideways(float fIncrement);//Move the camera based on the “right” vectordepending on the “view vector”
	void MoveVertical(float fIncrement);//Move the camera up or down depending on the “up vector”
	void ChangePitch(float fIncrement);//Orient your camera (meaning the forward and up vectors) changing its angle in x
	void ChangeRoll(float fIncrement);//Orient your camera (meaning the forward and up vectors) changing its angle in z
	void ChangeYaw(float fIncrement);//Orient your camera (meaning the forward and up vectors) changing its angle in y

private:
	SingletonCamera();
	~SingletonCamera() {};

	matrix4 m_viewMatrix = matrix4(1.0f);
	matrix4 m_projectionMatrix = matrix4(1.0f);

	vector3 m_position = vector3(0.0f, 0.0f, 5.0f);
	vector3 m_target = vector3(0.0f, 0.0f, 0.0f);
	vector3 m_up = vector3(0.0f, 1.0f, 0.0f);
	
	glm::quat m_qRotation;
};

#endif //__SingletonCamera_H_