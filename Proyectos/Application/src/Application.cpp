#include "Application.h"
#include "ShaderFuncs.h"
#include <iostream>

// Refactorizacion de la Geometria que estaba en Setup
void Application::SetUpGeometry()
{
	//Arreglo de vertices y colores del cuadrado
	std::vector<float> geometry
	{
		//X,    Y,    Z,    W
		//Cuadrado
		-1.0f, -1.0f, 0.0f, 1.0f, //Vertice 1
		-1.0f,  1.0f, 0.0f, 1.0f, //Vertice 2
		 1.0f, -1.0f, 0.0f, 1.0f, //Vertice 3
		 1.0f,  1.0f, 0.0f, 1.0f, //Vertice 4


		1.0f, 0.0f, 0.0f, 1.0f,   //Color Rojo Vertice 1
		0.0f, 1.0f, 0.0f, 1.0f,   //Color Verde Vertice 2
		0.0f, 0.0f, 1.0f, 1.0f,    //Color Azul Vertice 3
		1.0f, 0.0f, 0.0f, 1.0f    //Color
	};

	//Crear VAO
	GLuint VAO, VBO;
	glGenVertexArrays(1, &VAO);
	ids["cuadrado"] = VAO;

	glBindVertexArray(VAO);

	//Crear VBO vertices
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO); //Esto aun no manda nada a la GPU

	//Pasar arreglo de vertices a la memoria de la GPU
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(GLfloat) * geometry.size(), //Calculo el tamaño en bytes del arreglo
		&geometry[0],
		GL_STATIC_DRAW); //Mandamos la geometria el Buffer

	//Vertices
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0); //(index, size, type, normalized, stride, pointer)
	glEnableVertexAttribArray(0);

	//Colores
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (const void*)(16*sizeof(float))); //(index, size, type, normalized, stride, pointer)
	glEnableVertexAttribArray(1);
}

void Application::Setup()
{
	SetUpGeometry(); // Llamo a la funcion que crea la geometria
	GLuint ShadersID = InitializeProgramFromFiles("Shaders/VertextShader.glsl", "Shaders/FragmentShader.glsl"); //Cargo y compilo los shaders
	ids["program"] = ShadersID; //Guardo el ID del programa de shaders
	ids["time"] = glGetUniformLocation(ids["program"], "time"); //Obtengo la localizacion de la variable time en el shader
	//std::cout << "setup()" << std::endl;
}
void Application::Update()
{
	//std::cout << "update()" << std::endl;
	time += 0.001f;
}
void Application::Draw()
{
	glUseProgram(ids["program"]); //Uso el programa de shaders

	glBindVertexArray(ids["cuadrado"]); //Digo que geometria voy a usar

	glUniform1f(ids["time"], time); //Paso el valor de time al shader

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4); //Dibujo la geometria 

	//std::cout << "draw()" << std::endl;
}