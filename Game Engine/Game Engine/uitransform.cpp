#include "uitransform.hpp"



UITransform::UITransform() : UITransform(100.f, 100.f)
{
}

UITransform::UITransform(float w, float h)
	: oWeight(w)
	, oHeight(h)
{
}


UITransform::~UITransform()
{
}

inline float UITransform::getWeight() const
{
	return oWeight;
}

inline float UITransform::getHeight() const
{
	return oHeight;
}

inline float UITransform::getNormalizedWeight() const
{
	return 0.0f;
}

inline float UITransform::getNormalizedHeight() const
{
	return 0.0f;
}

inline const kmu::vec2 & UITransform::getNormalizedMinPoint() const
{
	return getMinPoint() / 100.f;
}

inline const kmu::vec2 & UITransform::getNormalizedMaxPoint() const
{
	return getMaxPoint() / 100.f;
}

inline const kmu::vec2 & UITransform::getMinPoint() const
{
	return kmu::vec2(oPos.x, oPos.y);
}

inline const kmu::vec2 & UITransform::getMaxPoint() const
{
	return kmu::vec2(oPos.x + oWeight, oPos.y + oHeight);
}
