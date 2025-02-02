#include "../Object/Object.h"

void Object::Update()
{
	if (physics != nullptr) {
		physics->Update((float)TIME.GetDeltaTime());
	}

	renderer->Update((float)TIME.GetDeltaTime());
}
