/* scene_loader.cpp */

#include <iostream>

#include "scene_loader.h"

SceneLoader::SceneLoader() {
}

SceneLoader::~SceneLoader() {
//  if (this->root)
//    memdelete(this->root);
}

void SceneLoader::_bind_methods() {
    ClassDB::bind_method(D_METHOD("CreateSphere"), &SceneLoader::CreateSphere);
    ClassDB::bind_method(D_METHOD("CreateCamera"), &SceneLoader::CreateCamera);
    ClassDB::bind_method(D_METHOD("CreateLight"), &SceneLoader::CreateLight);
    ClassDB::bind_method(D_METHOD("Init"), &SceneLoader::Init);
}

void SceneLoader::Init() {
  this->root = memnew(Spatial);
  this->root->set_name("__ROOT__");
  this->root->set_visible(1);
  this->root->set_process(1);
  this->add_child(this->root);
  this->root->set_owner(this);
}

void SceneLoader::CreateCamera()
{
  if (!this->root)
  {
    std::cerr << "Unable to create camera. Scene not initialized." << std::endl;
    return;
  }
   Camera *camera = memnew(Camera);
   camera->set_name("camera");
   this->root->add_child(camera);
   camera->set_owner(this);
   camera->set_translation(Vector3(0, 0, 3));
   std::cerr << "created camera" << std::endl;
}

void SceneLoader::CreateLight()
{
  if (!this->root)
  {
    std::cerr << "Unable to create light. Scene not initialized." << std::endl;
    return;
  }
   DirectionalLight *light = memnew(DirectionalLight);
   light->set_name("light");
   this->root->add_child(light);
   light->set_owner(this);
   std::cerr << "created light" << std::endl;
}



void SceneLoader::CreateSphere()
{
  if (!this->root)
  {
    std::cerr << "Unable to create sphere. Scene not initialized." << std::endl;
    return;
  }

  MeshInstance *meshInstance = memnew(MeshInstance);
  SphereMesh  *sphereMesh = memnew(SphereMesh);
  meshInstance->set_mesh(sphereMesh);
  this->root->add_child(meshInstance);
  meshInstance->set_owner(this);
  std::cerr << "created sphere" << std::endl;
}


