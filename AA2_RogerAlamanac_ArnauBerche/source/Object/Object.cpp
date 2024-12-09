#include "../Object/Object.h"

void Object::Update()
{
	if (physics != nullptr) {
		physics->Update(TIME.GetDeltaTime());
	}

	renderer->Update(TIME.GetDeltaTime());
}
