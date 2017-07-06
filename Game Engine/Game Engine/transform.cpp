#include "transform.h"



Transform::Transform()
	: oPos(0, 0, 0)
	, oScl(1, 1, 1)
	, oRot(0, 0, 0, 1)
{
}


Transform::~Transform()
{
}

kmu::mat4 Transform::transMatrix()
{
	kmu::mat4 trm(kmu::mat4::Translation(oPos[0], oPos[1], oPos[2]));
	kmu::mat4 slm(kmu::mat4::Scaling(oScl[0], oScl[1], oScl[2]));
	kmu::mat4 rtm(kmu::mat4::Rotation(oRot));
	return trm*(rtm*slm);
}
