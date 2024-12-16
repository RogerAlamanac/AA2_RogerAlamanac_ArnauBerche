#pragma once
#include "Transform.h"
#include "Rigidbody.h"
#include "../Renderers/ImageRenderer.h"
#include "../InputManager/TimeManager.h"
#include "../Renderers/AnimatedImageRenderer.h"
class Object {
private:
	bool isPendingDestroy = false;
	

protected:
	Transform* transform;
	Rigidbody* physics;
	Renderer* renderer;
public:
	std::string tag;

	Object()
	{
		//isPendingDestroy = false;
		transform = new Transform();
		physics = new Rigidbody(transform);
	}
	~Object() {
		delete transform;
		delete physics;
		delete renderer;
	}
	virtual void Update();
	inline virtual void Render() {renderer->Render();}
	inline Transform* GetTransform() { return transform; }
	inline Rigidbody* GetRigidBody() { return physics; }
	//inline void SetTransform(Transform* t) { transform = t; }

	//NO FAN RES DE MOMENT
	inline bool IsPendingDestroy() { return isPendingDestroy; }
	inline virtual void Destroy() { isPendingDestroy = true; }
	virtual void OnCollisionEnter(Object* other) {}
};