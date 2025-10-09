#pragma once
#include <vector>
#include <map>
#include "glad.h"
#include <iostream>

class Application
{
private:
	std::vector<float> geometry
	{
		//X, Y, Z, W
		-1.0f,  1.0f, 0.0f, 1.0f, //Vertice 1
		-1.0f, -1.0f, 0.0f, 1.0f, //Vertice 2
		 1.0f, -1.0f, 0.0f, 1.0f, //Vertice 3
	};

	std::map<std::string, GLuint> ids;

	// Refactorizacion de la Geometria que estaba en Setup
	void SetUpGeometry();

public:
	void Setup();
	void Update();
	void Draw();
};