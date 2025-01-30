
#include <GLFW/glfw3.h>
#include <iostream>
#include"../src/lab2/dda.cpp"
#include "../src/lab2/bresenham.cpp"

void take_input(int*,int*,int*,int*);
void lab1(); 
void draw_histogram();
void draw_line();
void lab2();
void lab3();
void lab4();
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
      


        //lab1();
      //lab2();
      //lab3();
      //lab4();
        


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


void draw_histogram(){
    int  frequencies[8] = {50,40,60,70,90,80,30,50};

    int barWidth = 40;
    int startX = 50;    
    int gap = 10;       

    for (size_t i = 0; i < 8; ++i) {
        int x1 = startX + i * (barWidth + gap);
        int x2 = x1 + barWidth;
        int y1 = 50;                
        int y2 = 50 + frequencies[i];

        dda_draw_line(new Point2D{50,50}, new Point2D{450,50});
        dda_draw_line(new Point2D{50,50}, new Point2D{50,450}); 
       
        if (0) {
            dda_draw_line(new Point2D{x1,y1},new Point2D{x1, y2}); // Left vertical line
            dda_draw_line(new Point2D{x1, y2}, new Point2D{x2, y2} ); // Top horizontal line
            dda_draw_line(new Point2D{x2, y2}, new Point2D{x2, y1} ); // Right vertical line
        } else {
            bresenham_draw_line(new Point2D{x1, y1} , new Point2D{x1, y2} ); // Left vertical line
            bresenham_draw_line(new Point2D{x1, y2} , new Point2D{x2, y2} ); // Top horizontal line
            bresenham_draw_line(new Point2D{x2, y2} , new Point2D{x2, y1} ); // Right vertical line
        }
    }
}

void draw_line(){
    
    int x1,y1,x2,y2;
    take_input(&x1,&y1,&x2,&y2);
    
    std::cout<<"Select the algorithm to draw line"<<std::endl;
    std::cout<<"1. DDA Algorithm"<<std::endl;
    std::cout<<"2. Bresenham Algorithm"<<std::endl;
    
    int option;

    std::cin>>option;

    if(option==1) dda_draw_line(new Point2D{x1,y1}, new Point2D{x2,y2});
    
    else if(option==2) bresenham_draw_line(new Point2D{x1,y1}, new Point2D{x2,y2});

    else draw_line();
    return ;

}

void take_input(int *x1, int *y1,  int *x2, int *y2){

        std::cout<<"Enter the value for x1"<<std::endl;
        std::cin>>(*x1);

        std::cout<<"Enter the value for y1"<<std::endl;
        std::cin>>*y1;

        std::cout<<"Enter the value for x2"<<std::endl;
        std::cin>>*x2;
        
        std::cout<<"Thner the value for y2"<<std::endl;
        std::cin>>*y2;
}


void lab2(){
    int option;

    std::cout<<"Select a Task TO DO"<<std::endl;
    std::cout<<"1. Draw Line"<<std::endl;
    std::cout<<"2. Draw Histogram"<<std::endl;
    
    std::cin>>option;

    if(option==1) draw_line();
    else if(option==2)draw_histogram();
    else lab1();
    return ;
}

void lab3(){

}
