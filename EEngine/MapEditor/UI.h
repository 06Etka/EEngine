#ifndef UI_CLASS_H
#define UI_CLASS_H

#include "imgui/imgui.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_glfw.h"
#include<GLFW/glfw3.h>

#include<string>
#include<iostream>
#include <filesystem>

namespace fs = std::filesystem;

class UI {
	public:
		UI(GLFWwindow* window);
		~UI();
		
		void draw(int viewportTexture);

	private:
		void newFrame();
		void render();
		void listFiles(const fs::path& directoryPath);
		void drawAssets(const std::string& directoryPath);
};

#endif // !UI_CLASS_H
