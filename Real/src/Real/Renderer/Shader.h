#pragma once
#include <string>
#include <unordered_map>
#include "Resource.h"

struct ShaderStrings {
	std::string vertexShader;
	std::string fragmentShader;
};

class Shader : public Resource
{
private:
	unsigned int m_RendererID;
	std::string m_FilePath;
	
	unsigned int getUniformLocation(const std::string& name);
	
	ShaderStrings getStrings(const std::string& filepath);
	unsigned int compileShader(unsigned int type, const std::string& src);
	unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader);

	std::unordered_map<std::string, int> m_UniformLocationCache;
public:
	Shader(const std::string& filename);
	~Shader();

	void bind() const;
	void unbind() const;

	void setUniform4f(const std::string& name, float v0, float v1, float f2, float f3);
};
