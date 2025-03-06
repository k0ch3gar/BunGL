#ifndef IUNIFORM_H
#define IUNIFORM_H

class ShaderProgram;

class IUniform {
public:
    virtual ~IUniform() = default;

    virtual void Uniform(int uniformPos) = 0;
};

#endif //IUNIFORM_H
