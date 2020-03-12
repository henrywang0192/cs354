#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
	glm::mat4 get_view_matrix() const;
	glm::mat4 translate_camera(glm::vec3 trans);
	void zoom_forward();
	void zoom_out();
	void mousePosition();
	void zoom_camera(double mousey);
	void switchMode();
	void setMouse(bool m);
	bool getMouse();
	void roll_left();
	void roll_right();
	void pan_up();
	void pan_down();
	void rotate_camera(double mousex, double mousey);
	void mousePosition(double mousex, double mousey);
	// FIXME: add functions to manipulate camera objects.
private:
	float camera_distance_ = 3.0;
	glm::vec3 look_ = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 up_ = glm::vec3(0.0f, 1.0, 0.0f);
	glm::vec3 eye_ = glm::vec3(0.0f, 0.0f, camera_distance_);
	bool mouse = false;
	bool fps = false;
	double curr_mousex;
	double curr_mousey;
	glm::vec3 center = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 tan = glm::normalize(glm::cross(look_, up_));
	// Note: you may need additional member variables
};

#endif
