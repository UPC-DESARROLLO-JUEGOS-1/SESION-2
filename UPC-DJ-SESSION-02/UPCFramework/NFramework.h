#pragma once

#include <functional>
#include "NWindow.h"

enum NEnumFrameworkState {
	Running,
	Exit
};

class NFramework
{
public:
	NFramework();
	~NFramework();

	void Initialize(std::string windowName, int screenWidth, int screenHeight, 
		unsigned int windowFlags);

	void SetFrameworkState(NEnumFrameworkState state);
	void OnInput(std::function<void(SDL_Event)> onInput) { mOnInput = onInput; }
	
	void DoGameLoop(std::function<void(float)> onUpdate, std::function<void(float)> onDraw);
	void Update(float dt);
	void Draw(float dt);

private:
	int mScreenWidth;
	int mScreenHeight;
	NEnumFrameworkState mFrameworkState;
	NWindow mWindow;

	std::function<void(SDL_Event)> mOnInput = NULL;
	std::function<void(float)> mOnUpdate = NULL;
	std::function<void(float)> mOnDraw = NULL;

	float ComputeDeltaTime();
	void OnListenInputsFromWindow(SDL_Event evnt);
};

