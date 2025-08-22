#pragma once
#include <GraceEngine/scene.h>

class SceneManager {
public:
    SceneManager() = default;
    ~SceneManager() = default;

    // Creation and deletion
    Scene* createScene(const char* sceneName);
    void deleteScene(const char* sceneName);

    // Loading and unloading existing scenes
    Scene* loadScene(const char* sceneName);
    void unloadScene(const char* sceneName);

private:
    uint8_t m_numberOfActiveScenes = 0;
    uint8_t m_maxNumberOfActiveScenes = 1;

    Scene* m_activeScene = nullptr;
};

