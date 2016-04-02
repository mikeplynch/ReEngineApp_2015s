#ifndef __CAMERACLASS_H_
#define __CAMERACLASS_H_

#include "RE\ReEngAppClass.h"

using namespace ReEng;
#include <SFML\Graphics.hpp>

class CameraClass : public ReEngAppClass 
{
public:
	typedef ReEngAppClass super;

	static CameraClass& getInstance()
	{
		static CameraClass instance;

		return instance;
	}

	~CameraClass() {};
	CameraClass(CameraClass const&) = delete;
	void operator=(CameraClass const&) = delete;
private:
	CameraClass() {};

	CameraClass(CameraClass const&);
	void operator=(const CameraClass& other);

	matrix4 GetView(void); //Should get the View Matrix from your singleton
	matrix4 GetProjection(bool bOrtographic); //Should get the Projection Matrix from your singleton, this function should let me choose between a Perspective or an Orthographic projection depending on the bool argument.
	void SetPosition(vector3 v3Position);//Sets the position of the camera
	void SetTarget(vector3 v3Target);//Sets the target of the camera
	void SetUp(vector3 v3Up);//Sets the up vector of the camera
	void MoveForward(float fIncrement);//Move the camera forward (or backwards) depending on the �view vector�
	void MoveSideways(float fIncrement);//Move the camera based on the �right� vectordepending on the �view vector�
	void MoveVertical(float fIncrement);//Move the camera up or down depending on the �up vector�
	void ChangePitch(float fIncrement);//Orient your camera (meaning the forward and up vectors) changing its angle in x
	void ChangeRoll(float fIncrement);//Orient your camera (meaning the forward and up vectors) changing its angle in z
	void ChangeYaw(float fIncrement);//Orient your camera (meaning the forward and up vectors) changing its angle in y

};
#endif //__CAMERACLASS_H_