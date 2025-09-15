#include "Shader.h"
#include "Renderer.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>



Shader::Shader(const std::string& filepath) 
	: m_FilePath(filepath), m_RendererID(0)
{
	ShaderStrings strings = getStrings(filepath);
	m_RendererID = createShader(strings.vertexShader, strings.fragmentShader);

}


Shader::~Shader() 
{
	GLCall(glDeleteProgram(m_RendererID));
}


unsigned int Shader::createShader(const std::string& vertexString, const std::string& fragmentString) {
	unsigned int program = glCreateProgram();
	unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexString);
	unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentString);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);
	glDeleteShader(vs);
	glDeleteShader(fs);
	
	return program;
}

ShaderStrings Shader::getStrings(const std::string& filepath) {
	std::ifstream stream(filepath);
	
	enum class ShaderType {
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};
	
	std::string line;
	std::stringstream ss[2];	
	ShaderType type = ShaderType::NONE;
	
	ShaderStrings result;

	while(getline(stream, line)) {
		if(line.find("#shader") != std::string::npos) {
			if(line.find("vertex") 	!= std::string::npos) {
				//SET MODE TO VERTEX
				type = ShaderType::VERTEX;
			}
 			else if(line.find("fragment") != std::string::npos) {
				//SET MODE TO FRAGMENT
				type = ShaderType::FRAGMENT;
			}
			else {
				ss[(int)type] << line;
			}
		}
		else {
			ss[(int)type] << line << "\n";
		}	
	}

	result.vertexShader = ss[(int)ShaderType::VERTEX].str();
	result.fragmentShader = ss[(int)ShaderType::FRAGMENT].str();
	return result;
}



unsigned int Shader::compileShader(unsigned int type, const std::string& source) 
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	
	glShaderSource(id, 1, &src, nullptr); 
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if(result != GL_TRUE) {
		int StringLength;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &StringLength);
		char* message = (char*)alloca(StringLength* sizeof(char));                                                   	
                glGetShaderInfoLog(id, StringLength, &StringLength, message);
                std::cout << "Failed to Compile" << (type == GL_VERTEX_SHADER ? "Vertex Shader!" : "Fragment Shader!") << std::endl;
                std::cout << message << std::endl;
                glDeleteShader(id);
                return 0;	
	}
	return id;
}


void Shader::bind() const
{
	GLCall(glUseProgram(m_RendererID));
}

void Shader::unbind() const
{
	GLCall(glUseProgram(0));
}

void Shader::setUniform4f(const std::string& name, float v0, float v1, float v2, float v3) 
{
	int location = getUniformLocation(name);
	glUniform4f(location, v0, v1, v2, v3);
}

unsigned int Shader::getUniformLocation(const std::string& name)
{
	if(m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
		return m_UniformLocationCache[name];

	GLCall(int location = glGetUniformLocation(m_RendererID, name.c_str()));
	if(location == -1) {
		std::cout << "Warning: uniform"  << name << "doesn't exist!" << std::endl;
	}

	m_UniformLocationCache[name] = location;
	return location;
}

