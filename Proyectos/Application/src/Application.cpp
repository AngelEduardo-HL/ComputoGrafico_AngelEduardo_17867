#include "Application.h"
#include <iostream>

void Application::Setup()
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

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
}
void Application::Update()
{
	std::cout << "update()" << std::endl;
}
void Application::Draw()
{
	std::cout << "draw()" << std::endl;
}