#include "CameraClass.h"

matrix4 CameraClass::GetView(void)
{
	return matrix4();
}

matrix4 CameraClass::GetProjection(bool bOrtographic)
{
	return matrix4();
}

void CameraClass::SetPosition(vector3 v3Position)
{
}

void CameraClass::SetTarget(vector3 v3Target)
{
}

void CameraClass::SetUp(vector3 v3Up)
{
}

void CameraClass::MoveForward(float fIncrement)
{
}

void CameraClass::MoveSideways(float fIncrement)
{
}

void CameraClass::MoveVertical(float fIncrement)
{
}

void CameraClass::ChangePitch(float fIncrement)
{
}

void CameraClass::ChangeRoll(float fIncrement)
{
}

void CameraClass::ChangeYaw(float fIncrement)
{
}
