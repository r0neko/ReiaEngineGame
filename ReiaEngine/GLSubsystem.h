#pragma once
#include "GraphicsSubsystem.h"
#include "cLogger.h"
#include "OpenGL/glad/glad.h"
#include "OpenGL/glfw3.h"
#include "Windows.h"
#include <thread>

// very useful resource! https://learnopengl.com/

class GLSubsystem :
    public GraphicsSubsystem
{
public:
    virtual int Init(int argc, char** argv) {
        DEBUG_LOG("GLSubsystem::Init - Compiled against GLFW %i.%i.%i\n", GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION);

        if (!glfwInit()) {
            ERROR_LOG("failed to glfwInit()\n");
            return -1;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_RESIZABLE, 0);

        return 0;
    }

    virtual void Start() {
        // create window
        DEBUG_LOG("GLSubsystem::Start\n");
        window = glfwCreateWindow(640, 480, "ReiaEngine", NULL, NULL);
        if (!window)
        {
            ERROR_LOG("failed to create window!\n");
            glfwTerminate();
        }
        else {
            INFO_LOG("created window\n");

            glfwMakeContextCurrent(window);

            if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
                ERROR_LOG("failed to init GLAD!\n");
            }
            else {
                INFO_LOG("GLAD init OK!\n");
            }

            if (glThreadHandle == NULL) {
                WARN_LOG("GLSubsystem::glThreadHandle = NULL!\n");
                glThreadHandle = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE) glRenderLoop, (void*) this, 0, nullptr);
            }
        }
    }

    void Stop() {
        glfwDestroyWindow(window);

        if (glThreadHandle != NULL) {
            WaitForSingleObject(glThreadHandle, 10);
            TerminateThread(glThreadHandle, 0);
            glThreadHandle = NULL;
        }

        glfwTerminate();
    }

    virtual void SetScreenResolution(VectorI2 NewResolution, bool FullScreen = false, bool WindowedMode = true) {
        GraphicsSubsystem::SetScreenResolution(NewResolution, FullScreen, WindowedMode);

        // get primary monitor info
        GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* mode = glfwGetVideoMode(primaryMonitor);

        INFO_LOG("new resolution: %ix%i\n", NewResolution.X, NewResolution.Y);
        
        if (FullScreen && WindowedMode) {
            INFO_LOG("windowed full-screen mode - %ix%i:%ihz\n", mode->width, mode->height, mode->refreshRate);
            glfwSetWindowMonitor(window, nullptr, 0, 0, mode->width, mode->height, mode->refreshRate);
        }
        else if (FullScreen) {
            INFO_LOG("full-screen mode - %ix%i:%ihz\n", NewResolution.X, NewResolution.Y, mode->refreshRate);
            glfwSetWindowMonitor(window, primaryMonitor, 0, 0, NewResolution.X, NewResolution.Y, mode->refreshRate);
        }
        else {
            INFO_LOG("windowed mode - %ix%i\n", NewResolution.X, NewResolution.Y);
            glfwSetWindowSize(window, NewResolution.X, NewResolution.Y);
        }
    };

    virtual void SetWindowTitle(char* NewTitle) {
        glfwSetWindowTitle(window, NewTitle);
    }

    virtual void ProcessFrame() {
        glViewport(0, 0, ScreenResolution.X, ScreenResolution.Y);

        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    virtual bool Available() {
        return !glfwWindowShouldClose(window);
    }
protected:
    static void glRenderLoop(void* params) {
        GLSubsystem *e = (GLSubsystem*) params;

        while (e->Available());
    }

    GLFWwindow* window;

    HANDLE glThreadHandle = NULL;
};

