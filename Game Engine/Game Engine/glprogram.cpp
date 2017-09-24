#include "glprogram.h"


GLProgram::GLProgram()
	: oProgramId(0)
{
	
}

GLProgram::~GLProgram()
{
	//for each (Shader var in oShaders)
	//	if (var.path != nullptr)
	//		delete[] var.path;
}

void GLProgram::addShader(SHADER type, const char * path)
{
	oShaders.emplace_back(type, 0, path);
}

void GLProgram::begin()
{
	if(oProgramId == 0)
		oProgramId = glCreateProgram();
}

void GLProgram::end()
{
	for each (Shader var in oShaders)
	{
		switch (var.type)
		{
		case SHADER::VERTEX:   var.id = glCreateShader(GL_VERTEX_SHADER);   break;
		case SHADER::GEOMETRY: var.id = glCreateShader(GL_GEOMETRY_SHADER); break;
		case SHADER::FRAGMENT: var.id = glCreateShader(GL_FRAGMENT_SHADER); break;
		}

		const GLchar *src[1];
		GLint lng[1];
		src[0] = utils::file::load_file(var.path);

		if(src[0] == nullptr)
			Logger::FatalError("Failed to create vertex shader");

		lng[0] = strlen(src[0]);
		glShaderSource(var.id, 1, src, lng);

		glCompileShader(var.id);
		if (var.id == 0)
			Logger::FatalError("Failed to create vertex shader");

		//check to compile success
		GLint success = 0;
		glGetShaderiv(var.id, GL_COMPILE_STATUS, &success);
		if (success == GL_FALSE)
		{
			GLint length = 0;
			glGetShaderiv(var.id, GL_INFO_LOG_LENGTH, &length);

			std::vector<char> errors(length);
			glGetShaderInfoLog(var.id, length, &length, &errors[0]);

			glDeleteShader(var.id);

			Logger::Log(std::string(var.path), LogType::ERR);
			std::printf("%s", &errors[0]);
			Logger::FatalError("Shader compile failed!");
		}

		(src[0] != nullptr) ? delete[] src[0] : src[0] = src[0];
		glAttachShader(oProgramId, var.id);
	}

	glLinkProgram(oProgramId);

	//success checked
	GLint isLinked = 0;
	glGetProgramiv(oProgramId, GL_LINK_STATUS, (int *)&isLinked);
	if (isLinked == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(oProgramId, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<char> infoLog(maxLength);
		glGetProgramInfoLog(oProgramId, maxLength, &maxLength, &infoLog[0]);

		for each (Shader var in oShaders)
			glDeleteShader(var.id);
		glDeleteProgram(oProgramId);

		std::printf("%s", &infoLog[0]);
		Logger::FatalError("Shader link failed");
	}

	glValidateProgram(oProgramId);

	//Always detach shaders after a successful link.
	for each (Shader var in oShaders)
	{
		glDetachShader(oProgramId, var.id);
		glDeleteShader(var.id);
	}
}

void GLProgram::bind()
{
	glUseProgram(oProgramId);
}

void GLProgram::unbind()
{
	glUseProgram(0);
}

GLuint GLProgram::getUniform(const char * name)
{
	GLuint id = glGetUniformLocation(oProgramId, name);
	if (id == GL_INVALID_INDEX)
		Logger::FatalError("Can not find uniform variable " + std::string(name));
	return id;
}
