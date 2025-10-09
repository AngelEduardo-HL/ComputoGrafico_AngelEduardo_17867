#include "Application.h"
#include "ShaderFuncs.h"
#include <iostream>

// Refactorizacion de la Geometria que estaba en Setup
void Application::SetUpGeometry()
{
	//Crear VAO
	GLuint VAO, VBO;
	glGenVertexArrays(1, &VAO);
	ids["triangle"] = VAO;

	glBindVertexArray(VAO);

	//Crear VBO vertices
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO); //Esto aun no manda nada a la GPU

	//Pasar arreglo de vertices a la memoria de la GPU
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(GLfloat) * geometry.size(), //Calculo el tamaño en bytes del arreglo
		&geometry[0],
		GL_STATIC_DRAW); //Mandamos la geometria el Buffer

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0); //(index, size, type, normalized, stride, pointer)
	glEnableVertexAttribArray(0);
}

void Application::Setup()
{
	SetUpGeometry(); // Llamo a la funcion que crea la geometria
	GLuint ShadersID = InitializeProgramFromFiles("Shaders/VertextShader.glsl", "Shaders/FragmentShader.glsl"); //Cargo y compilo los shaders
	ids["program"] = ShadersID; //Guardo el ID del programa de shaders
	//std::cout << "setup()" << std::endl;
}
void Application::Update()
{
	//std::cout << "update()" << std::endl;
}
void Application::Draw()
{
	glUseProgram(ids["program"]); //Uso el programa de shaders

	glBindVertexArray(ids["triangle"]); //Digo que geometria voy a usar

	glDrawArrays(GL_TRIANGLES, 0, 3); //Dibujo la geometria

	//std::cout << "draw()" << std::endl;
}