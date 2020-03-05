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
	glm::mat4 matrix;
	glm::vec3 y = up_;
	glm::vec3 z = glm::normalize(eye_ - center);
	glm::vec3 x = glm::cross(y, z);
	matrix[0][0] = x[0];
	matrix[1][0] = x[1];
	matrix[2][0] = x[2];
	matrix[3][0] = -glm::dot(x, eye_);
	matrix[0][1] = y[0];
	matrix[1][1] = y[1];
	matrix[2][1] = y[2];
	matrix[3][1] = -glm::dot(y, eye_);
	matrix[0][2] = z[0];
	matrix[1][2] = z[1];
	matrix[2][2] = z[2];
	matrix[3][2] = -glm::dot(z, eye_);
	matrix[0][3] = 0;
	matrix[1][3] = 0;
	matrix[2][3] = 0;
	matrix[3][3] = 1;
	return matrix;
}

glm::mat4 Camera::translate_camera(glm::vec3 trans){
	return glm::translate(get_view_matrix(), trans);
}

