#ifndef MESH_BUILDER_SCENE_H_
#define MESH_BUILDER_SCENE_H_

#include <memory>
#include <vector>

#include <tango_client_api.h>  // NOLINT
#include <tango-gl/gesture_camera.h>
#include <tango-gl/grid.h>
#include <tango-gl/tango-gl.h>
#include <tango-gl/util.h>
#include <tango_3d_reconstruction_api.h>
#include "model_io.h"

namespace mesh_builder {

class Scene {
 public:
  Scene();
  ~Scene();
  void InitGLContent();
  void DeleteResources();
  void SetupViewPort(int w, int h);
  void Render(bool frustum);
  void UpdateFrustum(glm::vec3 pos, float zoom);
  void AddDynamicMesh(SingleDynamicMesh* mesh);
  void ClearDynamicMeshes();

  tango_gl::Camera* camera_;
  tango_gl::StaticMesh frustum_;
  std::vector<unsigned int> textureMap;
  std::vector<tango_gl::StaticMesh> static_meshes_;
  std::vector<tango_gl::StaticMesh> debug_meshes_;
  std::vector<SingleDynamicMesh*> dynamic_meshes_;
  tango_gl::Material* color_vertex_shader;
  tango_gl::Material* textured_shader;
};
}  // namespace mesh_builder

#endif  // MESH_BUILDER_SCENE_H_
