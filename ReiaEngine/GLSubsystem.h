#pragma once
#include "GraphicsSubsystem.h"
#include "cLogger.h"
#include "OpenGL/glut.h"
#include <thread>

class GLSubsystem :
    public GraphicsSubsystem
{
public:
    int Init(int argc, char** argv) {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(ScreenResolution.X, ScreenResolution.Y);
        glutCreateWindow("ReiaEngine");
        // glutDisplayFunc(Update); // how am I supposed to do that lol?
        glutDisplayFunc([] {
            INFO_LOG("glutDisplayFunc called!");
            glClear(GL_COLOR_BUFFER_BIT);
            glColor3f(1.0, 0.0, 0.0);

            glBegin(GL_POINTS);
            glVertex2f(10.0, 10.0);
            glVertex2f(150.0, 80.0);
            glVertex2f(100.0, 20.0);
            glVertex2f(200.0, 100.0);
            glEnd();
            glFlush();
        });

        glColor3f(1.0, 0.0, 0.0);
        glPointSize(5.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0.0, 499.0, 0.0, 499.0);

        return 0;
    }

    void Start() {
        if (glUpdateThread == nullptr) {
            glUpdateThread = new std::thread([&] { glutMainLoop(); });
        }
    }

    void JoinThread() {
        if (glUpdateThread != nullptr) glUpdateThread->join();
    }

    void SetScreenResolution(VectorI2 NewResolution, bool FullScreen = false, bool WindowedMode = true) {
        GraphicsSubsystem::SetScreenResolution(NewResolution, FullScreen, WindowedMode);

        if (WindowedMode) {
            glutPositionWindow(0, 0);
            glutReshapeWindow(NewResolution.X, NewResolution.Y);
        }
        else {
            char gameModeString[16] = { 0 };
            snprintf(gameModeString, 15, "%ix%i:32", NewResolution.X, NewResolution.Y);

            glutGameModeString(gameModeString);

            INFO_LOG(gameModeString);

            if (glutGameModeGet(GLUT_GAME_MODE_ACTIVE) == true && !FullScreen) { // if the game is in fullscreen and we want it to stop being fullscreen
                glutLeaveGameMode();
            }
            else if (glutGameModeGet(GLUT_GAME_MODE_ACTIVE) == false && FullScreen) { // if the game isn't fullscreen and we want it to be fullscreen
                glutEnterGameMode();
            }
        }
        
    };

    void SetWindowTitle(char* NewTitle) {
        glutSetWindowTitle(NewTitle);
    }
protected:
    std::thread *glUpdateThread = nullptr;
};

