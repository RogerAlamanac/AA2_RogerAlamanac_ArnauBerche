#pragma once
#include "../Object/TextObject.h"

class Score : public TextObject {
private:
	int currentScore = 0;
public:
	Score(Vector2 pos, int _currentScore) : TextObject("Score: " + std::to_string(currentScore)), currentScore(_currentScore) {
		TextObject::transform->position = pos;
		TextObject::SetText("Score: " + std::to_string(currentScore));
		TextObject::GetTransform()->scale = Vector2(1.5f, 1.5f);
	}
	~Score();
	void Update() override;
	void Render() override;
	inline int GetCurrentScore() { return currentScore; }
};