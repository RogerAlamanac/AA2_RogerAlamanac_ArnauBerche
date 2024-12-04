#pragma once
#include "Transform.h"
#include "Rigidbody.h"
#include "ImageRenderer.h"
#include "TimeManager.h"
class Object {
private:
	bool isPendingDestroy = false;
	ImageRenderer* renderer;

protected:
	Transform* transform;
	Rigidbody* physics;
public:
	Object(std::string texturePath, Vector2 sourceOffset, Vector2 sourceSize)
	{
		transform = new Transform();
		physics = new Rigidbody(transform);
		physics->AddCollider(new AABB(sourceOffset, sourceSize * 0.2f));
		renderer = new ImageRenderer(transform, texturePath, sourceOffset, sourceSize);

		isPendingDestroy = false;
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