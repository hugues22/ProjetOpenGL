#pragma once

#include <string>
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Texture.h"

class Cube
{

private : 

	float * m_Positions;
	unsigned int * m_Indices;

	//VertexArray m_Va;
	VertexArray * m_Va;
	VertexBuffer * m_Vb;
	VertexBufferLayout m_Layout;
	IndexBuffer * m_Ib;

	Shader * m_Shader;
	Texture m_Texture;
	
	glm::vec4 m_Translation;

public: 
	
	Cube(float * positions, unsigned int * indices, std::string shaderPath);
	
	//void initTexture(const std::string name, unsigned int id);
	void Bind();
	void Unbind();

	//SETTER
	void SetShader(const std::string path);
	void SetTexture(const std::string path);
	void SetShaderUniformMat4f(const std::string name, glm::mat4 mvp);

	void translate(glm::vec3 v);


	// GETTERS
	inline VertexArray & GetVertexArray() const { return *m_Va; }
	inline IndexBuffer & GetIndexBuffer() const { return *m_Ib; }
	inline Shader & GetShader() { return *m_Shader; }
};