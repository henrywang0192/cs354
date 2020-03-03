#include "camera.h"

namespace {
	float pan_speed = 0.1f;
	float roll_speed = 0.1f;
	float rotation_speed = 0.05f;
	float zoom_speed = 0.1f;
};

// FIXME: Calculate the view matrix
glm::mat4 Camera::get_view_matrix() const
{
	return glm::mat4(1.0);
}

glm::mat4 Camera::translate_camera(glm::vec3 trans){
	return glm::translate(get_view_matrix(), trans);
}
