#include "Score.h"

void Score::Update()
{
	Object::Update();
	TextObject::SetText("Score: " + std::to_string(currentScore));
}

void Score::Render()
{
	TextObject::Render();
}
