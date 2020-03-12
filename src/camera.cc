#include "camera.h"
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtx/rotate_vector.hpp>
#define PI 3.14159265
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

// glm::mat4 Camera::rotate_camera(double rot){
// 	/*glm::vec3 x_vec = glm::normalize(glm::cross(up_, look_));
// 	glm::vec3 vec1 = glm::vec3(look_[0] * cos(rot), look_[1] * cos(rot), look_[2] * cos(rot));
// 	glm::vec3 vec2 = glm::cross(up_, look_);
// 	glm::vec3 vec3 = glm::vec3(vec2[0] * sin(rot), vec2[1] * sin(rot), vec2[2] * sin(rot));
// 	float dotp = glm::dot(up_, look_);
// 	float scalar = dotp * (1 - cos(rot));
// 	glm::vec3 vec4 = glm::vec3(up_[0] * scalar, up_[1] * scalar, up_[2] * scalar);
// 	look_ = vec1 + vec3 + vec4;*/
// 	glm::vec3 x_vec = glm::normalize(glm::cross(look_, up_));
// 	glm::vec3 vec1 = glm::vec3(up_[0] * cos(rot), up_[1] * cos(rot), up_[2] * cos(rot));
// 	glm::vec3 vec2 = glm::cross(look_, up_);
// 	glm::vec3 vec3 = glm::vec3(vec2[0] * sin(rot), vec2[1] * sin(rot), vec2[2] * sin(rot));
// 	float dotp = glm::dot(look_, up_);
// 	float scalar = dotp * (1 - cos(rot));
// 	glm::vec3 vec4 = glm::vec3(look_[0] * scalar, look_[1] * scalar, look_[2] * scalar);
// 	up_ = vec1 + vec3 + vec4;
// }

void Camera::switchMode(){
	if(fps){
		fps = false;
	}
	else{
		fps = true;
	}
}

void Camera::setMouse(bool m){
	mouse = m;
}

bool Camera::getMouse(){
	return mouse;
}

void Camera::mousePosition(double mousex, double mousey){
	curr_mousex = mousex;
	curr_mousey = mousey;
}

void Camera::zoom_camera(double mousey){
	eye_ = eye_ + look_ * (zoom_speed * (float)(curr_mousey - mousey));
	camera_distance_ = glm::length(center - eye_);
	curr_mousex = 0.0;
	curr_mousey = mousey;
}

void Camera::zoom_forward(){
	if(fps){
		eye_ = eye_ + (look_ * zoom_speed);
		center = center + (look_ * zoom_speed);
	}
	else{
		camera_distance_ = glm::length(center - eye_) - zoom_speed;
		eye_ = eye_ + (look_  * zoom_speed);
	}
}

void Camera::zoom_out(){
	if(fps){
		eye_ = eye_ - (look_ * zoom_speed);
		center = center - (look_ * zoom_speed);
	}
	else{
		camera_distance_ = glm::length(center - eye_) + zoom_speed;
		eye_ = eye_ - (look_  * zoom_speed);
	}
}

void Camera::roll_left(){
	up_ = glm::normalize(glm::rotate(up_, -roll_speed, look_));
	tan = glm::normalize(glm::cross(look_, up_));
}

void Camera::roll_right(){
	up_ = glm::normalize(glm::rotate(up_, roll_speed, look_));
	tan = glm::normalize(glm::cross(look_, up_));
}

void Camera::pan_up(){
	center = center + up_ * pan_speed;
	eye_ = eye_ + up_ * pan_speed;
}

void Camera::pan_down(){
	center = center - up_ * pan_speed;
	eye_ = eye_ - up_ * pan_speed;
}

void Camera::rotate_camera(double mousex, double mousey){
	double x = mousex - curr_mousex;
	double y = mousey - curr_mousey;
	curr_mousex = x;
	curr_mousey = y;
	if(fps){
		look_ = glm::rotate(look_, (float)x * rotation_speed, up_);
		tan = glm::normalize(glm::cross(look_, up_));
		look_ = glm::rotate(look_, (float)y * rotation_speed, tan); 
		up_ = glm::normalize(glm::cross(look_, -tan));
		center = look_ * camera_distance_ + eye_;
	}
	else{
		eye_ = glm::rotate(eye_, (float)x * rotation_speed, up_);
		look_ = center - eye_;
		tan = glm::normalize(glm::cross(look_, up_));
		eye_ = glm::rotate(eye_, (float)y * rotation_speed, tan);
		look_ = center - eye_;
		up_ = glm::normalize(glm::cross(look_, -tan));
	}
	look_ = glm::normalize(look_);
}