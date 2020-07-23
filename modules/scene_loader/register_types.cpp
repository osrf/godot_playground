/* register_types.cpp */

#include "register_types.h"

#include "core/class_db.h"
#include "scene_loader.h"

void register_scene_loader_types() {
    ClassDB::register_class<SceneLoader>();
}

void unregister_scene_loader_types() {
   // Nothing to do here in this example.
}
