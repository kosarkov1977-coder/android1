#include <jni.h>
#include <string>
#include <vector>

struct Vertex {
    float x;
    float y;
    float z;
};

static std::vector<Vertex> buildStellatedDodecahedronApproximation() {
    constexpr float phi = 1.61803398875f;
    constexpr float scale = 0.5f;

    std::vector<Vertex> vertices = {
        {0, scale, scale * phi}, {0, -scale, scale * phi},
        {0, scale, -scale * phi}, {0, -scale, -scale * phi},
        {scale, scale * phi, 0}, {-scale, scale * phi, 0},
        {scale, -scale * phi, 0}, {-scale, -scale * phi, 0},
        {scale * phi, 0, scale}, {scale * phi, 0, -scale},
        {-scale * phi, 0, scale}, {-scale * phi, 0, -scale}
    };

    return vertices;
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_vulkangeometry_MainActivity_getGeometryDescription(JNIEnv* env, jobject) {
    const auto vertices = buildStellatedDodecahedronApproximation();

    std::string report = "Native Vulkan-ready mesh data\n";
    report += "Vertices: " + std::to_string(vertices.size()) + "\n";
    report += "Pipeline hint: use VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST";

    return env->NewStringUTF(report.c_str());
}
