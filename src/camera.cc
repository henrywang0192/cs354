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

	glm::vec3 x = glm::normalize(glm::cross(up_, look_));
    glm::mat4 view_matrix = {
        x[0], up_[0], look_[0], 0,
        x[1], up_[1], look_[1], 0,
        x[2], up_[2], look_[2], 0,
        -glm::dot(x, eye_), -glm::dot(up_, eye_), -glm::dot(look_, eye_), 1
    };
    return view_matrix;
}

glm::mat4 Camera::translate_camera(glm::vec3 trans){
	glm::vec3 look_vec = glm::normalize(glm::cross(up_, look_));
	eye_ += (look_vec * pan_speed) * trans[0];
	if (!(trans[1] == 0))
		eye_ += (up_ * pan_speed) * trans[1];
	if (!(trans[2] == 0))
		eye_[2] += pan_speed * trans[2];
}

