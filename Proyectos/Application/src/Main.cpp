#include "glad.h"
#include "GLFW/glfw3.h"
#include "Application.h"

// Callback que se ejecuta cuando se presiona una tecla
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

int main(void)
{
    GLFWwindow* window;
    Application app;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1024, 768, "Hello Application", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
		return -1;
    }

    glfwSetKeyCallback(window, keyCallback);

	app.Setup();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Poll for and process events */
        glfwPollEvents();
        app.Update();

		//Llama a la funcion para cerrar la ventana con la tecla escape
        

		app.Draw();
        /* Swap front and back buffers */
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}