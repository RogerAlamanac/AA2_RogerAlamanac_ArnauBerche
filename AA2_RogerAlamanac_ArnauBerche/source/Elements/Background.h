#pragma once
#include "../Object/Object.h"
class Background : public Object
{
public:
	Background();
	~Background();
	void Update() override;
};

