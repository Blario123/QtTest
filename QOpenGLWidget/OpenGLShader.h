#ifndef OPENGLSHADER_H
#define OPENGLSHADER_H

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
public:
    uint ID;
    Shader(const char *vertPath, const char *fragPath, const char *geomPath = nullptr) {
        std::string vertCode, fragCode, geomCode;
        std::ifstream vShaderFile, fShaderFile, gShaderFile;

        vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        gShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

        try {
            vShaderFile.open(vertPath);
            fShaderFile.open(fragPath);
            std::stringstream vShaderStream, fShaderStream;
            vShaderStream << vShaderFile.rdbuf();
            fShaderStream << fShaderFile.rdbuf();

            vShaderFile.close();
            fShaderFile.close();

            vertCode = vShaderStream.str();
            fragCode = fShaderStream.str();

            if(geomPath != nullptr) {
                gShaderFile.open(geomPath);
                std::stringstream gShaderStream;
                gShaderStream << gShaderFile.rdbuf();
                gShaderFile.close();
                geomCode =  gShaderStream.str();
            }
        } catch(std::ifstream::failure &e) {
            std::cout << "Error -- Shader file not successfully read: " << e.what() << std::endl;
        }

        const char *vShaderCode = vertCode.c_str();
        const char *fShaderCode = fragCode.c_str();
        uint vertex, fragment;
        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vShaderCode, NULL);
        glCompileShader(vertex);
        checkCompileErrors(vertex, "Vertex");

        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fShaderCode, NULL);
        glCompileShader(fragment);
        checkCompileErrors(fragment, "Fragment");

        uint geometry;
        if(geomPath != nullptr) {
            const char *gShaderCode = geomCode.c_str();
            geometry = glCreateShader(GL_GEOMETRY_SHADER);
            glShaderSource(geometry, 1, &gShaderCode, NULL);
            glCompileShader(geometry);
            checkCompileErrors(geometry, "Geometry");
        }

        ID = glCreateProgram();

        glAttachShader(ID, vertex);
        glAttachShader(ID, fragment);
        if(geomPath != nullptr) {
            glAttachShader(ID, geometry);
        }
        glLinkProgram(ID);
        checkCompileErrors(ID, "Program");

        glDeleteShader(vertex);
        glDeleteShader(fragment);
        if(geomPath != nullptr) {
            glDeleteShader(geometry);
        }
    }
    void use() {
        glUseProgram(ID);
    }
    void setBool(const std::string &name, bool value) {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), (int) value);
    }
    void setInt(const std::string &name, int value) {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
    }
    void setFloat(const std::string &name, float value) {
        glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
    }
    void setVec2(const std::string &name, const glm::vec2 &value) {
        glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
    }
    void setVec2(const std::string &name, float x, float y) {
        glUniform2f(glGetUniformLocation(ID, name.c_str()), x, y);
    }
    void setVec3(const std::string &name, const glm::vec3 &value) {
        glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
    }
    void setVec3(const std::string &name, float x, float y, float z) {
        glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z);
    }
    void setVec4(const std::string &name, const glm::vec4 &value) {
        glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
    }
    void setVec4(const std::string &name, float x, float y, float z, float w) {
        glUniform4f(glGetUniformLocation(ID, name.c_str()), x, y, z, w);
    }
    void setMat2(const std::string &name, const glm::mat2 &value) {
        glUniformMatrix2fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &value[0][0]);
    }
    void setMat3(const std::string &name, const glm::mat3 &value) {
        glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &value[0][0]);
    }
    void setMat4(const std::string &name, const glm::mat4 &value) {
        glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &value[0][0]);
    }
    void checkCompileErrors(GLuint shader, std::string type) {
        GLint success;
        GLchar infoLog[1024];
        if(type != "Program") {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if(!success) {
                glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "Error -- " << type << " compilation error" << std::endl << infoLog << std::endl;
            }
        } else {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if(!success) {
                glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "Error -- " << type << " linking error" << std::endl << infoLog << std::endl;
            }
        }
    }
};

#endif //OPENGLSHADER_H
