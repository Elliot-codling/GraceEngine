#include <GraceEngine/sceneManager.h>

Scene* SceneManager::createScene(const char* sceneName) {
    m_activeScene = new Scene();
    m_activeScene->defineName(sceneName);
    // EXPERIMENTAL
    // TODO: Must get the vector size based on engine properties configurable by the user
    m_activeScene->defineVectorSize(500);
    return m_activeScene;
}

void SceneManager::deleteScene(const char* sceneName) {

}

Scene* SceneManager::loadScene(const char* sceneName) {
}

void SceneManager::unloadScene(const char* sceneName) {
}
