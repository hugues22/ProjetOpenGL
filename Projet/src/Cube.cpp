#include "Cube.h"


Cube::Cube(float * positions, unsigned int * indices, std::string shaderPath)
	: m_Positions(positions), m_Indices(indices),
	  m_Translation(glm::vec4(1.0f))/*, 
	  //m_Vb(VertexBuffer(positions, 3 * 8 * sizeof(float))), 
	  //m_Ib(IndexBuffer(indices, 3 * 12)), 
	  m_Shader(Shader(shaderPath))*/
{

	m_Layout.Push<float>(3);
	//layout.Push<float>(2);

	m_Va = new VertexArray();
	m_Vb = new VertexBuffer(positions, 3 * 8 * sizeof(float));
	m_Shader = new Shader(shaderPath);

	m_Va->AddBuffer(*m_Vb, m_Layout);

	m_Ib = new IndexBuffer(indices, 3 * 12);

	/*m_Va->Unbind();
	m_Vb.Unbind();
	m_Ib->Unbind();
	m_Shader.Unbind();*/
}

void Cube::Bind()
{
	m_Va->Bind();
	m_Vb->Bind();
	m_Ib->Bind();
	m_Shader->Bind();
}

void Cube::Unbind()
{
	m_Va->Unbind();
	m_Vb->Unbind();
	m_Ib->Unbind();
	m_Shader->Unbind();
}

void Cube::SetShader(const std::string path)
{
	m_Shader = new Shader(path);
	m_Shader->Unbind();
}

void Cube::SetTexture(const std::string path)
{
	Texture texture(path);
}

void Cube::SetShaderUniformMat4f(const std::string name, glm::mat4 mvp)
{
	//mvp = mvp * m_Translation;
	m_Shader->SetUniformMat4f(name, mvp);
}

void Cube::translate(glm::vec3 v)
{
	//m_Positions = glm::translate(m_Positions, v)
}

/*void Cube::initTexture(const std::string name, unsigned int id)
{
	m_Shader.Bind();
	m_Texture.Bind(id);
	m_Shader.setUniform1i(name, id);
	m_Texture.Unbind();
	m_Shader.Unbind();
}*/