using namespace std;

#include "Color.h"
#include "Scene.h"
#include "Object.h"
#include "Ray.h"
#include <vector>
#include <optional>
#include <random>

struct IntersectionData { // intersection data
    Object* object;
    glm::vec3 point;
    float distance;
};
class Renderer {
    public:
        Scene* scene;
        int width, height, samples, thread_count, recursion_depth;
        float light_loss, viewport_size, projection_plane_z;

        Renderer(Scene& scene, int width, int height, int samples, int thread_count=1, int recursion_depth=2, float light_loss=0.2, float viewport_size=1, float projection_plane_z=1);

        Color renderPixel(Ray oray);
        optional<IntersectionData> ClosestIntersection(Ray ray);
        Color bounceToColor(int b, Color sphere_color);
        glm::vec3 CanvasToViewport(glm::vec2 p2d);
        void SetScene(Scene& scene);
};