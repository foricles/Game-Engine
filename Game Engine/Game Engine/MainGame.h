#ifndef _MAINGAME_H_
#define _MAINGAME_H_

class MainGame 
{
public:
	virtual void Awake() = 0;
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void FixedUpdate() = 0;
	virtual void LateUpdate() = 0;
};

#endif //_MAINGAME_H_