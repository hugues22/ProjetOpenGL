#include "Renderer.h"

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Cube.h"


void GLClearError() {
	while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line) {
	while (GLenum error = glGetError()) {
		printf("OpenGL Error ( %d ) : %s, %s, %d", error, function, file, line);
		return false;
	}
	return true;
}

Renderer::Renderer(GLFWwindow & window, int w, int h)
	: m_Camera(new Camera(window, w, h))
{
}

void Renderer::Clear() const
{
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, Shader& shader)
{
	m_Camera->ComputeMatricesFromInputs();
	m_Camera->ComputeMVP();
	
	glm::mat4 mvp = m_Camera->GetMVP();

	shader.Bind();
	shader.SetUniformMat4f("u_MVP", mvp);

	va.Bind();
	ib.Bind();

	GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));

}

void Renderer::Draw(Cube cube)
{
	m_Camera->ComputeMatricesFromInputs();
	m_Camera->ComputeMVP();

	glm::mat4 mvp = m_Camera->GetMVP();
	
	
	cube.Bind();
	cube.SetShaderUniformMat4f("u_MVP", mvp);

	GLCall(glDrawElements(GL_TRIANGLES, cube.GetIndexBuffer().GetCount(), GL_UNSIGNED_INT, nullptr));
	
	cube.Unbind();
}