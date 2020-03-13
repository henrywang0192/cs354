#ifndef MENGER_H
#define MENGER_H

#include <glm/glm.hpp>
#include <vector>

class Menger {
public:
	Menger();
	~Menger();
	void set_nesting_level(int);
	bool is_dirty() const;
	void set_clean();
	void generate_geometry(std::vector<glm::vec4>& obj_vertices,
			       std::vector<glm::vec4>& vtx_normals,
	                       std::vector<glm::uvec3>& obj_faces) const;

	void
	generate_box(std::vector<glm::vec4>& obj_vertices,
			  std::vector<glm::vec4>& vtx_normals,
                          std::vector<glm::uvec3>& obj_faces,
                          float x_lower, float x_higher,
                          float y_lower, float y_higher,
                          float z_lower, float z_higher, int start) const;	
	int
	generate_more_boxes(std::vector<glm::vec4>& obj_vertices,
			  std::vector<glm::vec4>& vtx_normals,
                          std::vector<glm::uvec3>& obj_faces,
                          float x_lower, float y_lower, float z_lower, float size, int level, int start) const;
private:
	int nesting_level_ = 0;
	bool dirty_ = false;
};

#endif
