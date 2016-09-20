#include "NGameApplication.h"

#include <functional>
#include <iostream>
#include <UPCFramework\NEnumWindowFlags.h>

NGameApplication::NGameApplication()
{
}

void NGameApplication::InitializeApplication() {
	// Creamos el framework
	mFramework.Initialize("UPC - Desarrollo de Juegos", 
		NGameApplication::WIDTH, NGameApplication::HEIGHT,
		NEnumWindowFlags::Windowed);
	mFramework.OnInput(std::bind(&NGameApplication::OnInput, this, std::placeholders::_1));
}

void NGameApplication::Start() {
	// Inicializar nuesto juego
	InitializeApplication();

	//mFramework.AddCallback(std::bind(&NGameApplication::Test, this));
	mFramework.DoGameLoop(std::bind(&NGameApplication::Update, this, std::placeholders::_1),
		std::bind(&NGameApplication::Draw, this, std::placeholders::_1));
}

void NGameApplication::OnInput(SDL_Event evnt) {
	std::cout << std::to_string(evnt.type);
}

void NGameApplication::Update(float dt) {
	//std::cout << "update: " << std::to_string(dt) << std::endl;
}

void NGameApplication::Draw(float dt) {
	//std::cout << "Draw: " << std::to_string(dt) << std::endl;
}

NGameApplication::~NGameApplication()
{
}
