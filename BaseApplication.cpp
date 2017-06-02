
#include "stdafx.h" // Precompiled

#include <OgreCamera.h>
#include <OgreEntity.h>
#include <OgreLogManager.h>
#include <OgreRoot.h>
#include <OgreViewport.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreConfigFile.h>

#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISMouse.h>

#include "ImguiManager.h"

#ifdef _DEBUG
    static const std::string mPluginsCfg = "plugins_d.cfg";
#else
    static const std::string mPluginsCfg = "plugins.cfg";
#endif

struct GuiState
{
    bool test_window_visible;
    bool style_editor_visible;
};

class DemoApp: public Ogre::FrameListener, public OIS::KeyListener, public OIS::MouseListener,  public Ogre::WindowEventListener
{
public:
    void RoR_SetGuiStyle()
    {
// Exported colors

ImGuiStyle& style = ImGui::GetStyle();
style.Colors[ImGuiCol_Text]                  = ImVec4(0.90f, 0.90f, 0.90f, 1.00f);
style.Colors[ImGuiCol_TextDisabled]          = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
style.Colors[ImGuiCol_WindowBg]              = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
style.Colors[ImGuiCol_ChildWindowBg]         = ImVec4(0.00f, 0.00f, 0.00f, 0.99f);
style.Colors[ImGuiCol_PopupBg]               = ImVec4(0.05f, 0.05f, 0.10f, 1.00f);
style.Colors[ImGuiCol_Border]                = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
style.Colors[ImGuiCol_BorderShadow]          = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
style.Colors[ImGuiCol_FrameBg]               = ImVec4(0.44f, 0.51f, 0.52f, 1.00f);
style.Colors[ImGuiCol_FrameBgHovered]        = ImVec4(0.90f, 0.80f, 0.80f, 0.99f);
style.Colors[ImGuiCol_FrameBgActive]         = ImVec4(0.90f, 0.65f, 0.65f, 0.98f);
style.Colors[ImGuiCol_TitleBg]               = ImVec4(0.27f, 0.27f, 0.54f, 1.00f);
style.Colors[ImGuiCol_TitleBgCollapsed]      = ImVec4(0.40f, 0.40f, 0.80f, 1.00f);
style.Colors[ImGuiCol_TitleBgActive]         = ImVec4(0.32f, 0.32f, 0.63f, 1.00f);
style.Colors[ImGuiCol_MenuBarBg]             = ImVec4(0.40f, 0.40f, 0.55f, 1.00f);
style.Colors[ImGuiCol_ScrollbarBg]           = ImVec4(0.20f, 0.25f, 0.30f, 0.99f);
style.Colors[ImGuiCol_ScrollbarGrab]         = ImVec4(0.40f, 0.40f, 0.80f, 1.00f);
style.Colors[ImGuiCol_ScrollbarGrabHovered]  = ImVec4(0.40f, 0.40f, 0.80f, 0.99f);
style.Colors[ImGuiCol_ScrollbarGrabActive]   = ImVec4(0.80f, 0.50f, 0.50f, 0.99f);
style.Colors[ImGuiCol_ComboBg]               = ImVec4(0.20f, 0.20f, 0.20f, 0.99f);
style.Colors[ImGuiCol_CheckMark]             = ImVec4(0.90f, 0.90f, 0.90f, 1.00f);
style.Colors[ImGuiCol_SliderGrab]            = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
style.Colors[ImGuiCol_SliderGrabActive]      = ImVec4(0.80f, 0.50f, 0.50f, 1.00f);
style.Colors[ImGuiCol_Button]                = ImVec4(0.57f, 0.27f, 0.04f, 1.00f);
style.Colors[ImGuiCol_ButtonHovered]         = ImVec4(0.89f, 0.41f, 0.05f, 0.98f);
style.Colors[ImGuiCol_ButtonActive]          = ImVec4(1.00f, 0.69f, 0.27f, 1.00f);
style.Colors[ImGuiCol_Header]                = ImVec4(0.40f, 0.40f, 0.90f, 0.99f);
style.Colors[ImGuiCol_HeaderHovered]         = ImVec4(0.45f, 0.45f, 0.90f, 0.98f);
style.Colors[ImGuiCol_HeaderActive]          = ImVec4(0.53f, 0.53f, 0.87f, 0.97f);
style.Colors[ImGuiCol_Column]                = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
style.Colors[ImGuiCol_ColumnHovered]         = ImVec4(0.70f, 0.60f, 0.60f, 1.00f);
style.Colors[ImGuiCol_ColumnActive]          = ImVec4(0.90f, 0.70f, 0.70f, 1.00f);
style.Colors[ImGuiCol_ResizeGrip]            = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
style.Colors[ImGuiCol_ResizeGripHovered]     = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
style.Colors[ImGuiCol_ResizeGripActive]      = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
style.Colors[ImGuiCol_CloseButton]           = ImVec4(0.50f, 0.50f, 0.90f, 1.00f);
style.Colors[ImGuiCol_CloseButtonHovered]    = ImVec4(0.70f, 0.70f, 0.90f, 1.00f);
style.Colors[ImGuiCol_CloseButtonActive]     = ImVec4(0.70f, 0.70f, 0.70f, 1.00f);
style.Colors[ImGuiCol_PlotLines]             = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
style.Colors[ImGuiCol_PlotLinesHovered]      = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
style.Colors[ImGuiCol_PlotHistogram]         = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
style.Colors[ImGuiCol_PlotHistogramHovered]  = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
style.Colors[ImGuiCol_TextSelectedBg]        = ImVec4(0.00f, 0.00f, 1.00f, 1.00f);
style.Colors[ImGuiCol_ModalWindowDarkening]  = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);

        // Other styles
        style.WindowPadding      = ImVec2(10.f, 10.f);
        style.FrameRounding      = 2.f;
        style.WindowRounding     = 4.f;
        style.WindowTitleAlign   = ImVec2(0.5f, 0.5f);
        style.ItemSpacing        = ImVec2(5.f, 5.f);


    }

    void RoR_DrawMainMenu()
    {
        int flags = ImGuiWindowFlags_NoCollapse;
        ImGui::SetNextWindowPosCenter();
        if (ImGui::Begin("Main menu", nullptr, static_cast<ImGuiWindowFlags_>(flags)))
        {
            ImGui::Button("Single player");
            ImGui::Button("Multi player");
            ImGui::Separator();
            ImGui::Button("Settings");
            ImGui::Button("Exit game");

            ImGui::End();
        }

    }

    void DrawGui()
    {
        if (ImGui::BeginMainMenuBar())
        {
            ImGui::Checkbox("Test window", &m_gui_state.test_window_visible);
            ImGui::SameLine();
            ImGui::Checkbox("Style editor", &m_gui_state.style_editor_visible);

            ImGui::EndMainMenuBar();
        }

        if (m_gui_state.test_window_visible)
        {
            ImGui::ShowTestWindow(&m_gui_state.test_window_visible);
        }

        if (m_gui_state.style_editor_visible)
        {
            ImGui::ShowStyleEditor();
        }

        // Test main menu for ROR
        this->RoR_DrawMainMenu();
    }

    void Go()
    {
        memset(&m_gui_state, 0, sizeof(GuiState));

        mRoot = new Ogre::Root(mPluginsCfg);

        // Show the configuration dialog and initialise the system.
        // NOTE: If you have valid file 'ogre.cfg', you can use `root.restoreConfig()` instead.
        if(!mRoot->showConfigDialog())
        {
            // User abort
            delete mRoot;
            return;
        }

        const bool create_window = true; // Let's be descriptive :)
        const char* window_name = "OGRE/ImGui demo app";
        mWindow = mRoot->initialise(create_window, window_name);

        mSceneMgr = mRoot->createSceneManager(Ogre::ST_GENERIC);
        mCamera = mSceneMgr->createCamera("PlayerCam");

        // Create one viewport, entire window
        Ogre::Viewport* vp = mWindow->addViewport(mCamera);
        vp->setBackgroundColour(Ogre::ColourValue(0,0,0));

        // Alter the camera aspect ratio to match the viewport
        mCamera->setAspectRatio(Ogre::Real(vp->getActualWidth()) / Ogre::Real(vp->getActualHeight()));

        Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);
        Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

        mSceneMgr->setAmbientLight(Ogre::ColourValue(.7f, .7f, .7f));
        mCamera->getViewport()->setBackgroundColour(Ogre::ColourValue(0.f, 0.2f, 0.1f)); // Dark green

        // OIS setup
        OIS::ParamList pl;

        size_t windowHnd = 0;
        std::ostringstream windowHndStr;
        mWindow->getCustomAttribute("WINDOW", &windowHnd);
        windowHndStr << windowHnd;
        pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));
#if OGRE_PLATFORM == OGRE_PLATFORM_LINUX
        pl.insert(OIS::ParamList::value_type("x11_mouse_hide", "false"));
        pl.insert(OIS::ParamList::value_type("XAutoRepeatOn", "false"));
        pl.insert(OIS::ParamList::value_type("x11_mouse_grab", "false"));
#else
        pl.insert(OIS::ParamList::value_type("w32_mouse", "DISCL_FOREGROUND"));
        pl.insert(OIS::ParamList::value_type("w32_mouse", "DISCL_NONEXCLUSIVE"));
#endif
        mInputManager = OIS::InputManager::createInputSystem(pl);

        mKeyboard = static_cast<OIS::Keyboard*>(mInputManager->createInputObject(OIS::OISKeyboard, true));
        mMouse = static_cast<OIS::Mouse*>(mInputManager->createInputObject(OIS::OISMouse, true));

        // Set initial mouse clipping size
        this->windowResized(mWindow);

        // Register as a Window listener
        Ogre::WindowEventUtilities::addWindowEventListener(mWindow, this);

        // === Create IMGUI ====
        Ogre::ImguiManager::createSingleton();
        Ogre::ImguiManager::getSingleton().init(mSceneMgr, mKeyboard, mMouse); // OIS mouse + keyboard

        this->RoR_SetGuiStyle();

        mRoot->addFrameListener(this);

        mMouse->setEventCallback(this);
        mKeyboard->setEventCallback(this);

        mRoot->startRendering();

        this->Shutdown();
    }

private:
    virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt) override
    {
        return (!mWindow->isClosed() && (!mShutDown)); // False means "exit the application"
    }

    virtual bool frameStarted(const Ogre::FrameEvent& evt) override
    {
        // Need to capture/update each device
        mKeyboard->capture();
        mMouse->capture();

        // ===== Start IMGUI frame =====
        int left, top, width, height;
        mWindow->getViewport(0)->getActualDimensions(left, top, width, height); // output params
        Ogre::ImguiManager::getSingleton().newFrame(evt.timeSinceLastFrame, Ogre::Rect(left, top, width, height));

        // ===== Draw IMGUI  ====
        this->DrawGui();

        return true;
    }

    bool keyPressed( const OIS::KeyEvent &arg ) override
    {
        if (arg.key == OIS::KC_ESCAPE) // All extras we need
        {
            mShutDown = true;
        }

        Ogre::ImguiManager::getSingleton().keyPressed(arg);
        return true;
    }

    bool keyReleased(const OIS::KeyEvent &arg) override
    {
        Ogre::ImguiManager::getSingleton().keyReleased(arg);
        return true;
    }

    bool mouseMoved(const OIS::MouseEvent &arg) override
    {
        Ogre::ImguiManager::getSingleton().mouseMoved(arg);
        return true;
    }

    bool mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id) override
    {
        Ogre::ImguiManager::getSingleton().mousePressed(arg, id);
        return true;
    }

    bool mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id) override
    {
        Ogre::ImguiManager::getSingleton().mouseReleased(arg, id);
        return true;
    }

    // Adjust mouse clipping area
    virtual void windowResized(Ogre::RenderWindow* rw) override
    {
        unsigned int width, height, depth;
        int left, top;
        rw->getMetrics(width, height, depth, left, top);

        const OIS::MouseState &ms = mMouse->getMouseState();
        ms.width = width;
        ms.height = height;
    }

    virtual void windowClosed(Ogre::RenderWindow* rw) override
    {
        this->Shutdown(); // Unattach OIS before window shutdown (very important under Linux)
        mShutDown = true; // Stop application
    }

    void Shutdown()
    {
        if(mInputManager)
        {
            mInputManager->destroyInputObject(mMouse);
            mInputManager->destroyInputObject(mKeyboard);

            OIS::InputManager::destroyInputSystem(mInputManager);
            mInputManager = 0;
        }
        // Remove ourself as a Window listener
        Ogre::WindowEventUtilities::removeWindowEventListener(mWindow, this);
        delete mRoot;
        mRoot = nullptr;
    }

    Ogre::Root*                 mRoot    ;
    Ogre::Camera*               mCamera  ;
    Ogre::SceneManager*         mSceneMgr;
    Ogre::RenderWindow*         mWindow  ;

    bool                        mShutDown;

    //OIS Input devices
    OIS::InputManager*          mInputManager;
    OIS::Mouse*                 mMouse       ;
    OIS::Keyboard*              mKeyboard    ;

    GuiState                    m_gui_state;
};



int main(int argc, char *argv[])
{
    try
    {
        DemoApp demo_app;
        demo_app.Go();
    }
    catch(Ogre::Exception& e)
    {
        std::cerr << "An exception has occurred: " << e.getFullDescription().c_str() << std::endl;
    }

    return 0;
}

