#include <iostream>

#include"Window.h"
#include"UI.h"
#include"Shader.h"
#include"Model.h"

int SCR_WIDTH = 800;
int SCR_HEIGHT = 600;

int main()
{
    Window window(SCR_WIDTH, SCR_HEIGHT, "Map Editor");

    UI ui(window.getWindow());

    unsigned int framebuffer;
    glGenFramebuffers(1, &framebuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);

    unsigned int viewportTexture;
    glGenTextures(1, &viewportTexture);
    glBindTexture(GL_TEXTURE_2D, viewportTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, SCR_WIDTH, SCR_HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);

    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, viewportTexture, 0);

    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
        std::cerr << "Framebuffer is not complete!" << std::endl;
        return -1;
    }

    glEnable(GL_DEPTH_TEST);

    Shader defaultShader("default.vert", "default.frag");

    Model box("../Engine/assets/models/box.obj");

    while (!window.shouldClose())
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);

        defaultShader.use();

        defaultShader.setVec3("viewPos", glm::vec3(0.0f, 0.0f, 0.0f));

        glm::mat4 projection = glm::perspective(75.0f, (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        glm::mat4 view = glm::mat4(1.0f);
        defaultShader.setMat4("projection", projection);
        defaultShader.setMat4("view", view);


        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, -30.0f));
        model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
        defaultShader.setMat4("model", model);
        box.draw(defaultShader);

        glBindFramebuffer(GL_FRAMEBUFFER, 0);

        ui.draw(viewportTexture);
        window.update();
    }

    glDeleteTextures(1, &viewportTexture);
    glDeleteFramebuffers(1, &framebuffer);
    return 0;
}
