#include "menger.h"

namespace {
	const int kMinLevel = 0;
	const int kMaxLevel = 4;
};

Menger::Menger()
{
	// Add additional initialization if you like
}

Menger::~Menger()
{
}

void
Menger::set_nesting_level(int level)
{
	nesting_level_ = level;
	dirty_ = true;
}

bool
Menger::is_dirty() const
{
	return dirty_;
}

void
Menger::set_clean()
{
	dirty_ = false;
}

// FIXME generate Menger sponge geometry
void
Menger::generate_geometry(std::vector<glm::vec4>& obj_vertices,
			  std::vector<glm::vec4>& vtx_normals,
                          std::vector<glm::uvec3>& obj_faces) const
{
    obj_vertices.clear();
    vtx_normals.clear();
    obj_faces.clear();
    if(nesting_level_ == 0)
    {
        generate_box(obj_vertices, vtx_normals, obj_faces, -0.5f, 0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0);
    }
    else
    {
        generate_more_boxes(obj_vertices, vtx_normals, obj_faces, -0.5f, -0.5f, -0.5f, 0.333f, nesting_level_, 0);
    }
	obj_vertices.push_back(glm::vec4(-0.5f, -0.5f, -0.5f, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_vertices.push_back(glm::vec4(0.5f, -0.5f, -0.5f, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_vertices.push_back(glm::vec4(0.0f, 0.5f, -0.5f, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_faces.push_back(glm::uvec3(0, 1, 2));
}

void
Menger::generate_box(std::vector<glm::vec4>& obj_vertices,
			  std::vector<glm::vec4>& vtx_normals,
                          std::vector<glm::uvec3>& obj_faces,
                          float x_lower, float x_higher,
                          float y_lower, float y_higher,
                          float z_lower, float z_higher, int start) const
{
	obj_vertices.push_back(glm::vec4(x_lower, y_lower, z_higher, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_vertices.push_back(glm::vec4(x_higher, y_higher, z_higher, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_vertices.push_back(glm::vec4(x_lower, y_higher, z_higher, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_faces.push_back(glm::uvec3(start, start + 1, start + 2));
	
    	obj_vertices.push_back(glm::vec4(x_lower, y_lower, z_higher, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_vertices.push_back(glm::vec4(x_higher, y_lower, z_higher, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_vertices.push_back(glm::vec4(x_higher, y_higher, z_higher, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_faces.push_back(glm::uvec3(start + 3, start + 4, start + 5));
	
	obj_vertices.push_back(glm::vec4(x_higher, y_higher, z_higher, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_vertices.push_back(glm::vec4(x_higher, y_lower, z_lower, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_vertices.push_back(glm::vec4(x_higher, y_higher, z_lower, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_faces.push_back(glm::uvec3(start + 6, start + 7, start + 8));
	
	obj_vertices.push_back(glm::vec4(x_higher, y_lower, z_higher, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_vertices.push_back(glm::vec4(x_higher, y_lower, z_lower, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_vertices.push_back(glm::vec4(x_higher, y_higher, z_higher, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_faces.push_back(glm::uvec3(start + 9, start + 10, start + 11));

	obj_vertices.push_back(glm::vec4(x_lower, y_lower, z_lower, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_vertices.push_back(glm::vec4(x_higher, y_higher, z_lower, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_vertices.push_back(glm::vec4(x_lower, y_higher, z_lower, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_faces.push_back(glm::uvec3(start + 12, start + 13, start + 14));
	
	obj_vertices.push_back(glm::vec4(x_lower, y_lower, z_lower, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_vertices.push_back(glm::vec4(x_higher, y_lower, z_lower, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_vertices.push_back(glm::vec4(x_higher, y_higher, z_lower, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_faces.push_back(glm::uvec3(start + 15, start + 16, start + 17));
	
	obj_vertices.push_back(glm::vec4(x_lower, y_higher, z_higher, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_vertices.push_back(glm::vec4(x_lower, y_lower, z_lower, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_vertices.push_back(glm::vec4(x_lower, y_higher, z_lower, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_faces.push_back(glm::uvec3(start + 18, start + 19, start + 20));

	obj_vertices.push_back(glm::vec4(x_lower, y_lower, z_higher, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_vertices.push_back(glm::vec4(x_lower, y_lower, z_lower, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_vertices.push_back(glm::vec4(x_lower, y_higher, z_higher, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_faces.push_back(glm::uvec3(start + 21, start + 22, start + 23));
	
	obj_vertices.push_back(glm::vec4(x_lower, y_higher, z_higher, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_vertices.push_back(glm::vec4(x_lower, y_higher, z_lower, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_vertices.push_back(glm::vec4(x_higher, y_higher, z_lower, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_faces.push_back(glm::uvec3(start + 24, start + 25, start + 26));
	
	obj_vertices.push_back(glm::vec4(x_lower, y_higher, z_higher, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_vertices.push_back(glm::vec4(x_higher, y_higher, z_higher, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_vertices.push_back(glm::vec4(x_higher, y_higher, z_lower, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_faces.push_back(glm::uvec3(start + 27, start + 28, start + 29));

    	obj_vertices.push_back(glm::vec4(x_lower, y_lower, z_higher, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_vertices.push_back(glm::vec4(x_lower, y_lower, z_lower, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_vertices.push_back(glm::vec4(x_higher, y_lower, z_lower, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_faces.push_back(glm::uvec3(start + 30, start + 31, start + 32));

    	obj_vertices.push_back(glm::vec4(x_lower, y_lower, z_higher, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_vertices.push_back(glm::vec4(x_higher, y_lower, z_higher, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_vertices.push_back(glm::vec4(x_higher, y_lower, z_lower, 1.0f));
	vtx_normals.push_back(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));
	obj_faces.push_back(glm::uvec3(start + 33, start + 34, start + 35));
}

int
Menger::generate_more_boxes(std::vector<glm::vec4>& obj_vertices,
			  std::vector<glm::vec4>& vtx_normals,
                          std::vector<glm::uvec3>& obj_faces,
                          float x_lower, float y_lower, float z_lower, float size, int level, int start) const 
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                if(((i == 1) && (j == 1)) || ((i == 1) && (k == 1)) || ((j == 1) && (k == 1)))
                {
                    float x_start = x_lower + (float)i * size;
                    float y_start = y_lower + (float)j * size;
                    float z_start = z_lower + (float)k * size;
                    if(level > 1)
                    {
                        return generate_more_boxes(obj_vertices, vtx_normals, obj_faces, x_start, y_start, z_start, size / 3.0f, level - 1, start);
                    }
                    generate_box(obj_vertices, vtx_normals, obj_faces, x_start, y_start, z_start, x_start + size, y_start + size, z_start + size, start);
                    return start + 36;
                }
            }
        }
    }
}
