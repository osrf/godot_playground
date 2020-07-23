#ifndef SCENE_LOADER_H
#define SCENE_LOADER_H

#include "scene/main/node.h"
#include "scene/3d/camera.h"
#include "scene/3d/light.h"
#include "scene/3d/spatial.h"
#include "scene/3d/mesh_instance.h"
#include "scene/resources/primitive_meshes.h"
#include "modules/csg/csg_shape.h"

class SceneLoader : public Spatial {
    GDCLASS(SceneLoader, Spatial);

    Spatial *root = nullptr;

protected:
    static void _bind_methods();

public:
    SceneLoader();
    ~SceneLoader();

    void Init();
    void CreateCamera();
    void CreateLight();
    void CreateSphere();
};

#endif // SCENE_LOADER_H
