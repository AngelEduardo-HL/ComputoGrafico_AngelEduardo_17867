#pragma once
#include <vector>
#include <map>
#include "glad.h"
#include <iostream>

class Application
{
private:
	

	std::map<std::string, GLuint> ids;

	// Refactorizacion de la Geometria que estaba en Setup
	void SetUpGeometry();
	float time{ 0.0f }; // Variable para controlar el tiempo

public:
	void Setup();
	void Update();
	void Draw();

};