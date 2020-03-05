#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
	glm::mat4 get_view_matrix() const;
	glm::mat4 translate_camera(glm::vec3 trans);
	// FIXME: add functions to manipulate camera objects.
private:
	float camera_distance_ = 3.0;
	glm::vec3 look_ = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 up_ = glm::vec3(0.0f, 1.0, 0.0f);
	glm::vec3 eye_ = glm::vec3(0.0f, 0.0f, camera_distance_);
	bool mouse = true;
	glm::vec3 center = glm::vec3(0.0f, 0.0f, 0.0f);
	// Note: you may need additional member variables
};

#endif
