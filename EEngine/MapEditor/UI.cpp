#include"UI.h"

UI::UI(GLFWwindow* window) {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");
}

UI::~UI() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void UI::newFrame() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void UI::render() {
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void UI::draw(int viewportTexture) {
    // ------------------------------------ //
    newFrame();
    // ------------------------------------ //

    // --------------------------------------------------------------------------------------------  //
    static bool dockspaceOpen = true;
    ImGuiWindowFlags windowFlags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
    ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->Pos);
    ImGui::SetNextWindowSize(viewport->Size);
    ImGui::SetNextWindowViewport(viewport->ID);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
    windowFlags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
    windowFlags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
    // --------------------------------------------------------------------------------------------  //

    if (dockspaceOpen && ImGui::Begin("Dockspace", &dockspaceOpen, windowFlags)) {
        ImGui::PopStyleVar(3);

        ImGuiID dockspaceId = ImGui::GetID("MyDockSpace");
        ImGui::DockSpace(dockspaceId, ImVec2(0.0f, 0.0f), ImGuiDockNodeFlags_None);
        // ----------------------------------------------------------------------------- //


        if (ImGui::BeginMenuBar()) {
            if (ImGui::BeginMenu("File")) {
                if (ImGui::MenuItem("New", "Ctrl+N")) {
                }
                if (ImGui::MenuItem("Open", "Ctrl+O")) {
                }
                if (ImGui::MenuItem("Save", "Ctrl+S")) {
                }
                if (ImGui::MenuItem("Exit", "Alt+F4")) {
                }
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Edit")) {
                if (ImGui::MenuItem("Undo", "Ctrl+Z")) {
                }
                if (ImGui::MenuItem("Redo", "Ctrl+Y")) {
                }
                if (ImGui::MenuItem("Editor Settings", "Alt+Enter")) {
                }
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Map")) {
                if (ImGui::MenuItem("Run Map", "F9")) {
                }
                if (ImGui::MenuItem("Map Settings", "Ctrl+Alt+Enter")) {
                }
                ImGui::EndMenu();
            }
            ImGui::EndMenuBar();
        }


        ImGui::Begin("Viewport");
        ImVec2 viewportSize = ImGui::GetContentRegionAvail();
        static GLuint textureId = viewportTexture;
        glBindTexture(GL_TEXTURE_2D, viewportTexture);
        ImGui::Image((void*)(intptr_t)textureId, viewportSize, ImVec2(0, 1), ImVec2(1, 0));
        ImGui::End();

        ImGui::Begin("Scene");
        ImGui::End();

        /*ImGui::Begin("Assets");
        for (unsigned int i = 0; i < 10; i++)
        {
            std::string filename = "Folder " + std::to_string(i);
            ImGui::Image(0, ImVec2(16, 16));
            ImGui::SameLine();
            if (ImGui::Button(filename.c_str(), ImVec2(128, 16))) {
                std::cout << "Button clicked for: " << filename << std::endl;
            }
        }
        
        ImGui::End();*/

        drawAssets("../Engine/assets");

        ImGui::Begin("Properties");
        ImGui::End();

        ImGui::Begin("Actions");
        ImGui::End();

        // ----------------------------------------------------------------------------- //
        ImGui::End();
    }

    // ------------------------------------ //
    render();
    // ------------------------------------ //
}

void UI::listFiles(const fs::path& directoryPath)
{
    for (const auto& entry : fs::directory_iterator(directoryPath))
    {
        const auto& path = entry.path();

        if (fs::is_directory(path))
        {
            // Display folder name as a tree node
            bool node_open = ImGui::TreeNode(path.filename().string().c_str());
            if (node_open)
            {
                // Recursively list contents of subdirectories
                listFiles(path);
                ImGui::TreePop();
            }
        }
        else if (fs::is_regular_file(path))
        {
            // Display file name
            ImGui::Button(path.filename().string().c_str());
        }
    }
}

void UI::drawAssets(const std::string& directoryPath)
{
    ImGui::Begin("Assets");

    fs::path path(directoryPath);

    if (fs::exists(path) && fs::is_directory(path))
    {
        listFiles(path);
    }
    else
    {
        ImGui::Text("Invalid directory or directory does not exist.");
    }

    ImGui::End();
}