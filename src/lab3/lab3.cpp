
#include <GLFW/glfw3.h>
#include <iostream>
#include "../../src/lab3/midpoint_alg.cpp"
// Callback to adjust the viewport when the window is resized
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);  // Adjust the viewport to match the window size
}

int main() {    
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Set GLFW context and window properties
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);  // OpenGL version 3.x
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE); // Use compatibility profile for fixed pipeline

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(800, 600, "Simple Point in OpenGL", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Set callback for window resize
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Set up the projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 800.0, 0.0, 600.0, -1.0, 1.0);  // Map coordinates to the window dimensions
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
 
 
    // Main render loop

    while (!glfwWindowShouldClose(window)) {
        // Input handling (optional)
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }

        // Rendering commands
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);  // Set the background color
        glClear(GL_COLOR_BUFFER_BIT);         // Clear the screen

        // Draw a point
        glColor3f(1.0f, 0.0f, 0.0f);          // Set the point color to red

        //plot_circle_point(new Point2D{30,40}, new Point2D{200,200});
        draw_midpoint_circle(100,new Point2D{200,200});
        draw_midpoint_ellipse(200,100,new Point2D{200,200});
        glEnd();

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    // Clean up and exit
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}


